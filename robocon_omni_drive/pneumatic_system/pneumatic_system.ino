int pin = 4;
int ch =3 ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   pinMode(pin,OUTPUT);
   pinMode(ch, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  long on =pulseIn(ch, HIGH);
  Serial.println(on);

  if(){
    digitalWrite(pin,1);
    delay(1000);
  }
esle {
    digitalWrite(pin,0);
    delay(1000);
  }
}
