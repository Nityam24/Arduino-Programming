const int buttonPin  = 2;     // the pin that the pushbutton is attached to
const int ledPin     = 13;    // the pin that the LED is attached to

int buttonState      = 0;     // current state of the button
int lastButtonState  = 0;     // previous state of the button
int ledState         = 0;     // remember current led state

void setup() {
  pinMode(buttonPin, INPUT);  // initialize the button pin as a input
  pinMode(ledPin, OUTPUT);    // initialize the button pin as a output
}

void loop() {
  // read the pushbutton input pin
  buttonState = digitalRead(buttonPin);

  // check if the button is pressed or released
  // by comparing the buttonState to its previous state 
  if (buttonState != lastButtonState) {
    
    // change the state of the led when someone pressed the button
    if (buttonState == 1) { 
      if(ledState==1) ledState=0;
      else            ledState=1;         
    }
    
    // remember the current state of the button
    lastButtonState = buttonState;
  }
  
  // turns LED on if the ledState=1 or off if the ledState=0
  digitalWrite(ledPin, ledState);
  
  // adding a small delay prevents reading the buttonState to fast
  // ( debouncing )
  delay(20);
}
If you like to work with more than two states, do something like below. And use a switch or if statement later to perform some action on a certain stateNum value.

if (buttonState == 1) { 
      stateNum++; 
      if(stateNum>2) stateNum=0;      
}
