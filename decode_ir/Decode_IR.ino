#include <IRremote.h>

int IRpin = 13;
IRrecv irrecv(IRpin);
decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decoder");
  irrecv.enableIRIn();
}

void loop() 
{
  if (irrecv.decode(&results)) 
    {
      Serial.println(results.value, HEX);
      irrecv.resume();
    }
  
  
}
