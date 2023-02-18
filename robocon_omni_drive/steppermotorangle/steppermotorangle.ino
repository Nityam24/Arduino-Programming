// defines pins numbers

const int dir2 = 5;
const int dir1  = 2;
const int pwm1 = 8;

// Button

const int b1 = A0;
//const int b2 = A1;
//const int b3 = A2;
//const int b4 = A3;



int currentAngle = 0;
int angle = 0;
float stepPerAngle = 1.8; // full step = 1.8
int   numstep;




void setup() {

  Serial.begin(9600);

  // Sets the two pins as Outputs

  pinMode(dir2,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(pwm1,OUTPUT);

  digitalWrite(pwm1,LOW);
  digitalWrite(dir1,HIGH);



  pinMode(b1, INPUT);
  //pinMode(b2, INPUT);
  //pinMode(b3, INPUT);
  //pinMode(b4, INPUT);



}

void loop() {



    int n;
    if( analogRead(b1) >546){
      Serial.println(analogRead(b1));
    angle = 0;
    }

    else if( analogRead(b1)< 460){
      Serial.println(analogRead(b1));
      angle = 45;

    }
  /*  else if( digitalRead(b3) == HIGH){

     angle = 225;
 }

    else if( digitalRead(b4) == HIGH){

        angle = 270;
    }*/



    if( currentAngle != angle ){
        if( currentAngle < angle){

            digitalWrite(dir1,HIGH);
            n = angle - currentAngle;
            numstep = n / stepPerAngle;
        }

        else if( currentAngle > angle){
          digitalWrite(dir1,LOW);
          n = currentAngle - angle;

            if( angle == 0){

               n =currentAngle;

            }

            numstep = n / stepPerAngle;

        }



        for(int x = 0; x < numstep; x++) {

           digitalWrite(dir2,HIGH);

           delayMicroseconds(1000);

           digitalWrite(dir2,LOW);

           delayMicroseconds(1000);

        }
        currentAngle = angle;
    }
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   delay(500);

}
