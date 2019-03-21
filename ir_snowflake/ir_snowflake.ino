#include "IRremote.h"

int receiver = 13;
int iringeffect;
int oringeffect;
int aringeffect;
int inout;

//Current arrangement: center = 7, inner ring = 1,2,3,4,5,6, outer ring = 8,9,10,11,12,0, IR remote = 13
int c = 7;
int i1 = 1, i2 = 2, i3 = 3, i4 = 4, i5 = 5, i6 = 6;
int o1 = 8, o2 = 9, o3 = 10, o4 = 11, o5 = 12, o6 = 0;

IRrecv irrecv(receiver);
decode_results results;

void setup() {
  pinMode(o6, OUTPUT);
  pinMode(i1, OUTPUT);
  pinMode(i2, OUTPUT);
  pinMode(i3, OUTPUT);
  pinMode(i4, OUTPUT);
  pinMode(i5, OUTPUT);
  pinMode(i6, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(o1, OUTPUT);
  pinMode(o2, OUTPUT);
  pinMode(o3, OUTPUT);
  pinMode(o4, OUTPUT);
  pinMode(o5, OUTPUT);
  pinMode(13, INPUT);
  iringeffect = 0;
  oringeffect = 0;
  inout = 0;
  irrecv.enableIRIn();
}

void inouteffect() {
  digitalWrite(c, HIGH);
  digitalWrite(i1, LOW);
  digitalWrite(i2, LOW);
  digitalWrite(i3, LOW);
  digitalWrite(i4, LOW);
  digitalWrite(i5, LOW);
  digitalWrite(i6, LOW);
  delay(350);
  digitalWrite(o1, HIGH);
  digitalWrite(o2, HIGH);
  digitalWrite(o3, HIGH);
  digitalWrite(o4, HIGH);
  digitalWrite(o5, HIGH);
  digitalWrite(o6, HIGH);
  digitalWrite(c, LOW);
  delay(350);
  digitalWrite(i1, HIGH);
  digitalWrite(i2, HIGH);
  digitalWrite(i3, HIGH);
  digitalWrite(i4, HIGH);
  digitalWrite(i5, HIGH);
  digitalWrite(i6, HIGH);
  digitalWrite(o1, LOW);
  digitalWrite(o2, LOW);
  digitalWrite(o3, LOW);
  digitalWrite(o4, LOW);
  digitalWrite(o5, LOW);
  digitalWrite(o6, LOW);
  delay(350);
}

void oeffect() {
        digitalWrite(i1, HIGH);
        delay(50);
        digitalWrite(i6, LOW);
        delay(50);
        digitalWrite(i2, HIGH);
        delay(50);
        digitalWrite(i1, LOW);
        delay(50);
        digitalWrite(i3, HIGH);
        delay(50);
        digitalWrite(i2, LOW);
        delay(50);
        digitalWrite(i4, HIGH);
        delay(50);
        digitalWrite(i3, LOW);
        delay(50);
        digitalWrite(i5, HIGH);
        delay(50);
        digitalWrite(i4, LOW);
        delay(50);
        digitalWrite(i6, HIGH);
        delay(50);
        digitalWrite(i5, LOW);
        delay(50);
}

void ieffect() {
        digitalWrite(o1, HIGH);
        delay(50);
        digitalWrite(o6, LOW);
        delay(50);
        digitalWrite(o2, HIGH);
        delay(50);
        digitalWrite(o1, LOW);
        delay(50);
        digitalWrite(o3, HIGH);
        delay(50);
        digitalWrite(o2, LOW);
        delay(50);
        digitalWrite(o4, HIGH);
        delay(50);
        digitalWrite(o3, LOW);
        delay(50);
        digitalWrite(o5, HIGH);
        delay(50);
        digitalWrite(o4, LOW);
        delay(50);
        digitalWrite(o6, HIGH);
        delay(50);
        digitalWrite(o5, LOW);
        delay(50);
}

void aeffect() {
        digitalWrite(c, HIGH);
        digitalWrite(o1, HIGH);
        digitalWrite(i1, HIGH);
        delay(50);
        digitalWrite(o6, LOW);
        digitalWrite(i6, LOW);
        delay(50);
        digitalWrite(o2, HIGH);
        digitalWrite(i2, HIGH);
        delay(50);
        digitalWrite(o1, LOW);
        digitalWrite(i1, LOW);
        delay(50);
        digitalWrite(o3, HIGH);
        digitalWrite(i3, HIGH);
        delay(50);
        digitalWrite(o2, LOW);
        digitalWrite(i2, LOW);
        delay(50);
        digitalWrite(o4, HIGH);
        digitalWrite(i4, HIGH);
        delay(50);
        digitalWrite(o3, LOW);
        digitalWrite(i3, LOW);
        delay(50);
        digitalWrite(o5, HIGH);
        digitalWrite(i5, HIGH);
        delay(50);
        digitalWrite(o4, LOW);
        digitalWrite(i4, LOW);
        delay(50);
        digitalWrite(o6, HIGH);
        digitalWrite(i6, HIGH);
        delay(50);
        digitalWrite(o5, LOW);
        digitalWrite(i5, LOW);
        delay(50);
}

void loop() {
  if (iringeffect == 1 && oringeffect == 1) {
     iringeffect = 0;
     oringeffect = 0;
     aringeffect = 1;
  }
  if (iringeffect == 1) {
     ieffect();
  }

  if (oringeffect == 1) {
     oeffect();
  }

  if (inout == 1) {
     inouteffect();
  }

  if (aringeffect == 1) {
     aeffect();
  }
  if (irrecv.decode(&results)) {
    if (results.value == 0xFF18E7 && digitalRead(o1) == LOW) { // #2 Inner Ring Static
        digitalWrite(o1, HIGH);
        digitalWrite(o2, HIGH);
        digitalWrite(o3, HIGH);
        digitalWrite(o4, HIGH);
        digitalWrite(o5, HIGH);
        digitalWrite(o6, HIGH);
        results.value = 0x000000;
        delay(500);
    }
    else if (results.value == 0xFF18E7 && digitalRead(o1) == HIGH) {
        digitalWrite(o1, LOW);
        digitalWrite(o2, LOW);
        digitalWrite(o3, LOW);
        digitalWrite(o4, LOW);
        digitalWrite(o5, LOW);
        digitalWrite(o6, LOW);
        iringeffect = 0;
        results.value = 0x000000;
        delay(500);
    }
    else if (results.value == 0xFF7A85 && digitalRead(i6) == LOW && digitalRead(i2) == LOW) { // #3 Outer Ring Static
        digitalWrite(i1, HIGH);
        digitalWrite(i2, HIGH);
        digitalWrite(i3, HIGH);
        digitalWrite(i4, HIGH);
        digitalWrite(i5, HIGH);
        digitalWrite(i6, HIGH);
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF7A85 && digitalRead(i6) == HIGH && digitalRead(i2) == HIGH) {
        digitalWrite(i1, LOW);
        digitalWrite(i2, LOW);
        digitalWrite(i3, LOW);
        digitalWrite(i4, LOW);
        digitalWrite(i5, LOW);
        digitalWrite(i6, LOW);
        oringeffect = 0;
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF30CF && digitalRead(c) == LOW) { // #1 Center Static
        digitalWrite(c, HIGH);
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF30CF && digitalRead(c) == HIGH) {
        digitalWrite(c, LOW);
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF10EF && iringeffect == 0) { // #4 Inner Ring Dynamic
        iringeffect = 1;
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF10EF && iringeffect == 1) {
        iringeffect = 0;
        digitalWrite(o1, LOW);
        digitalWrite(o2, LOW);
        digitalWrite(o3, LOW);
        digitalWrite(o4, LOW);
        digitalWrite(o5, LOW);
        digitalWrite(o6, LOW);
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF38C7 && oringeffect == 0) { // #5 Outer Ring Dynamic
        oringeffect = 1;
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF38C7 && oringeffect == 1) {
        oringeffect = 0;
        digitalWrite(i1, LOW);
        digitalWrite(i2, LOW);
        digitalWrite(i3, LOW);
        digitalWrite(i4, LOW);
        digitalWrite(i5, LOW);
        digitalWrite(i6, LOW);
        digitalWrite(o1, LOW);
        digitalWrite(o2, LOW);
        digitalWrite(o3, LOW);
        digitalWrite(o4, LOW);
        digitalWrite(o5, LOW);
        digitalWrite(o6, LOW);
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF5AA5 && aringeffect == 0) { // #6 All Ring Effect
        aringeffect = 1;
        delay(250);
    }
    else if (results.value == 0xFF5AA5 && aringeffect == 1) {
        aringeffect = 0;
        digitalWrite(i1, LOW);
        digitalWrite(i2, LOW);
        digitalWrite(i3, LOW);
        digitalWrite(i4, LOW);
        digitalWrite(i5, LOW);
        digitalWrite(i6, LOW);
        digitalWrite(c, LOW);
        digitalWrite(o1, LOW);
        digitalWrite(o2, LOW);
        digitalWrite(o3, LOW);
        digitalWrite(o4, LOW);
        digitalWrite(o5, LOW);
        digitalWrite(o6, LOW);
        delay(250);
    }
    else if (results.value == 0xFF6897 && inout == 0) { // #0 InOut Effect
        inout = 1;
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFF6897 && inout == 1) {
        inout = 0;
        digitalWrite(i1, LOW);
        digitalWrite(i2, LOW);
        digitalWrite(i3, LOW);
        digitalWrite(i4, LOW);
        digitalWrite(i5, LOW);
        digitalWrite(i6, LOW);
        digitalWrite(c, LOW);
        digitalWrite(o1, LOW);
        digitalWrite(o2, LOW);
        digitalWrite(o3, LOW);
        digitalWrite(o4, LOW);
        digitalWrite(o5, LOW);
        digitalWrite(o6, LOW);
        results.value = 0x000000;
        delay(250);
    }
    else if (results.value == 0xFFA25D && digitalRead(i1) == HIGH  || digitalRead(i2) == HIGH || digitalRead(i3) == HIGH || digitalRead(i4) == HIGH || digitalRead(i5) == HIGH || digitalRead(i6) == HIGH || digitalRead(o6) == HIGH || digitalRead(o1) == HIGH || digitalRead(c) == HIGH) { // All Off
        digitalWrite(i1, LOW);
        digitalWrite(i2, LOW);
        digitalWrite(i3, LOW);
        digitalWrite(i4, LOW);
        digitalWrite(i5, LOW);
        digitalWrite(i6, LOW);
        digitalWrite(c, LOW);
        digitalWrite(o1, LOW);
        digitalWrite(o2, LOW);
        digitalWrite(o3, LOW);
        digitalWrite(o4, LOW);
        digitalWrite(o5, LOW);
        digitalWrite(o6, LOW);
        iringeffect = 0;
        oringeffect = 0;
        aringeffect = 0;
        inout = 0;
        results.value = 0x000000;
        delay(500);
    }
    else if (results.value == 0xFFA25D) { // All On
        digitalWrite(i1, HIGH);
        digitalWrite(i2, HIGH);
        digitalWrite(i3, HIGH);
        digitalWrite(i4, HIGH);
        digitalWrite(i5, HIGH);
        digitalWrite(i6, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(o1, HIGH);
        digitalWrite(o2, HIGH);
        digitalWrite(o3, HIGH);
        digitalWrite(o4, HIGH);
        digitalWrite(o5, HIGH);
        digitalWrite(o6, HIGH);
        results.value = 0x000000;
    }
    results.value = 0x000000;
    irrecv.resume();
  }
}
