int iringeffect;
int oringeffect;
int inout;
int numLights = 5;
int c = 7;
int inner[5] = {2, 3, 4, 5, 6};
int outer[5] = {8, 9, 10, 11, 12};
String x;
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
    char x = Serial.read();  //gets one byte from serial buffer
    if (x == ',') {
      Serial.println("testsdfasdfdsf");
      readString=""; //clears variable for new input      
     }  



  
  if (iringeffect == 1){
      ieffect();
  }

  if (oringeffect == 1){
      oeffect();
  }

    if (inout == 1){
      inouteffect();    
  }
  
if (Serial.available()>0) // Checks for a character in the serial monitor
{
    char x = Serial.read();  //gets one byte from serial buffer
    if (x = "ring on") {
      for (int i = 0; i < numLights; i++) 
        digitalWrite(outer[i], HIGH);
      x = "";
      Serial.println(x);
    }
    if (x == "ring off") {
      for (int i = 0; i < numLights; i++) 
        digitalWrite(outer[i], LOW);
      iringeffect = 0;
      Serial.println(x);
      x = "";
    }
    if (x == "center on") {
      digitalWrite(c, HIGH);
      Serial.println();
    }
    if (x == "center off") {
      digitalWrite(c, LOW);
    }
    if (x == "ring inner on") {
      iringeffect = 1;
    }
    if (x == "ring inner off") {
      iringeffect = 0;
      for (int i = 0; i < numLights; i++) 
            digitalWrite(inner[i], LOW);
    }
    if (x == "ring outer on") {
      oringeffect = 1;
    }
    if (x == "ring outer off") {
      oringeffect = 0;
      for (int i = 0; i < numLights; i++) {
        digitalWrite(outer[i], LOW);
      }
    }
    if (x == "inout on") {
      inout = 1;
    }
    if (x == "inout off") {
      inout = 0;
      for(int i = 2; i < 12; i++)
        digitalWrite(i, LOW);
      }
     if (x == "all off") {    
      for(int i = 2; i < 12; i++)
        digitalWrite(i, LOW);
      iringeffect = 0;
      oringeffect = 0;
      inout = 0;
     }
     if (x == "all on") {
      for(int i = 2; i < 12; i++)
        digitalWrite(i, HIGH);
     }
         else {     
      readString += x; //makes the string readString
    }
  } 
  }
  
