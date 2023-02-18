
int pwm1 =;
int pwm2 =;
int dir1 =;
int dir2 =;

int motorSpeed1 = 0;
int motorSpeed2 = 0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(dir1,1);
   digitalWrite(dir2,1);

   motorSpeed1 = analogRead(A0);
   motoeSpeed2 = analogRead(A1);

   int motorSpeed11 = map(motorSpeeed1,0,1023,0,255);
   int motorSpeed22 = map(motorSpeed2,0,1023,0,255);

   

   analogWrite(pwm1, motorSpeed11);
   analogWrite(pwm2, motorSpeed22);
}
