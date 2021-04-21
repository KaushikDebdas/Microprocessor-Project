// SLAVE 1
#include <Wire.h>
#include <VirtualWire.h>
#include <VirtualWire_Config.h>
int Humidity = 0;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(11,INPUT_PULLUP); // PUSH BUTTON, using external pullup resistor  / internal pullup resistor* connect with pin 11
  pinMode(9,INPUT_PULLUP);  // PUSH BUTTON, using external pullup resistor  / internal pullup resistor* connect with pin 9
  pinMode(7,INPUT_PULLUP);  // PUSH BUTTON, using external pullup resistor  / internal pullup resistor* connect with pin 7
  Wire.begin(1);  // wire begin with salve1
  
  // Attach a funtion to trigger when something is recevied
  Wire.onReceive(receiveEvent);
  Serial.begin(9600); // Serial Communication Start
  Serial.println("****SLAVE 1 TERMINAL****");

  // RF Module Code
  vw_set_ptt_inverted(true);  //Configure the "push to talk" polarity
  vw_setup(2000); // initialize all the library 
  vw_set_tx_pin(12);  // transmitted pin is connected to DIGITAL pin 12

}

void receiveEvent(int bytes)
{
  Humidity = Wire.read();    // read on character from the I2C
}

void loop() {
  // put your main code here, to run repeatedly:

  // Print Slave 1
  Serial.print("Slave Device 1 : ");
  Serial.println(Humidity); // Print Humidity value
  delay(300); // delay 0.3sec

  // RF module
  if(digitalRead(11)==HIGH)
  {
    // RF module
    char msg[50] = {'P','1',' ','p','u','s','h',' ','i','d',' ','p','r','e','s','s','e','d'};
    vw_send((uint8_t *)msg, 18);  // Transmit a message. "msg" is an array of the bytes to send, and "length" is the number of bytes stored in the array
    delay(10); //delay of 0.01sec
  }

  if(digitalRead(9)==HIGH)
  {
    // RF module
    char msg[50] = {'P','2',' ','p','u','s','h',' ','i','d',' ','p','r','e','s','s','e','d'};
    vw_send((uint8_t *)msg, 18);  // Transmit a message. "msg" is an array of the bytes to send, and "length" is the number of bytes stored in the array
    delay(10); //delay of 0.01sec
  }

  if(digitalRead(7)==HIGH)
  {
    // RF module
    char msg[50] = {'P','3',' ','p','u','s','h',' ','i','d',' ','p','r','e','s','s','e','d'};
    vw_send((uint8_t *)msg, 18);  // Transmit a message. "msg" is an array of the bytes to send, and "length" is the number of bytes stored in the array
    delay(10); //delay of 0.01sec
  }
  
}
