void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);


}

id setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);


}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorvalue = analogRead(A0);
  int sn2=analogRead(A1);
  if( sensorvalue>512 && sn2>512){
        Serial.print("\n Left-up, ");
        Serial.print(map(sensorvalue,512,1023,0,10));
        Serial.print(", ");
        Serial.print( map(sn2,512,1023,0,10));
        delay(1000);
      } 
      else if( sensorvalue>512 && sn2<512){
        Serial.print("\n Left-down, ");
        Serial.print(map(sensorvalue,512,1023,0,10));
        Serial.print(", ");
        Serial.print( map(sn2,0,512,10,0));
        delay(1000);
      }
      else if( sensorvalue<512 && sn2<512){
        Serial.print("\n Right-down, ");
        Serial.print(map(sensorvalue,0,512,10,0));
        Serial.print(", ");
        Serial.print( map(sn2,0,512,10,0));
        delay(1000);
      }
      else if( sensorvalue<512 && sn2>512){
        Serial.print("\n Right-up, ");
        Serial.print(map(sensorvalue,0,512,10,0));
        Serial.print(", ");
        Serial.print( map(sn2,512,1023,0,10));
        delay(1000);
      }
      
 else if(sensorvalue<512){
  Serial.print("\n Right ");
  Serial.print(map(sensorvalue, 0, 512, 10,0));
  delay(1000);
  }
  else if(sensorvalue>512){
  Serial.print("\n Left ");
  Serial.print(map(sensorvalue, 512, 1023, 0, 10));
  delay(1000);
  }
  else if(sn2<512){
    Serial.print("\n down ");
    Serial.print(map(sn2, 0, 512, 10, 0));
    delay(1000);
    }
    else if(sn2>512){
      Serial.print("\n up ");
      Serial.print(map(sn2, 512, 1023, 0, 10));
      delay(1000);
      }
      
  else{
    Serial.print("\n middle ");
    Serial.print(0);
    delay(1000);
  }
}
