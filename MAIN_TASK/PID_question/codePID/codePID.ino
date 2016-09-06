
/*
  Read the README file before using the program
  Sensor Loop and Thruster details in README
*/
#include <Wire.h>
#include "MS5837.h"
#include <Servo.h>
MS5837  sensor;                 // The depth sensor
double  Kp = 0, Ki = 0, Kd = 0; // the constansts for P,I and D
double  setPoint = 0;           // the required value of the Depth
double  prevError = 0;          //stores prevoius error value
double  error = 0;              // the Error occoured
double  P_val = 0;              // current Propotional value
double  I_val = 0;              // current Integral value
double  D_val = 0;              // current Derivative Value
double  Current_val = 0;        // current Sensor Value
double  Time = 0;               // Time taken by function to run
double  PID_val = 0;            // sum of P,I,D value
Servo   servo;                  // T100 servo
byte    servoPin = 10;          // attach servo to PWM pin 10
double  Max_val=setPoint;       // Maximum PID value
double  Min_val=-1*setPoint;    // Minimum PID value
unsigned long time=0;           // to store time
unsigned long prevTime=0;	// to store previous time	

void setup()                    // Initial Setting for values
{
  Serial.begin(9600);
  Kp = 1;                       // Multiplication Constants
  Ki = 0.6;
  Kd = 0.32;
  setPoint = 200;                     // Required value
  Time = 1;                           // initial time set to 1 millisecond
  Wire.begin();                       // starting sensor
  sensor.init();
  sensor.setFluidDensity(997);        // kg/m^3 (997 for fresh water)
  servo.attach(servoPin);             // attached T100 thruster here
  servo.writeMicroseconds(1500);      // 1500 to stop
  delay(1000);                        // Waiting for the thruster to stop
}

void loop() {                         // PID implementation here
  Current_val = sensor_val();         // Recieve value form the sensor
  error = setPoint - Current_val;     // Change error value
  
  time =millis();
  P_val = Kp * (error);               // P calculated here
	  
  if (error < 20 && error > -20)      // I calculated only if absolute error is less than 20 (can be altered)
  {
    I_val = I_val + Ki * (error);
  }
  if (I_val > (50 / Ki))              // Can be altered not necessary
  {
    I_val = (50 / Ki);                // Mainitaining I under a specific point (As I increases very fast)

  }
  D_val = Kd * (error - prevError)/((time-prevTime)/1000);   // D calculated here

  PID_val = P_val + I_val + D_val;    // P I D calculated here

  if (error > 0) {                    // Data sent to thruster function , normal case

    if (PID_val > Max_val) {          // If PID_val over shoots more than the Max_val value

      thruster(Max_val, 1);
    }
    else
    {
      thruster(PID_val, 1);
    }
  }
  else if (error < 0 ) {                  // Overshooting case
    if (PID_val < Min_val) {              // If PID_val under shoots less than the Min_val value
      thruster(Min_val, 0);
    }
    else
    {
      thruster(PID_val, 0);
    }
  }
  else {                                  // If the error is = 0 
                                          // Reset value of I and D when position is reached
    I_val = 0;
    D_val = 0;
    servo.writeMicroseconds(1500);        // Stop the thrusters when error is 0;

/* use this command on servo with testThruster() function
 *  servo.write(0);
 */
    delay(1000);
  }
  prevError = error;                      // set new value to prevError
  prevTime  = time;   			  // set old value of time to previous time	
}

double sensor_val() {
  //sensor code here
  return (double)(sensor.depth());        // return depth in meters
}

void thruster(double PID, int k) {        // using BLUE ROBOTICS® T100 thruster
  //thruster code here
  if (k == 1) {                           // k=1 handles positive error
    
    servo.writeMicroseconds((1500+((1900-1500)/setPoint)*PID));       // averaging values
  }
  if(k == 0){                             // k=0 handles negative error
    servo.writeMicroseconds((1100+(abs(((1100-1500)/setPoint)*PID))));  // averaging values ,abs() function to avoid negative values
  }
  delay(100);                             // 0.1 seconds delay for motor to adjust
}

void testThruster(double PID, int k){     // thruster according to the TASK PDF 
 if (k == 1) {                            // k=1 handles positive error
    
    servo.write((int)((255/setPoint)*PID));
  }
  if(k == 0){                             // k=0 handles negative error
    servo.write((int)(abs(((-255/setPoint)*PID))));
  }
   
}
