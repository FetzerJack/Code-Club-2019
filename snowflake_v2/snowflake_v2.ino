#include "IRremote.h"
//#define NUM(a) (sizeof(a) / sizeof(*a));
int numLights = 6;
int receiver = 13;
int iRingEffect, oRingEffect, aRingEffect; // <=== Check out the Camel Case !!!!
int inOut;

//Current arrangement: center = 7, inner ring = 1,2,3,4,5,6, outer ring = 8,9,10,11,12,0, IR remote = 13
int c = 7;
int inner[6] = {1, 2, 3, 4, 5, 6};
int outer[6] = {8, 9, 10, 11, 12, 0};

IRrecv irrecv(receiver);
decode_results results;

void setup() {
   pinMode(c, OUTPUT);
   for (int i = 0; i < numLights; i++)
      pinMode(inner[i], OUTPUT);
   for (int i = 0; i < numLights; i++) 
      pinMode(outer[i], OUTPUT);

   pinMode(13, INPUT);
   iRingEffect = 0;
   oRingEffect = 0;
   inOut = 0;
   irrecv.enableIRIn();
}



//In out effect will...
void inOutEffect()  
{
  digitalWrite(c, HIGH);
  for (int i = 0; i < numLights; i++)
    digitalWrite(inner[i], LOW);
  delay(350);

  for (int i = 0; i < numLights; i++)
     digitalWrite(outer[i], HIGH); 
  delay(350);

  for (int i = 0; i < numLights; i++)
     digitalWrite(inner[i], HIGH);
  delay(350);

  for (int i = 0; i < numLights; i++)
     digitalWrite(outer[i], LOW);
  delay(350);
} //End inOutEffect



//oEffect will....
void oEffect() 
{
   int len = numLights;

   for (int i = 0; i < numLights; i++)
   {
      digitalWrite(inner[i], HIGH);
      delay(50);
      digitalWrite(inner[(i + len-1) % len], LOW);
      delay(50);
   }
} //End oEffect



//iEffect will...
void iEffect() 
{
   int len = numLights;

   for (int i = 0; i < numLights; i++)
   {
      digitalWrite(outer[i], HIGH);
      delay(50);
      digitalWrite(outer[(i + len-1) % len], LOW);
      delay(50);
   }
} //End iEffect



//aEffect will...
void aEffect() 
{
   int len = numLights;

   digitalWrite(c, HIGH);
   for (int i = 0; i < numLights; i++)
   {
      digitalWrite(outer[i], HIGH);
      digitalWrite(inner[i], HIGH);
      delay(50);
      digitalWrite(outer[(i + len-1) % len], LOW);
      digitalWrite(inner[(i + len-1) % len], LOW);
      delay(50);
   }
}


//allOff will check each of the pins in the array that it is sent and return true if all are off, false otherwise
boolean allOff(int a[])
{
  boolean off = true;
  int i = 0;

  while (i < numLights && off)
      if (digitalRead(a[i])==HIGH)
          off = false;
  
  return off;
} //End allOff



//MAIN LOOP 
void loop() 
{
  if (iRingEffect == 1 && oRingEffect == 1) 
  {
    iRingEffect = 0;
    oRingEffect = 0;
    aRingEffect = 1;
  }

  if (iRingEffect == 1) 
    iEffect();

  if (oRingEffect == 1) 
    oEffect();

  if (inOut == 1)
    inOutEffect();

  if (aRingEffect == 1) 
    aEffect();


  if (irrecv.decode(&results)) 
  {
      if (results.value == 0xFF18E7)  // #2 Inner Ring Static <== what does the user press for code 0xFF18E7????
      {
         if (digitalRead(outer[0])==LOW)
         {
            for (int i = 0; i < numLights; i++)
               digitalWrite(outer[i], HIGH);
         }
         else //digitalRead(outer[0])==HIGH
         {
            for (int i = 0; i < numLights; i++)
               digitalWrite(outer[i], LOW);
            iRingEffect = 0;
         }
         delay(500);
      } 
      else if (results.value == 0xFF7A85)  // #3 Outer Ring Static
      {
         if (digitalRead(inner[5])==LOW && digitalRead(inner[1])==LOW)
         {
            for (int i = 0; i < numLights; i++)
               digitalWrite(inner[i], HIGH);
         }
         else if (digitalRead(inner[5])==HIGH && digitalRead(inner[1])==HIGH)
         {
            for (int i = 0; i < numLights; i++)
              digitalWrite(inner[i], LOW);

            oRingEffect = 0;
         }
         delay(250);
       }
      else if (results.value == 0xFF30CF)  // #1 Center Static
      { 
         if (digitalRead(c) == LOW)
            digitalWrite(c, HIGH);
         else
            digitalWrite(c, LOW);

         delay(250);
       }
       else if (results.value == 0xFF10EF)  // #4 Inner Ring Dynamic
       {
           if (iRingEffect==0)
              iRingEffect = 1;
           else
           {
              iRingEffect = 0;
              for (int i = 0; i < numLights; i++) 
                digitalWrite(outer[i], LOW);
           }
           delay(250);
       }
       else if (results.value == 0xFF38C7)  // #5 Outer Ring Dynamic
       {
          if (oRingEffect == 0)
            oRingEffect = 1;
          else
          {
             for (int i = 0; i < numLights; i++) 
             {
             digitalWrite(inner[i], LOW);
             digitalWrite(outer[i], LOW);
             }
          }
          delay(250);
       }
       else if (results.value == 0xFF5AA5)  // #6 All Ring Effect
       {
           if (aRingEffect == 0)
               aRingEffect = 1;
           else
           {
              aRingEffect = 0;

              digitalWrite(c, LOW);
              for (int i = 0; i < numLights; i++) 
              {
                digitalWrite(inner[i], LOW);
                digitalWrite(outer[i], LOW);
              }
           }
           delay(250);
        }
        else if (results.value == 0xFF6897)  // #0 InOut Effect
        {
           if (inOut == 0)
               inOut = 1;
           else
           {
              inOut = 0;
              digitalWrite(c, LOW);
              for (int i = 0; i < numLights; i++) 
              {
                digitalWrite(inner[i], LOW);
                digitalWrite(outer[i], LOW);
              }
           }
           delay(250);
        }
        else if (results.value==0xFFA25D)
        {
           if (allOff(inner) && allOff(outer))
           {
              digitalWrite(c, LOW);
              for (int i = 0; i < numLights; i++) 
              {
                digitalWrite(inner[i], LOW);
                digitalWrite(outer[i], LOW);
              }
              iRingEffect = 0;
              oRingEffect = 0;
              aRingEffect = 0; 
              inOut = 0;
              delay(500);
          }
          else
          {
              digitalWrite(c, LOW);
              for (int i = 0; i < numLights; i++) 
              {
                digitalWrite(inner[i], HIGH);
                digitalWrite(outer[i], HIGH);
              }
          }
       }
   }
   results.value = 0x000000;
   irrecv.resume();
 }



//void write(int[] a, int interDel, int afterDel, value)
//{
    


//}
