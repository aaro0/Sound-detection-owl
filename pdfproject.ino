#include <Servo.h>

const int turnDegrees = 10;
int servoPin = A0;
const int rightSensorPin = A1;
const int leftSensorPin = A2;
int rightVal = 0;
int leftVal = 0;
int state = 90;
int difference = 50;

Servo servo;

void setup(){
  pinMode(leftSensorPin, INPUT); //Make pin 8 an input pin.
  pinMode(rightSensorPin, INPUT); //Make pin 7 an input pin.
  servo.attach(servoPin);
  servo.write(state);

  Serial.begin (9600); // initialize the serial port:
}
  
void loop (){
  //poll inputs for signal
  rightVal = analogRead(rightSensorPin);
  leftVal = analogRead(leftSensorPin);
  Serial.println(rightVal);
  Serial.println(leftVal);
  
  // when the sensor detects a signal above the threshold value set on sensor, turn finder to the direction of sound
    if(rightVal - leftVal > difference){
      Serial.println("Turning Right");
      if(state <= 179){
        state = state + 1;
        servo.write(state);
    }else if(leftVal - rightVal > difference){
      Serial.println("Turning left");
      if(state >= 1){
        state = state - 1;
        servo.write(state);  
      }
    }
  delay(100);
  }
}
