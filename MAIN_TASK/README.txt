The main task for SRM-AUV recruitment

A PID controller

Made on an ArduinoUNO IDE.

Depth sensor used : Blue Robotics "MS5837"
Thruster used 	  : Blue Robotics "T100" attached to ~PWM '10' pin

The PID_question folder contains a folder named MS5837 , this is the library used by the MS5837 presure sensor to measure depth , place the folder in libraries on your linux device before running the code.

T100 requires no external libraries.

Before using the code edit the setup() for setting the values of 'Kp','Ki','Kd' and the "setPoint"

Notes:

> The T100 thruster works in the range of PWM values of 1100 to 1900
provided to it as servo.writeMicroseconds() function of servo class

> The servo is stopped by providing value of 1500

> The integral function has been designed to activate only after error has reduced to 20 and can reach only a custom value of 50/Ki value , both of which can be reset.

> There is an extra snippet of code named testThruster() , it is designed according to the task PDF statement , it takes values : -255 to 0 to 255 for minimum , zero and maximum speeds respectively.

> A variable k has been used to switch thruster direction. 

HAVE FUN!
