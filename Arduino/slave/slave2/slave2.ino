// Slave 2
#include <Wire.h>

#include <VirtualWire.h>
#include <VirtualWire_Config.h>

int i  , j  , Humidity = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT); // Blue is connect with Digital Pin 9
  pinMode(10,OUTPUT); // Green is connect with Digital Pin 10
  pinMode(11,OUTPUT); // Red is connect with Digital Pin 11
  
  Wire.begin(2);  // wire begin with slave 2
  // Attach a funtion to trigger when something is recevied
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);   // Serial Communication Start
  Serial.println("****SLAVE 2 TERMINAL****");
  
}

void receiveEvent(int bytes)
{
  Humidity = Wire.read();    // read on character from the I2C
}

void loop() {
  // put your main code here, to run repeatedly:
  // SLAVE DEVICE 2 PRINT
  Serial.print("Slave Device 2 : ");
  Serial.println(Humidity); // Print Humidity value
  delay(300); // delay 0.3sec
  
  // IF Humidity increase then change RGB red to blue 
  // IF Humidity decrease then change RGB blue to red
  // to store Humidity(20-90) to rgb color(0-255)
  int diff = Humidity - 20 ;  
  int red = 255 - (diff * 4);
  int blue = 0 + (diff * 4);

  if(red < 0)
  {
    red = 0 ;
    blue = 255 ;
  }
  analogWrite(9,blue); // Blue
  analogWrite(10,0); // Green
  analogWrite(11,red); // Red

}
