int sw = 2;
int pwm1 = 9;
//int pwm2 = 6;
 int dir1 = 7;
 
//int dir2 = 8;
int joyposVert = 512;
int joyposHorz = 512;
int joyVert = A1;
int joyHorz = A2; 
 int motorSpeed1 = 0;
int motorSpeed11=  0;
//int motorSpeed22 = 0;
//int motorSpeed2 = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pwm1, OUTPUT);
pinMode(dir1,OUTPUT);

//pinMode(pwm2, OUTPUT);
//pinMode(dir2,OUTPUT);

   digitalWrite(pwm1,LOW);
digitalWrite(dir1, HIGH);
 //digitalWrite(pwm2,LOW);
//digitalWrite(dir2, HIGH);



}

void loop() {
  // put your main code here, to run repeatedly:
  joyposVert = analogRead(A1);
  //Serial.println(joyposVert);
 // joyposHorz = analogWrite(A0);
   if(joyposVert< 514){
        digitalWrite(dir1, HIGH);

  //      digitalWrite(dir2, HIGH);
   //     digitalWrite(dir3, HIGH);
 //       digitalWrite(dir4, LOW);
        //digitalWrite(pwm1, joyposVert);
        motorSpeed1 = 514-joyposVert;
    //    motorSpeed2 = 514 - joyposVert;
     //   motorSpeed3 = 514-joyposVert;
       // motorSpeed4 = 514-joyposVert;
        motorSpeed11 = map(motorSpeed1,0, 514, 0,255);
      //  motorSpeed22 = map(motorSpeed2,0, 514, 0,255);
        //motorSpeed33 = map(motorSpeed1,0, 514, 0,255);
        //motorSpeed44 = map(motorSpeed2,0, 514, 0,255);
       // Serial.println(motorSpeed11);
        analogWrite(pwm1, motorSpeed11);
        //analogWrite(pwm2, motorSpeed22);
       // analogWrite(pwm3, motorSpeed33);
       // analogWrite(pwm4, motorSpeed44);
    }
    
  else if(joyposVert> 514){
        digitalWrite(dir1, LOW);
        //digitalWrite(dir2,LOW);
        //digitalWrite(dir3,LOW);
        //digitalWrite(dir4,HIGH);
        //digitalWrite(pwm1, joyposVert);
        motorSpeed1 = joyposVert - 514;
        //motorSpeed2 = joyposVert-514;
        //motorSpeed3 = joyposVert-514;
        //motorSpeed4 = joyposVert-514;


        motorSpeed11 = map(motorSpeed1,0, 514, 0,255);
         //motorSpeed22 = map(motorSpeed2,0, 512, 0,255);
         //motorSpeed33 = map(motorSpeed2,0, 512, 0,255);
         //motorSpeed44 = map(motorSpeed2,0, 512, 0,255);
       // Serial.prinssstln(motorSpeed11);
        analogWrite(pwm1, motorSpeed11);
        
        //analogWrite(pwm2, motorSpeed22);
        Serial.println( "y axis ");
        Serial.println(analogRead(A1));
        //Serial.print("x axis ");
        //Serial.print(analogRead(A2));
        //analogWrite(pwm3, motorSpeed33);
        //analogWrite(pwm4, motorSpeed44);
    }
    
    
}
