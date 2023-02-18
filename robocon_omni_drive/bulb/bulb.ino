void setup(){
  Serial.begin(9600);
  }

  void loop(){

    int bulb = 13;
    pinMode(bulb,HIGH);
    delay(1000);
    pinMode(bulb,LOW);
    delay(1000);
  }
