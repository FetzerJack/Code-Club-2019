#include "IRremote.h"

int receiver = 13;
String readString;

IRrecv irrecv(receiver);
decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Translator"); 
  irrecv.enableIRIn();
}

void loop()
{
  while (Serial.available()) 
  {  
    char c = Serial.read();
    readString += c; 
  }

  if (readString.length() > 0)
  {
    if (readString == "reset")
    {
      Serial.println("RESET...");
      readString = "";
    }
    }
  
  
  if (irrecv.decode(&results))
  {
    translateIR(); 
    irrecv.resume();
  }  
}

void translateIR()
{

  switch(results.value)
  {
  case 0xFF30CF: Serial.println(" 1");    break;
  case 0xFF18E7: Serial.println(" 2");    break;
  case 0xFF7A85: Serial.println(" 3");    break;
  case 0xFF10EF: Serial.println(" 4");    break;
  case 0xFF38C7: Serial.println(" 5");    break;
  case 0xFF5AA5: Serial.println(" 6");    break;
  case 0xFF42BD: Serial.println(" 7");    break;
  case 0xFF4AB5: Serial.println(" 8");    break;
  case 0xFF52AD: Serial.println(" 9");    break;
  case 0xFF6897: Serial.println(" 0");    break;
  case 0xFFA25D: Serial.println("PWR");   break;
  case 0xFF629D: Serial.println("VOL+");   break;
  case 0xFFA857: Serial.println("VOL-");   break;
  case 0xFF22DD: Serial.println("BACK");   break;
  case 0xFFC23D: Serial.println("FORWARD");   break;
  case 0xFF02FD: Serial.println("PLAY/PAUSE");   break;
  case 0xFF906F: Serial.println("UP");   break;
  case 0xFFE01F: Serial.println("DOWN");   break;
  case 0xFFE21D: Serial.println("STOP");   break;
  case 0xFF9867: Serial.println("EQ");   break;
  case 0xFFB04F: Serial.println("REPEAT");   break;
                      
  }

  delay(50);


} 
