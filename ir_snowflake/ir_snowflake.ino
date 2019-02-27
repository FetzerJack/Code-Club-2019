#include "IRremote.h"

int receiver = 0;
int iringeffect;
int oringeffect;
int inout;

IRrecv irrecv(receiver);
decode_results results;

void setup() {
  pinMode(0, INPUT);
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
  pinMode(13, OUTPUT);
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
  digitalWrite(13, HIGH);
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
  digitalWrite(13, LOW);
  delay(350);



}

void oeffect(){
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

void ieffect(){
        digitalWrite(8, HIGH);
        delay(50);
        digitalWrite(13, LOW);
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
        digitalWrite(13, HIGH);
        delay(50);
        digitalWrite(12, LOW);
        delay(50);
}

void loop() {
  if (iringeffect == 1){
      ieffect();

  }

  if (oringeffect == 1){
      oeffect();

  }

    if (inout == 1){
      inouteffect();

  }

    if (results.value == 0xFF30CF)
    {
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(13, HIGH);
        delay(750);
    }
    if (results.value == 0xFF30CF && digitalRead(8 == HIGH) && digitalRead(9 == HIGH))
    {
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        iringeffect = 0;
        delay(750);
    }
    if (results.value == 0xFF18E7)
    {
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        delay(1000);

    }
    if (results.value == 0xFF18E7 && digitalRead(6 == HIGH) && digitalRead(2 == HIGH))
    {
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        oringeffect = 0;
        delay(1000);
    }
        if (results.value == 0xFF02FD)
    {
      digitalWrite(7, HIGH);
      delay(1000);
    }
    if (results.value == 0xFF02FD && digitalRead(7 == HIGH))
    {
      digitalWrite(7, LOW);
      delay(1000);

    }
        if (results.value == 0xFF629D)
    {
        iringeffect = 1;
        delay(1000);
    }
        if (results.value == 0xFF629D && iringeffect == 1)
    {
        iringeffect = 0;
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        delay(1000);
    }
        if (results.value == 0xFFA857 && oringeffect == 0)
    {
        oringeffect = 1;
        delay(1000);
    }
        if (results.value == 0xFFA857 && oringeffect == 1)
    {
        oringeffect = 0;
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        delay(1000);
    }
        if (results.value == 0xFF7A85)
    {
        inout = 1;
        delay(1000);
    }
        if (results.value == 0xFF7A85 && inout == 1)
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
        digitalWrite(13, LOW);
        delay(1000);
    }
        if (results.value == 0xFFA25D && digitalRead(1) == HIGH && digitalRead(13) == HIGH)
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
        digitalWrite(13, LOW);
        iringeffect = 0;
        oringeffect = 0;
        inout = 0;
        delay(1000);
    }
         if (results.value == 0xFFA25D && digitalRead(1) == LOW && digitalRead(13) == LOW)
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
        digitalWrite(13, HIGH);
        delay(1000);
    }
    results.value = 0x000000;
    irrecv.resume();
  }
