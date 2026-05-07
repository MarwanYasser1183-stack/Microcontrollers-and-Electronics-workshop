const int ldrPin   = A2;
const int ledPin   = 5;
const int threshold = 500;  // Adjust: lower = turns on earlier
 
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  int lightLevel = analogRead(ldrPin);  // 0 = dark, 1023 = bright
  Serial.print("Light level: ");
  Serial.println(lightLevel);
 
  if (lightLevel < threshold) {
    digitalWrite(ledPin, HIGH);  // Dark — turn LED on
  } else {
    digitalWrite(ledPin, LOW);   // Bright — turn LED off
  }
  delay(200);
}
