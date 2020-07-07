#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

// ---------------------------------------------------------
// for the sensor
int distance = 0;
int boxHight = 0;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()
{
  // measure the ping time in cm
  distance = 0.01723*readUltrasonicDistance(7, 7); // distance from the sensor to the top of the box
  boxHight = 100 - distance; // 100 is the distance from sensor to the ground in cm
  // distance = 100 mean there is no box , distance = 90 mean the box size is 10*10*10 ...
  
  Serial.print("boxHight: "); 
  Serial.println(boxHight); // to see the values
  
  if ( boxHight>5 && boxHight<15 ) // 5 cm error
  { myservo.write(0); }
  if ( boxHight>15 && boxHight<25 ) // 5 cm error
  {  myservo.write(90); } 
  if ( boxHight>25 && boxHight<35 ) // 5 cm error
  {  myservo.write(180); }

  delay(100); // Wait for 100 millisecond(s)
}
