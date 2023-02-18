// joystick control / omni wheels


#define pinX A1
#define pinY A0

#define dir1 2
#define pwm1 3
#define dir2 4
#define pwm2 5
#define dir3 7
#define pwm3 6
#define dir4 8
#define pwm4 9

#define initSpd 20
#define finalSpd 1023
#define joyIdle 512

int xVal;
int yVal;

void setup() {

  pinMode(pwm1, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(pwm4, OUTPUT);
  pinMode(dir4, OUTPUT);
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  Serial.begin(9600);
}

void loop() {
xVal = analogRead(pinX);
  yVal = analogRead(pinY);
  int val = 0;
  int spd = 0;

// Assuming joystick origin at bottom right
  
  if(xVal >= yVal){
    if(xVal < joyIdle){
      val = joyIdle - xVal;
      spd = map(val, 0, (1023-joyIdle), 0, 255);
      drive(spd, 1, 1, 0, 0);
    }
    else if(xVal >= joyIdle){
      val = xVal - joyIdle;
      spd = map(val, joyIdle, 1023, 0, 255);
      drive(spd, 0, 0, 1, 1);
    }
  }
  else if(xVal < yVal){
    if(yVal < joyIdle){
      val = joyIdle - yVal;
      spd = map(val, 0, (1023-joyIdle), 0, 255);
      drive(spd, 1, 0, 0, 1);
    }
    else if(yVal >= joyIdle){
      val = yVal - joyIdle;
      spd = map(val, joyIdle, 1023, 0, 255);
      drive(spd, 0, 1, 1, 0);
    }
  }
}

int drive(int spd, int d1, int d2, int d3, int d4){
  analogWrite(pwm1, spd);
  analogWrite(pwm2, spd);
  analogWrite(pwm3, spd);
  analogWrite(pwm4, spd);
  digitalWrite(dir1, d1);
  digitalWrite(dir2, d2);
  digitalWrite(dir3, d3);
  digitalWrite(dir4, d4);
}
