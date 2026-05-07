#include <BLEDevice.h> 
#include <BLEAdvertising.h> 
  
void setup() { 
  Serial.begin(115200); 
  BLEDevice::init("IEEE-RAS-MyName");  // Change MyName to your name 
  BLEAdvertising* adv = BLEDevice::getAdvertising(); 
  adv->start(); 
  Serial.println("BLE beacon is broadcasting!"); 
} 
  
void loop() { 
  delay(1000);  // Nothing else needed — BLE runs in background 
}