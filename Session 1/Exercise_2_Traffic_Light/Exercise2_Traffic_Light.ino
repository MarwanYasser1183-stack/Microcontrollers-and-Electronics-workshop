const int greenPin  = 9; 
const int yellowPin = 10; 
const int redPin    = 11; 
  
void setup() { 
  pinMode(greenPin,  OUTPUT); 
  pinMode(yellowPin, OUTPUT); 
  pinMode(redPin,    OUTPUT); 
} 
  
void loop() { 
  // Green phase 
  digitalWrite(greenPin, HIGH); 
  delay(3000); 
  digitalWrite(greenPin, LOW); 
  
  // Yellow phase 
  digitalWrite(yellowPin, HIGH); 
  delay(1000); 
  digitalWrite(yellowPin, LOW); 
  
  // Red phase 
  digitalWrite(redPin, HIGH); 
  delay(3000); 
  digitalWrite(redPin, LOW); 
}