const int trigPin    = 9;
const int echoPin    = 10;
const int buzzerPin  = 11;
const int threshold  = 20;  // cm — alarm distance
 
void setup() {
  pinMode(trigPin,   OUTPUT);
  pinMode(echoPin,   INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Measure echo time and calculate distance
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;  // Speed of sound / 2
 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
 
  if (distance < threshold) {
    digitalWrite(buzzerPin, HIGH);  // Too close — alarm on
  } else {
    digitalWrite(buzzerPin, LOW);   // Safe distance — alarm off
  }
  delay(200);
}
