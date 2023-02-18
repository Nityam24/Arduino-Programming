//arduino pin number
const int sw_pin = 2;
const int X_pin = 0;
const int Y_pin = 1;



void setup() {
  // put your setup code here, to run once:
  pinMode(sw_pin, INPUT);
  digitalWrite(sw_pin, HIGH);
  Serial.begin(115200);


}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("switch: ");
  Serial.print(digitalRead(sw_pin));
  Serial.print("\n");
  Serial.print("X axis:");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y_axis ");
  Serial.print(analogRead(Y_pin));
  Serial.print("\n\n");
  delay(500);
}
