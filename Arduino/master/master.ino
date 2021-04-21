// MASTER
#include <Wire.h>

#include <VirtualWire.h>
#include <VirtualWire_Config.h>

#include <dht.h>

dht DHT;


void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);   // Serial Communication Start
  Serial.println("****MASTER TERMINAL****");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  DHT.read11(9);  // Connect DHT11 with Digital pin9
  
  // Print & Collect Humidity from the environment using Digital Sensor
  Serial.print("Humidity = "); 
  int Humidity = DHT.humidity;  // DHT.humidity value stroe in HUMIDITY variable
  Serial.println(Humidity);   // Print Humidity value
  delay(50); // Delay 0.05sec
  
  // Slave 1 transimission
  Wire.beginTransmission(1); // transmit to device 1
  Wire.write(Humidity);      //  sends Humidity value
  Wire.endTransmission();   // stop transmitting
  delay(50);   // Delay 0.05sec

  // Slave 2 transmission
  Wire.beginTransmission(2); // transmit to device 2
  Wire.write(Humidity);      //  sends Humidity value
  Wire.endTransmission();   // stop transmitting
  delay(50); // Delay 0.05sec
  
}
