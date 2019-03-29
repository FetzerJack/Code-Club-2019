String hello[5] = {"H","E","L","L","O"};
int pins[5] = {10,11,12,12,13};
#define NUM(x) (sizeof(x)/sizeof(x[0]))

void setup() 
{
  for (int i = 0; i < NUM(hello); i++)
    pinMode(pins[i], OUTPUT);
  Serial.begin(9600);
  
}

void loop() 
{ 
  for (int i = 0; i < NUM(hello); i++)
  {
    delay(250);
    Serial.print(hello[i]);
    digitalWrite(pins[i], HIGH);
    delay(250);
    digitalWrite(pins[i], LOW);
    if (i == 4)
      Serial.println();
  }
  
}
