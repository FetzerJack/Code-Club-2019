int iringeffect;
int oringeffect;
int inout;
String readString;

void setup() {
  Serial.begin(9600);
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
  Serial.println("Snowflake v2.04 Initalize...");
  iringeffect = 0;
  oringeffect = 0;
  inout = 0;
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

  while (Serial.available()) {
    readString += Serial.read(); 
  }

  if (readString.length() > 0) {
    Serial.println(readString);

    if (readString == "ring on")     
    {
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(13, HIGH);
      
    }
    if (readString == "ring off")
    {
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        iringeffect = 0;
    }
        if (readString == "center on")
    {
      digitalWrite(7, HIGH);
    }
        if (readString == "center off")
    {
      digitalWrite(7, LOW);

    }
        if (readString == "ring inner on")     
    {
        iringeffect = 1;
    }
        if (readString == "ring inner off")     
    {
        iringeffect = 0;
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
    }
        if (readString == "ring outer on")     
    {
        oringeffect = 1;
    }
        if (readString == "ring outer off")     
    {
        oringeffect = 0;
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
    }
        if (readString == "inout on")     
    {
        inout = 1;
    }
        if (readString == "inout off")     
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
    }
        if (readString == "all off")
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
    }
        if (readString == "all on")
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
    }
    }
    
    readString="";
  } 
