#include <Servo.h>

Servo gate;
Servo push;

#define gateIN A1
#define pushIN A2
#define spdIN 10
#define pitchIN 11
#define yawIN 9
#define conIN 8
#define btnIN A0
#define srvP 6
#define srvD 7
#define srvYP 12
#define srvYD 13
#define leftP 4
#define leftD 5
#define rightP 2
#define rightD 3
#define pA 26
#define pB 24
#define belt 28

void drive(int spd, int d1, int d2){
  analogWrite(leftP, spd);
  analogWrite(rightP, spd);
    digitalWrite(leftD, d1);
  digitalWrite(rightD, d2);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("BEGIN!");

  gate.attach(30);
  push.attach(32);
  
  pinMode(spdIN, INPUT);
  pinMode(pitchIN, INPUT);
  pinMode(yawIN, INPUT);
  pinMode(btnIN, INPUT);
  pinMode(conIN, INPUT);
  pinMode(gateIN, INPUT);
  pinMode(pushIN, INPUT);
  pinMode(pA, OUTPUT);
  pinMode(pB, OUTPUT);
  pinMode(belt, OUTPUT);
  pinMode(srvP, OUTPUT);
  pinMode(srvD, OUTPUT);
  pinMode(leftP, OUTPUT);
  pinMode(leftD, OUTPUT);
  pinMode(rightP, OUTPUT);
  pinMode(rightD, OUTPUT);
  digitalWrite(srvD, 0);
  digitalWrite(leftD, 0);
  digitalWrite(rightD, 0);
  digitalWrite(pA, 1);
  digitalWrite(pB, 1);
  digitalWrite(belt, 1);
  analogWrite(srvP, 0);
  analogWrite(leftP, 0);
  analogWrite(rightP, 0);
  drive(0, 0, 0);
}

void loop()
{
  int spd = pulseIn(spdIN, HIGH, 30000); 
  int pitch = pulseIn(pitchIN, HIGH, 30000);
  int yaw = pulseIn(yawIN, HIGH, 30000);
  int btn = pulseIn(btnIN, HIGH, 30000);
  int con = pulseIn(conIN, HIGH, 30000);
  int gateVal = pulseIn(gateIN, HIGH, 30000);
  int pushVal = pulseIn(pushIN, HIGH, 30000);

  int val = abs(map(spd, 1500, 1960, 0, 250));
  int pitchVal = abs(map(pitch, 980, 1980, -25, 25));
  int yawVal = abs(map(yaw, 980, 1980, -25, 25));
  if (val > 200 ) val = 200;
  
  Serial.print(spd);
  Serial.print("/t" );
  Serial.print(val);  

  if(pitch > 1520) {
    analogWrite(srvP, 100);
    digitalWrite(srvD, 0);
  }
  else if(pitch < 1400) {
    analogWrite(srvP, 50);
    digitalWrite(srvD, 1);
  } else {
    analogWrite(srvP, 0);
    digitalWrite(srvD, 0);
    }

  if(pitch > 1520) {
    analogWrite(srvYP, 100);
    digitalWrite(srvYD, 0);
  }
  else if(pitch < 1400) {
    analogWrite(srvYP, 50);
    digitalWrite(srvYD, 1);
  } else {
    analogWrite(srvYP, 0);
    digitalWrite(srvYD, 0);
    }

  if(con > 1400){
    digitalWrite(belt, 0);
  }
  else{
    digitalWrite(belt, 1);
  }

  if(gateVal > 1400){
    gate.write(0);
  }
  else{
    gate.write(90);
  }

  if(pushVal > 1400) {
    push.write(120);
  }
  else {
    push.write(170);
  }
    
  if(btnIN > 1350 && btnIN < 1550) {
    digitalWrite(pA, 1);
    digitalWrite(pB, 1);
  }
  else if(btnIN < 1100) {
    digitalWrite(pA, 1);
    digitalWrite(pB, 0);
  }
  else if(btnIN > 1800) {
    digitalWrite(pA, 0);
    digitalWrite(pB, 1);
  }

  
  if(spd > 1500) {
    drive(val, 0, 0);
  } else {
    drive(0, 0, 0);
  }

  delay(100);

}
