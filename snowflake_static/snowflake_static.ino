int pin[14] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13}; 

void setup() 
{
  for (int i = 0; i < 14; i++)
    {
      pinMode(i, OUTPUT);
    }
}

void loop() {
  for (int i = 0; i < 14; i++)
    {
      digitalWrite(i, HIGH);
    }
}
