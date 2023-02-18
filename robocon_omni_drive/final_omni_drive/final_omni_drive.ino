#include <IBusBM.h>

// Create iBus Object
IBusBM ibus;

// Channel Values

int rcCH1 = 0; // Left - Right
int rcCH2 = 0; // Forward - Reverse
int rcCH4 = 0; // turn clockwise - anticlockwise

int joyMid = 0;

 long int x;
long int y;
 double xVal;
double yVal;
float theta;
#define pi 3.14
int pwm[4] = {0,1,2,3};
int pwm[0] = ;
int pwm[1] = ;
int pwm[2] = ;
int pwm[3] = ;
int dir[4] = {0,1,2,3};
int dir[0] = ;
int dir[1] = ;
int dir[2] = ;
int dir[3] = ;
//double p[4] ={0,1,2,3};
int i;
 double p1 = 0;
 double p2 = 0;
 double p3 = 0;
 double p4 = 0;
int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}




void setup()
  
{
  Serial.begin(115200);

  
  ibus.begin(Serial);

  
   pinMode();
   pinMode();
   pinMode();
   pinMode();
   pinMode();
   pinMode();

   void drive(int p1,int p2,int p3, int p4,int d1, int d2, int d3, int d4){
  analogWrite(pwm[0], abs(p1));
  analogWrite(pwm[1], abs(p2));
  analogWrite(pwm[2], abs(p3));
  analogWrite(pwm[3], abs(p4));
  digitalWrite(dir[0], d1);
  digitalWrite(dir[1], d2);
  digitalWrite(dir[2], d3);
  digitalWrite(dir[3], d4);
  }

   void loop() {

  
  rcCH1 = readChannel(0, -100, 100, 0);
  rcCH2 = readChannel(1, -100, 100, 0);
  rcCH4 = readChannel(3, -100, 100, 0);
  

  
  Serial.print("Ch1 = ");
  Serial.print(rcCH1);

  Serial.print(" Ch2 = ");
  Serial.print(rcCH2);

  Serial.print(" Ch4 = ");
  Serial.print(rcCH4);

//long int x = analogRead(A0);
//xVal = map(rcCH1, -100, 100, 0, 255);
//long int y = analogRead(A1);
//yVal = map(rcCH2, -100, 100, 0, 255);
   Serial.print("\n x axis: ");
    Serial.println(xVal);
    //delay(1000);
    Serial.println("\n y axis: ");
    Serial.println(yVal);
    delay(1000);
  double power = sqrt(sq(xVal) + sq(yVal));
  Serial.println("power: ");
  Serial.println(power);
    delay(1000);
   float theta = atan(rcCH1/rcCH2);
   Serial.println("theta: ");
   Serial.println(theta);                 // ans in radian
   delay(1000);
   float thetad = atan(rcCH1/rcCH2)*(180/pi);
   Serial.println("in degree: ");
   Serial.println(thetad);                // ans in degree
   delay(1000);
    float M1 = -sin(theta + pi/4);
    float M2 = cos(theta + pi/4);
    float M3 = sin(theta + pi/4);
    float M4 = -cos(theta + pi/4);

        Serial.println(M1);
         Serial.println(M2);
          Serial.println(M3);
           Serial.println(M4);
           Serial.println("\n");
           delay(1000);


     p1 = power * (M1);
     p2 = power * (M2);
     p3 = power * (M3);
     p4 = power * (M4);

    Serial.println(p1);
    Serial.println(p2);
    Serial.println(p3);
    Serial.println(p4);
    
  delay(1000);

  
   /*   for(i=0; i<4; i++){
        if(p[i]<0){
            digitalWrite(dir[i],LOW);
            analogWrite( pwm[i],-p[i]);
          }
          else{
              digitalWrite(dir[i] ,HIGH);
              analogWrite(pwm[i] ,p[i]);
            }
          
        }*/
    //   if((rcCH1<-5 && rcCH1>5) || (rcCH2<-5 && rcCH2>5)){
         if(abs(rcCH1)>=abs(rcCH2)){
           if(rcCH1<joyMid){
            drive(p1,p2,p3,p4,1,1,0,0);
            } 
            else if(rcCH1>=joyMid){
              drive(p1,p2,p3,p4,0,0,1,1);
              }
          }
          else if(abs(rcCH1)<abs(rcCH2)){
            if(rcCH2<joyMid){
              drive(p1,p2,p3,p4,1,0,0,1);
              }
              else if(rcCH2>=joyMid){
                drive(p1,p2,p3,p4,0,1,1,0);
                }
            }
              else if(rcCH4>0){
                drive(rcCH4,rcCH4,rcCH4,rcCH4,1,1,1,1);
                }
                else if{
                  drive(rcCH4,rcCH4,rcCH4,rcCH4,0,0,0,0);
                  }
   }
                   
}
 
