const int potPin = A0;   // Potentiometer wiper 
const int ledPin = 9;    // Must be PWM pin (marked with ~ on board) 
  
void setup() { 
  pinMode(ledPin, OUTPUT); 
} 
  
void loop() { 
  int potValue  = analogRead(potPin);           // 0 to 1023 
  int brightness = map(potValue, 0, 1023, 0, 255); // Scale to PWM range 
  analogWrite(ledPin, brightness);              // Set brightness 
}