// R2 lagori Gripper
const int dirPin1 = ;
const int stepPin1 = ;
const int buttonPin = ;
const int motorPin = ;
 int buttonState = 0;
 int lastButtonState = 0;
 int motorState = 0;

const int stepPerRev =200;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
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
  
if(digitalRead(A1)==){
  int val = ;
}
else if(digitalRead(A2)==){
  int val = ;  
  }
  else if(digitalRead(A3)==){
    int val = ;
    }
    else if(digitalRead(A4)==){
    int val = ;      
      }
      else if(digitalRead(A5)==){
     int val = ;   
        }
      
    

if(digitalRead(motorPin)==1){
    digitalWrite(dirPin1,HIGH);
}
else if(digitalRead(motorPin)==0){
    digitalWrite(dirPin1,LOW);
  }

    for(int x=0; x<val ; x++){
      digitalWrite(stepPin1, 1);
      delay(100);
      digitalWrite(stepPin1, 0);
      delay(100);
      
      }
   
   
        
   delay(100);
}
