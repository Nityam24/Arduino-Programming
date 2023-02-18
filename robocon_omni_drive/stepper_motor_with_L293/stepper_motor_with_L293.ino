#include <AFMotor.h>

// Number of steps per output rotation
// Change this as per your motor's specification
const int stepsPerRevolution = 200;

// connect motor to port #2 (M3 and M4)
AF_Stepper motor(stepsPerRevolution, 1);

void setup() {
  Serial.begin(9600);
  Serial.println("Stepper test!");
pinMode(A0, INPUT);
  motor.setSpeed(100);  // 10 rpm 
   //motor.step(200, FORWARD, INTERLEAVE);   
}

void loop() {
  //Serial.println("Single coil steps");
  while(digitalRead(A0)==1){
    motor.step(10, FORWARD, SINGLE);
   // delay(10);
    Serial.println(digitalRead(A0)); 
    }
}
// motor.step(1, FORWARD, SINGLE); 
  //delay(1000);
// motor.step(100, BACKWARD, SINGLE); 
//delay(1000);

 /* Serial.println("Double coil steps");
  motor.step(100, FORWARD, DOUBLE); 
  motor.step(100, BACKWARD, DOUBLE);

  Serial.println("Interleave coil steps");
  motor.step(100, FORWARD, INTERLEAVE); 
  motor.step(100, BACKWARD, INTERLEAVE); 

  Serial.println("Micrsostep steps");
  motor.step(100, FORWARD, MICROSTEP); 
  motor.step(100, BACKWARD, MICROSTEP); */
