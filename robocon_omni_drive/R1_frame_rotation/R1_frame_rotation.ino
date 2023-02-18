int dir1;
int dir2;
int pwm1;
int pwm2;
int x;
int y;
float xVal;
float yVal;



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(pwm1,INPUT);
pinMode(pwm2, INPUT);
pinMode(dir1, OUTPUT);
pinMode(dir2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    int x = analogRead(A0);
    int y = analogRead(A1);
    float xVal = map(x,);

if(x>){
    digitalWrite(dir1,HIGH);
}else if(x<){
    digitalWrite(dir1, LOW);
 }
    analogWrite(pwm1, xVal);

    

    float yVal = map(y,);
    if(y>){
    digitalWrite(dir2,HIGH);
    }else if(y<){
    digitalWrite(dir2, LOW);
    }
    analogWrite(pwm2, yVal);
}
