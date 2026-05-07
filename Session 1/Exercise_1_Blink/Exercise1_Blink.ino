void setup() { 
  pinMode(LED_BUILTIN, OUTPUT);  // Set built-in LED pin as output 
} 
  
void loop() { 
  digitalWrite(LED_BUILTIN, HIGH);  // LED on 
  delay(500);                        // Wait 500ms 
  digitalWrite(LED_BUILTIN, LOW);   // LED off 
  delay(500);                        // Wait 500ms 
}