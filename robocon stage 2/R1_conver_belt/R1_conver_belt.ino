const int dirPin = ;
const int stepPin = ;
const int motorPin = ;

const int stepPerRev = 200;

void setup() {
  // put your setup code here, to run once:
    pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(motorPin)==1){
    digitalWrite(dirPin, HIGH);

    
      digitalWrite(stepPin, 1);
      delay(100);
      digitalWrite(stepPin, 0);
      delay(100);
}
}
