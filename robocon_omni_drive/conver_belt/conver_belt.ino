//R1 conver Belt 

const int dirPin = ;
const int stepPin = ;

const int buttonPin = ;
const int motorPin = ;
 int buttonState = 0;
 int lastButtonState = 0;
 int motorState = 0;

const int stepPerRev = 200;

void setup(){
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
   pinMode(buttonPin, INPUT);
  pinMode(motorPin, OUTPUT);

  if(digitalRead(motorPin)==1){
    digitalWrite(dirPin, HIGH);

    for(int x=0; x< ; x++){
      digitalWrite(stepsPin, 1);
      delay(100);
      digitalWrite(stepPin, 0);
      delay(100);
      }
  }
  }
  void loop(){
     buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState){
    if(buttonState == 1){
      if(motorState == 1)motorState=0;
      else               motorState=1;
      }
    lastButtonState = buttonState;
  }
  digitalWrite(motorPin, motorState);
  delay(500);
    
    }

 //2nd code

 /*#include <AFMotor.h>
const int stepsPerRevolution = 200;

AF_Stepper motor1(stepsPerRevolution,1);

void setup(){
   Serial.begin(9600);
  Serial.println("Stepper test!");

  motor1.setSpeed(10); 
  if(digitalWrite(A0)==){
  Serial.println("Single coil steps");
  motor1.step(100, FORWARD, SINGLE); 
  }

  else if(digitalWrite(A1)==){
    
   motor1.step(100, BACKWARD, SINGLE); 
  }
}
  

  
  }

 */
