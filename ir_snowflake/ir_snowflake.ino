#include "IRremote.h"

int receiver = 13;
int iringeffect;
int oringeffect;
int aringeffect;
int inout;

IRrecv irrecv(receiver);
decode_results results;

void setup() 
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
  iringeffect = 0;
  oringeffect = 0;
  inout = 0;
  irrecv.enableIRIn();
}

void inouteffect() 
{
  digitalWrite(7, HIGH);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(350);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(0, HIGH);
  digitalWrite(7, LOW);
  delay(350);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(0, LOW);
  delay(350);
}

void oeffect() 
{
        digitalWrite(1, HIGH);
        delay(50);
        digitalWrite(6, LOW);
        delay(50);
        digitalWrite(2, HIGH);
        delay(50);
        digitalWrite(1, LOW);
        delay(50);
        digitalWrite(3, HIGH);
        delay(50);
        digitalWrite(2, LOW);
        delay(50);
        digitalWrite(4, HIGH);
        delay(50);
        digitalWrite(3, LOW);
        delay(50);
        digitalWrite(5, HIGH);
        delay(50);
        digitalWrite(4, LOW);
        delay(50);
        digitalWrite(6, HIGH);
        delay(50);
        digitalWrite(5, LOW);
        delay(50);
}

void ieffect() 
{
        digitalWrite(8, HIGH);
        delay(50);
        digitalWrite(0, LOW);
        delay(50);
        digitalWrite(9, HIGH);
        delay(50);
        digitalWrite(8, LOW);
        delay(50);
        digitalWrite(10, HIGH);
        delay(50);
        digitalWrite(9, LOW);
        delay(50);
        digitalWrite(11, HIGH);
        delay(50);
        digitalWrite(10, LOW);
        delay(50);
        digitalWrite(12, HIGH);
        delay(50);
        digitalWrite(11, LOW);
        delay(50);
        digitalWrite(0, HIGH);
        delay(50);
        digitalWrite(12, LOW);
        delay(50);
}

void aeffect() 
{
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(1, HIGH);
        delay(50);
        digitalWrite(0, LOW);
        digitalWrite(6, LOW);
        delay(50);
        digitalWrite(9, HIGH);
        digitalWrite(2, HIGH);
        delay(50);
        digitalWrite(8, LOW);
        digitalWrite(1, LOW);
        delay(50);
        digitalWrite(10, HIGH);
        digitalWrite(3, HIGH);
        delay(50);
        digitalWrite(9, LOW);
        digitalWrite(2, LOW);
        delay(50);
        digitalWrite(11, HIGH);
        digitalWrite(4, HIGH);
        delay(50);
        digitalWrite(10, LOW);
        digitalWrite(3, LOW);
        delay(50);
        digitalWrite(12, HIGH);
        digitalWrite(5, HIGH);
        delay(50);
        digitalWrite(11, LOW);
        digitalWrite(4, LOW);
        delay(50);
        digitalWrite(0, HIGH);
        digitalWrite(6, HIGH);
        delay(50);
        digitalWrite(12, LOW);
        digitalWrite(5, LOW);
        delay(50);
}

void loop() 
{
  if (iringeffect == 1 && oringeffect == 1) 
  {
     iringeffect = 0;
     oringeffect = 0;
     aringeffect = 1;
  }
  if (iringeffect == 1) 
  {
     ieffect();
  }

  if (oringeffect == 1) 
  {
     oeffect();
  }

  if (inout == 1) 
  {
     inouteffect();
  }

  if (aringeffect == 1) 
  {
     aeffect();
  }
  if (irrecv.decode(&results)) 
  {
    if (results.value == 0xFF18E7 && digitalRead(8) == LOW) // #2 Inner Ring Static
    {
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(0, HIGH);
        results.value = 0x000000;
        delay(500);
    }
    else if (results.value == 0xFF18E7 && digitalRead(8) == HIGH) 
    {
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(0, LOW);
        iringeffect = 0;
        results.value = 0x000000;
        delay(500);
    }
    else if (results.value == 0xFF7A85 && digitalRead(6) == LOW && digitalRead(2) == LOW) // #3 Outer Ring Static
    {
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF7A85 && digitalRead(6) == HIGH && digitalRead(2) == HIGH) 
    {
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        oringeffect = 0;
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF30CF && digitalRead(7) == LOW) // #1 Center Static
    {
        digitalWrite(7, HIGH);
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF30CF && digitalRead(7) == HIGH) 
    {
        digitalWrite(7, LOW);
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF10EF && iringeffect == 0) // #4 Inner Ring Dynamic
    {
        iringeffect = 1;
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF10EF && iringeffect == 1) 
    {
        iringeffect = 0;
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(0, LOW);
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF38C7 && oringeffect == 0) // #5 Outer Ring Dynamic
    {
        oringeffect = 1;
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF38C7 && oringeffect == 1) 
    {
        oringeffect = 0;
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(0, LOW);
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF5AA5 && aringeffect == 0) // #6 All Ring Effect
    {
        aringeffect = 1;
        delay(250);
    }
    else if (results.value == 0xFF5AA5 && aringeffect == 1) 
    {
        aringeffect = 0;
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(0, LOW);
        delay(250);
    }
    else if (results.value == 0xFF6897 && inout == 0) // #0 InOut Effect
    {
        inout = 1;
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF6897 && inout == 1) 
    {
        inout = 0;
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(0, LOW);
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFFA25D && digitalRead(1) == HIGH  || digitalRead(2) == HIGH || digitalRead(3) == HIGH || digitalRead(4) == HIGH || digitalRead(5) == HIGH || digitalRead(6) == HIGH || digitalRead(0) == HIGH || digitalRead(8) == HIGH || digitalRead(7) == HIGH) // All Off
    {
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(0, LOW);
        iringeffect = 0;
        oringeffect = 0;
        aringeffect = 0;
        inout = 0;
        results.value = 0x000000;
        delay(500);
    }
    else if (results.value == 0xFFA25D) // All On
    {
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(0, HIGH);
        results.value = 0x000000;
    }
    results.value = 0x000000;
    irrecv.resume();
  }
}
