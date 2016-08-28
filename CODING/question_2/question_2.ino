long echo = 0; // stores the recieved echo 
int USpin = 9; // pin on which the Ultra sonic sensor is connected
double USvalue = 0; // stores the ultra sonic signal value
double data[64]; // data array for storage of the recieved data
int t = 0; // counter to store array position

void setup()
{
  Serial.begin(9600); // serial data rate in bits per second
  pinMode(USpin, OUTPUT); // set ultra sonic pin to output (initially)
}

void loop() // the logic here
{
  if (t == 64)
  {
    t = 0;
  }
  data[t] = distance(); // distance is a random number generator , use ultrasonic signal using USsensor() instead of distance()
  t++;
  delay(100);    // delay of 0.1 seconds
  /*
   * Serial.write("At");
    Serial.print(t);
    Serial.write(" value ");
    Serial.println(data[t - 1]);
    
    //Can be used to test the code
  */
}

double distance() //generates psuedo random numbers and converts them to decimal value
{ double k=0;
  k= random(1, 10000) / 1000.0; // double number generated
  /*Serial.println("sent ");
  Serial.write(" value ");
  Serial.print(t);
  Serial.write(" is ++> ");
  Serial.println(k);
  //Can be used for testing
  */
  return k;
}

double USsensor() // ultrasonic sensor attached to pin USpin 
{
  pinMode(USpin, OUTPUT);

  digitalWrite(USpin, LOW);

  delayMicroseconds(2);

  digitalWrite(USpin, HIGH);

  delayMicroseconds(5);

  digitalWrite(USpin, LOW);

  pinMode(USpin, INPUT);

  digitalWrite(USpin, HIGH);

  echo = pulseIn(USpin, HIGH); // listen to the echo

  USvalue = (echo / 58.138); // change the value of echo to cm

  return USvalue;
}
