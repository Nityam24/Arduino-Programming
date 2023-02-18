//R2 Ball Gripper code
const int dirPin1 = ;
const int stepPin1 = ;
const int dirPin2 = ;
const int stepPin2 = ;
const int dirPin3 = ;
const int stepPin3 = ;

const int buttonPin = ;
const int motorPin = ;
 int buttonState = 0;
 int lastButtonState = 0;
 int motorState = 0;

const int stepPerRev = 200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState){
    if(buttonState == 1){
      if(motorState == 1)motorState=0;
      else               motorState=1;
      }
    lastButtonState = buttonState;
  }
  digitalWrite(motorPin, motorState);
  
   if(digitalRead(motorPin)==1){
    digitalWrite(dirPin1,HIGH);
    digitalWrite(dirPin2,HIGH);
    digitalWrite(dirPin3,HIGH);
    
    for(int x=0; x< ; x++){
      digitalWrite(stepPin1, 1);
      digitalWrite(stepPin2, 1);
      digitalWrite(stepPin3, 1);
      delay(100);
      digitalWrite(stepPin1, 0);
      digitalWrite(stepPin2, 0);
      digitalWrite(stepPin3, 0);
      delay(100);
      
      }
   }
   else if(digitalRead(motorPin)==0){
      digitalWrite(dirPin1, 0);
      digitalWrite(dirPin2, 0);
      digitalWrite(dirPin3, 0);


    for(int x=0; x< ; x++){
      digitalWrite(stepPin1, 1);
      digitalWrite(stepPin2, 1);
      digitalWrite(stepPin3, 1);
      delay(100);
      digitalWrite(stepPin1, 0);
      digitalWrite(stepPin2, 0);
      digitalWrite(stepPin3, 0);
      delay(100);
      
      }
   }


//2nd code
/*#include <AFMotor.h>
const int stepsPerRevolution = 200;

AF_Stepper motor1(stepsPerRevolution,1);
AF_Stepper motor2(stepsPerRevolution,2);
AF_Stepper motor3(stepsPerRevolution,3);

void setup() {
  Serial.begin(9600);
  Serial.println("Stepper test!");

  motor1.setSpeed(10); // 10 rpm
  motor2.setSpeed(10);
  motor3.setSpeed(10);   
if(digitalWrite(A0)==){
  Serial.println("Single coil steps");
  motor1.step(100, FORWARD, SINGLE); 
  motor2.step(100, FORWARD, SINGLE);
  motor3.step(100, FORWARD, SINGLE);
}

  else if(digitalWrite(A1)==){
    
   motor1.step(100, BACKWARD, SINGLE); 
  motor2.step(100, BACKWARD, SINGLE);
  motor3.step(100, BACKWARD, SINGLE);
    
    }
}*/
