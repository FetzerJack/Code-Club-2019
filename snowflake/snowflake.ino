int iringeffect;
int oringeffect;
int inout;
String readString;
int numLights = 5;
int c = 7;
int inner[5] = {2, 3, 4, 5, 6};
int outer[5] = {8, 9, 10, 11, 12};

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
  

  
}

void oeffect(){
  for (int i = 0; i < numLights; i++) {
    digitalWrite(inner[i], HIGH);
    delay(50);
    digitalWrite(inner[(i + numLights-1) % numLights], LOW);
    delay(50);
  }
}

void ieffect(){
  for (int i = 0; i < numLights; i++) {
    digitalWrite(outer[i], HIGH);
    delay(50);
    digitalWrite(outer[(i + numLights-1) % numLights], LOW);
    delay(50);
  }
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

  while (Serial.available()) {
    readString += Serial.read(); 
  }

  if (readString.length() > 0) {
    Serial.println(readString);

    if (readString == "ring on") {
      for (int i = 0; i < numLights; i++) {
        digitalWrite(outer[i], HIGH);
    }
    if (readString == "ring off") {
      for (int i = 0; i < numLights; i++) {
        digitalWrite(outer[i], LOW);
      iringeffect = 0;
    }
        if (readString == "center on") {
          digitalWrite(c, HIGH);
      }
        if (readString == "center off") {
          digitalWrite(c, LOW);
        }
        if (readString == "ring inner on") {
          iringeffect = 1;
        }
        if (readString == "ring inner off") {
          iringeffect = 0;
          for (int i = 0; i < numLights; i++) {
            digitalWrite(inner[i], LOW);
          }
        }
        if (readString == "ring outer on") {
          oringeffect = 1;
        }
        if (readString == "ring outer off") {
          oringeffect = 0;
          for (int i = 0; i < numLights; i++) {
            digitalWrite(outer[i], LOW);
          }
        }
        if (readString == "inout on") {
          inout = 1;
        }
        if (readString == "inout off") {
          inout = 0;
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
        }
        if (readString == "all off") {    
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
          iringeffect = 0;
          oringeffect = 0;
          inout = 0;
        }
        if (readString == "all on") {
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
        }
    }
    
    readString="";
  } 
