int dir1;
int pwm1;
int y;
float yVal;



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(pwm1,INPUT);
pinMode(dir1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 
    int y = analogRead(A1);

    float yVal = map(y,);
    if(y>){
    digitalWrite(dir2,HIGH);
    }
    else if(y<){
    digitalWrite(dir2, LOW);
    }
    analogWrite(pwm2, yVal);
}
