const int STEP_PIN = 9;
const int Enable_PIN = 12;
const int DIR_PIN = 8;
long currentMicros = 0;
long previousMicros = 0;
float accel = 0;
int steps = 4000;
//float d =accel*0.4;
//float h= d/100;

void setup()
{
  Serial.begin(9600);
   pinMode(STEP_PIN, OUTPUT);
   pinMode(Enable_PIN, OUTPUT);
   pinMode(DIR_PIN, OUTPUT);
   digitalWrite(STEP_PIN, LOW);
   digitalWrite(Enable_PIN, HIGH); 
   digitalWrite(DIR_PIN, HIGH); 
}

void loop(){
  float d =accel*0.4;
  float h= d/100;
  
  digitalWrite(Enable_PIN, LOW);
    digitalWrite(DIR_PIN, LOW);
    float b=333;
  float a=8000;
    for (int i=0; i < steps; i++) {

      if (a<=b) a=b;
        else a=a-h;
        long delay_Micros =  a ;
    currentMicros = micros();
        
    if(currentMicros - previousMicros >= delay_Micros) {
          previousMicros = currentMicros;
          
          digitalWrite(STEP_PIN,HIGH);
            delayMicroseconds(a);
            digitalWrite(STEP_PIN,LOW);
      }
    }

  delay(5000);
 

    /* if (long delay_Micros=500) {
      digitalWrite(Enable_PIN, LOW);
        digitalWrite(DIR_PIN, HIGH);
        float c=333 ;
    float d=2000;
      for (int j=0; j< steps/5; j++) {
        if (d<=c) d=c;
        else c=c+h;
        long delay_Micros =  c ;
      currentMicros = micros();
        if(currentMicros - previousMicros >= delay_Micros) {
            previousMicros = currentMicros;
          digitalWrite(STEP_PIN,HIGH);
          delayMicroseconds(c);
        digitalWrite(STEP_PIN,LOW);
      }
       }
     
     delay(2000);
  } */
}
