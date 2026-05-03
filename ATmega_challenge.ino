// ATmega32 version of Button + LED
// Pin numbers updated to MightyCore mapping
 
const int buttonPin = 12;  // Port B4 — was pin 2 on Arduino
const int ledPin    = 13;  // Port B5 — was pin 7 on Arduino
 
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}
 
void loop() {
  if (digitalRead(buttonPin) == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}

