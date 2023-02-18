//L298N motor demonstration
//L298N motor.Demo.ino
//Demostrates function of L298N motor controller


//motor A

int enA = 9;
int in1 = 8;
int in2 = 7;

//motor B

int enB = 3;
int in3 = 5;
int in4 = 4;



void setup() {
  // put your setup code here, to run once:

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void demoOne(){
        //This function will run the motors in both direction at a fixed speed
        //Turn on motor A

         digitalWrite(in1, HIGH);
         digitalWrite(in2, LOW);

         //SET speed to 200 out of possible range 0-255

         analogWrite(enA, 200);

         //Turn on motor B

         digitalWrite(in3, HIGH);
         digitalWrite(in4, LOW);

         //SET speed to 200 out of possible range 0-255
         analogWrite(enB, 200);
         delay(2000);

         //now change motor directions

         digitalWrite(in1, LOW);
         digitalWrite(in2, HIGH);
         digitalWrite(in3, LOW);
         digitalWrite(in4, HIGH);

         delay(2000);

         //Now turn off motors 
         digitalWrite(in1, LOW);
         digitalWrite(in2, LOW);
         digitalWrite(in3, LOW);
         digitalWrite(in4, LOW);
}

        void demoTwo(){
          //This function will run motors across the range of possible speeds
          //Note that maximum speed is determined by motor itself and the operating voltage 

          //Turn on motors

          digitalWrite(in1, LOW);
          digitalWrite(in2,HIGH);
          digitalWrite(in3, LOW);
          digitalWrite(in4, HIGH);

          //Acclerate from zero to maximum speed
          int i;
          for (int i=0; i<256; i++);
          {
            analogWrite(enA,i);
            analogWrite(enB,i);

            delay(20);
          }

          //decelarate from maximum speed to zero
          for (int i = 255; i>= 0; --i)
          {
            analogWrite(enA, i);
            analogWrite(enB, i);

            delay(20);
            }

            //now turn off motors 

            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);
            
          }

void loop() {
  // put your main code here, to run repeatedly:
  demoOne();
  delay(1000);
  demoTwo();
  delay(1000);
  
}
