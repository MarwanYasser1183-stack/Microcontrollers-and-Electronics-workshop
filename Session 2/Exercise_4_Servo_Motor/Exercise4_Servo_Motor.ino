#include <Servo.h>
 
Servo myServo;
const int potPin   = A0;
const int servoPin = 3;
 
void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
}
 
void loop() {
  int potValue = analogRead(potPin);           // 0–1023
  int angle    = map(potValue, 0, 1023, 0, 180); // Scale to 0–180 degrees
  myServo.write(angle);
  Serial.print("Angle: "); Serial.println(angle);
  delay(15);  // Give servo time to reach position
}
