long int x;
long int y;
 double xVal;
double yVal;
float theta;
#define pi 3.14
int pwm[4] = {0,1,2,3};
int dir[4] = {0,1,2,3};
double p[4] ={0,1,2,3};
int i;

void setup(){
  Serial.begin(9600);
  }

  void loop(){
    int x = -5;
    int y = -5;
//long int x = analogRead(A0);
xVal = map(x, 0, 1023, 0, 255);
//long int y = analogRead(A1);
yVal = map(y, 0, 1023, 0, 255);
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
   float theta = atan(x/y);
   Serial.println("theta: ");
   Serial.println(theta);                 // ans in radian
   delay(1000);
   float thetad = atan(x/y)*(180/pi);
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


     p[0] = power * (M1);
     p[1] = power * (M2);
     p[2] = power * (M3);
     p[3] = power * (M4);

    Serial.println(p[0]);
    Serial.println(p[1]);
    Serial.println(p[2]);
    Serial.println(p[3]);
    
  delay(1000);

  
      for(i=0; i<4; i++){
        if(p[i]<0){
            digitalWrite(dir[i],LOW);
            analogWrite( pwm[i],-p[i]);
          }
          else{
              digitalWrite(dir[i] ,HIGH);
              analogWrite(pwm[i] ,p[i]);
            }
          
        }
       
                   Serial.println();
    }

    
