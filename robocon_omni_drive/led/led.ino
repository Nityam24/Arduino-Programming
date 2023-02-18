

const int bulb = 13;
void setup() {
  // put your setup code here, to run once:
  
pinMode(bulb, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(bulb,HIGH);
  delay(100);
  digitalWrite(bulb, LOW);
  delay(100);
  

}
