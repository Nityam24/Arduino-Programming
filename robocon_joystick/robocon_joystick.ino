// motor A

int enA = 9;
int in1 = 8;
int in2 = 7;

// motor B

int enB = 3;
int in3 = 5;
int in4 = 4;

// joystick Input 
int joyVert = A0;  //vertical
int joyHorz = A1;


//Motor Speed values - start at zero
int MotorSpeed1 = 0;
int MotorSpeed2 = 0;


//joystick values - start at 512(middle position)
int joyposVert = 512;
int joyposHorz = 512;






void setup() {
  // put your setup code here, to run once:
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    // put your main code here, to run repeatedly:

    //motor A

    digitalWrite(enA, LOW);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    //MOTOR B

    digitalWrite(enB, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

    //Read the joystick X and Y positions

    joyposVert = analogRead(joyVert);
    joyposHorz = analogRead(joyHorz);

    //determine if this is a forward or backward motion 
    //Do this by reading the verticle value 
    //apply results to MotorSpeed and to direction

    if(joyposVert<460)
    {
      //this is backward
      //set motor A backward

      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);

      //SET MOTOR B backward

      digitalWrite(in3,LOW);
      digitalWrite(in4, HIGH);

      //DETERMINE MOTOR SPEEDS

      //AS WE ARE GOING BACKWARD WE NEED TO REVERSE READINGS

      joyposVert = joyposVert - 460;   //this produce a negative number 
      joyposVert = joypos Vert * -1;   //make the number positive 

      MotorSpeed1 = map(joyposVert, 0,460, 0, 255);
       MotorSpeed2 = map(joyposVert, 0,460, 0, 255);
    } 
    else if(joyposVert>564)
    {
      //this is forward

      //set motor A forward

      digitalWrite(in1, HIGH);
      digitalWrite(in2,LOW);

      //SET motor B forward

      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

      //DETERMINE motor speeds

      MotorSpeed1 = map(joyposVert, 564, 1023, 0, 255);
      MotorSpeed2 = map(joyposVert, 564, 1023, 0, 255);
    }
    else
    {
      //this is stopped 

      MotorSpeed1 = 0;
      MotorSpeed2 = 0;
    }

    //now do streeing
    //the horizontal position will "weigh" the motor speed
    //value for each motor

    if(joy)
    }
}
