//motorA

int enA = 9;
int in1 = 8;
int in2 = 7;

// motor B

int enB = 3;
int in3 = 5;
int in4 = 4;

//speed control potentiometers

int SpeedControl1 =A0;
int SpeedControl2 =A1;

//motor speed values - start at zero

int MotorSpeed1 = 0;
int MotorSpeed2 = 0;




void setup() {
  // put your setup code here, to run once:

    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //set Motor A forward

  digitalWrite(in1, HIGH);
  
  digitalWrite(in2, LOW);

  //set Motor B forward

  digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    //rEAD THE VALUE from potentiometers

    MotorSpeed1 = analogRead(SpeedControl1);
    MotorSpeed2 = analogRead(SpeedControl2);

    // convert to range of 0-255

    MotorSpeed1 = map(MotorSpeed1, 0, 1023, 0, 255);
        MotorSpeed2 = map(MotorSpeed2, 0, 1023, 0, 255);

        //adjust to prevent "buzzing" at very low speed 

        if(MotorSpeed1<8)MotorSpeed1 = 0;
        if(MotorSpeed2<8)MotorSpeed2 = 0;

        //set the motor speeds

        analogWrite(enA, MotorSpeed1);
        analogWrite(enB, MotorSpeed2);
        
}
