
#include <ezButton.h>
#define LEDPin 13
#define ButtonPin 12
ezButton button(ButtonPin);  // create ezButton object that attach to pin 7;

void setup(){
  pinMode(LEDPin, OUTPUT);
  //pinMode(ButtonPin, INPUT_PULLUP);
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
}

void loop() {
  button.loop(); // MUST call the loop() function first

  //if (digitalRead(ButtonPin)){
  if(button.isPressed()){
    digitalWrite(LEDPin, HIGH);
  }
  //else{
  if(button.isReleased()){
    digitalWrite(LEDPin, LOW);
  }
}
