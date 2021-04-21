#include <VirtualWire.h>
int i;
void setup()
{
  Serial.begin(9600);   // Serial Communication Start
  Serial.println("****Recevier C****");   // Print Terminal name
  vw_set_ptt_inverted(true);  // Configure the "push to talk" polarity
  vw_setup(2000);   // initialize all the library
  vw_set_rx_pin(11);  // receiver pin is connected to DIGITAL pin 11
  vw_rx_start();  // Activate the receiver process
}
void loop()
{
  String ch = "";
  String check = "P3 push id pressed";
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen))
  {
    for ( i = 0; i < buflen; i++)
    {
      ch = ch + char(buf[i]);
    }
  }
  if(ch.equals(check))  // check P3 string 
  {
    Serial.println(ch);
  }
}
