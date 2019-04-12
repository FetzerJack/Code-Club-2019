int iringeffect;
int oringeffect;
int inout;
int numLights = 5;
int c = 7;
int inner[5] = {8, 9, 10, 11, 12};
int outer[5] = {2, 3, 4, 5, 6};
char x;
String readString;


void setup() {
  Serial.begin(9600);
  pinMode(c, OUTPUT);
  for (int i = 0; i < numLights; i++)
    pinMode(inner[i], OUTPUT);
  for (int i = 0; i < numLights; i++)
    pinMode(outer[i], OUTPUT);
  Serial.println("Snowflake v2.04 Initalize...");
  iringeffect = 0;
  oringeffect = 0;
  inout = 0;
}

void inouteffect()
{
  digitalWrite(c, HIGH);
  for (int i = 0; i < numLights; i++)
    digitalWrite(inner[i], LOW);
  delay(350);
  
  for (int i = 0; i < numLights; i++)
     digitalWrite(outer[i], HIGH);
  digitalWrite(c, LOW);
  delay(350);
 
  for (int i = 0; i < numLights; i++)
     digitalWrite(inner[i], HIGH);
  for (int i = 0; i < numLights; i++)
     digitalWrite(outer[i], LOW);
  delay(350);
} //End inouteffect

void oeffect(){
  for (int i = 0; i < numLights; i++) {
    digitalWrite(inner[i], HIGH);
    delay(50);
    digitalWrite(inner[(i + numLights-1) % numLights], LOW);
    delay(50);
  }
} //End oeffect

void ieffect(){
  for (int i = 0; i < numLights; i++) {
    digitalWrite(outer[i], HIGH);
    delay(50);
    digitalWrite(outer[(i + numLights-1) % numLights], LOW);
    delay(50);
  }
} //End ieffect

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
  
  while (Serial.available())
  {
    delay(3);  
    char x = Serial.read();
    readString += x;
    Serial.println(readString);
  }
  if (readString.length() > 0)
  {
  Serial.println("*" + readString + "*");
  readString.trim();
  Serial.println("*" + readString + "*");
  }
  if (readString.length() >0) {
    if (readString == "static outer on") {
      for (int i = 0; i < numLights; i++) 
        digitalWrite(inner[i], HIGH);
      Serial.println(readString);
    }
    else if (readString == "static outer off") {
      for (int i = 0; i < numLights; i++) 
        digitalWrite(inner[i], LOW);
      iringeffect = 0;
      Serial.println(readString);
    }
    if (readString == "static inner on") {
      for (int i = 0; i < numLights; i++) 
        digitalWrite(outer[i], HIGH);
      Serial.println(readString);
    }
    else if (readString == "static inner off") {
      for (int i = 0; i < numLights; i++) 
        digitalWrite(outer[i], LOW);
      iringeffect = 0;
      Serial.println(readString);
    }
    else if (readString == "static center on") {
      digitalWrite(c, HIGH);
      Serial.println(readString);
    }
    else if (readString == "static center off") {
      digitalWrite(c, LOW);
      Serial.println(readString);
    }
    else if (readString == "effect inner on") {
      iringeffect = 1;
      Serial.println(readString);
    }
    else if (readString == "effect inner off") {
      iringeffect = 0;
      for (int i = 0; i < numLights; i++) 
            digitalWrite(inner[i], LOW);
      Serial.println(readString);
    }
    else if (readString == "effect outer on") {
      oringeffect = 1;
      Serial.println(readString);
    }
    else if (readString == "effect outer off") {
      oringeffect = 0;
      for (int i = 0; i < numLights; i++) {
        digitalWrite(outer[i], LOW);
      Serial.println(readString);
      }
    }
    else if (readString == "inout on") {
      inout = 1;
      Serial.println(readString);
    }
    else if (readString == "inout off") {
      inout = 0;
      for(int i = 2; i < 13; i++)
        digitalWrite(i, LOW);
      Serial.println(readString);
      }
     else if (readString == "all off") {    
      for(int i = 2; i < 13; i++)
        digitalWrite(i, LOW);
      iringeffect = 0;
      oringeffect = 0;
      inout = 0;
      Serial.println(readString);
     }
     else if (readString == "all on") {
      for(int i = 2; i < 13; i++)
        digitalWrite(i, HIGH);
      Serial.println(readString);
     }
    readString = "";
  }
  } 
  
