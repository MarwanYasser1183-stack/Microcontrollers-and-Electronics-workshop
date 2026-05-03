#include <WiFi.h>
#include <WebServer.h>
 
const char* ssid     = "YOUR_WIFI_NAME";     // Change this
const char* password = "YOUR_WIFI_PASSWORD"; // Change this
const int ledPin = 2;
 
WebServer server(80);
 
void handleRoot() {
  String html = "<html><body style='font-family:Arial;text-align:center;padding:40px'>";
  html += "<h2>ESP32 LED Control</h2>";
  html += "<a href='/on'><button style='padding:30px 60px;font-size:24px;margin:10px'>ON</button></a>";
  html += "<a href='/off'><button style='padding:30px 60px;font-size:24px;margin:10px'>OFF</button></a>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}
 
void handleOn()  { digitalWrite(ledPin, HIGH); server.sendHeader("Location","/"); server.send(303); }
void handleOff() { digitalWrite(ledPin, LOW);  server.sendHeader("Location","/"); server.send(303); }
 
void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println("\nConnected! Open this IP in your browser:");
  Serial.println(WiFi.localIP());
  server.on("/",    handleRoot);
  server.on("/on",  handleOn);
  server.on("/off", handleOff);
  server.begin();
}
 
void loop() {
  server.handleClient();
}
