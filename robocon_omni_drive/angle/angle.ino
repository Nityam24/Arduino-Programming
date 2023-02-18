
//int joyVert = analogRead(A1);
//int joyHorz = analogRead(A0);
float pi = 3.141;
float angleDeg;
float angleRad = angleDeg*pi/180;
 //float power = sqrt(sq(joyHorz)+sq(joyVert)); 
//int pwm1 = 9;
//int dir1 = 7;
//int dir2 = 8;
int joyposVert = 512;
int joyposHorz = 512;

 //int motorSpeed1 = 0;
//int motorSpeed11=  0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//pinMode(pwm1, OUTPUT);
//pinMode(dir1,OUTPUT);
  
  // digitalWrite(pwm1,LOW);
//digitalWrite(dir1, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  //joyposVert = joyVert;
  //joyposHorz = joyHorz;
  //Serial.println(joyposVert);
 // joyposHorz = analogWrite(A0);
  angleDeg = atan((analogRead(A0)/analogRead(A1))) + 0.78;
  Serial.print(angleDeg);
  Serial.print("\n");
  
  delay(1000);
  
}
