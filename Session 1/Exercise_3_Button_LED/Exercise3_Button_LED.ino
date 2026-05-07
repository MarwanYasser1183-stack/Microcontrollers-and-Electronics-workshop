const int buttonPin = 2; 
const int ledPin    = 7; 
  
void setup() { 
  pinMode(buttonPin, INPUT_PULLUP);  // Built-in pull-up: HIGH normally, LOW when pressed 
  pinMode(ledPin, OUTPUT); 
} 
  
void loop() { 
  if (digitalRead(buttonPin) == LOW) {  // Button pressed 
    digitalWrite(ledPin, HIGH);           // LED on 
  } else { 
    digitalWrite(ledPin, LOW);            // LED off 
  } 
}