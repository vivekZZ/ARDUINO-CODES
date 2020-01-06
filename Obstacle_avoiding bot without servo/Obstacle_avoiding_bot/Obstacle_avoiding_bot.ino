/*
    
     by vivek katore,https://www.linkedin.com/in/vivek-katore/
*/
#include <AFMotor.h>

AF_DCMotor motor1(1);

AF_DCMotor motor2(2); 
 AF_DCMotor motor3(3);
 AF_DCMotor motor4(4);

// defines pins numbers
const int trigPin = A0;
const int echoPin = A1;

// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

if(distance <35)
  {
 digitalWrite(13,HIGH);
 motor1.setSpeed(0);
   motor4.setSpeed(0);//Define maximum velocity
  motor1.run(RELEASE);
 motor4.run(RELEASE);//rotate the motor clockwise
  motor2.setSpeed(0);
  motor3.setSpeed(0);//Define maximum velocity
  motor3.run(RELEASE);
  motor2.run(RELEASE); //rotate the motor clockwise
  delay(1000);
   motor1.setSpeed(255);
   motor4.setSpeed(255);//Define maximum velocity
  motor1.run(BACKWARD);
 motor4.run(BACKWARD);//rotate the motor clockwise
  motor2.setSpeed(255);
  motor3.setSpeed(255);//Define maximum velocity
  motor3.run(BACKWARD);
  motor2.run(BACKWARD); //rotate the motor clockwise
  delay(500);
   motor2.setSpeed(0);
  motor3.setSpeed(0);//Define maximum velocity
  motor3.run(RELEASE);
  motor2.run(RELEASE); //rotate the motor clockwise
  motor1.setSpeed(255);
   motor4.setSpeed(255);//Define maximum velocity
  motor1.run(FORWARD);
 motor4.run(FORWARD);//rotate the motor clockwise
 delay(1000);
  }
  if(distance >36)
  {
   
  motor1.setSpeed(255);
   motor4.setSpeed(255);//Define maximum velocity
  motor1.run(FORWARD);
  motor4.run(FORWARD);//rotate the motor clockwise
  motor2.setSpeed(255);
  motor3.setSpeed(255);//Define maximum velocity
  motor3.run(FORWARD);
  motor2.run(FORWARD); //rotate the motor clockwise
  
  }
}
