#include <dht11.h>
#define DPIN 2   // Data pin connected to pin 2
dht11 DHT;
void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 Ready!");
}
void loop() {
  int result = DHT.read(DPIN);
  switch (result) {
    case DHTLIB_OK:
      Serial.print("Humidity:    ");
      Serial.print(DHT.humidity);
      Serial.println(" %");
      Serial.print("Temperature: ");
      Serial.print(DHT.temperature);
      Serial.println(" °C");
      Serial.println("-------------------");
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.println("Checksum error!");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.println("Timeout error!");
      break;
    default:
      Serial.println("Unknown error!");
      break;
  }
  delay(2000); // DHT11 needs ~2 seconds between readings
}
