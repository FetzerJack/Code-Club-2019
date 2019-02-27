const int transistorPin = 9;    // connected to the base of the transistor
 
 void setup() {
   // set  the transistor pin as output:
   pinMode(13, OUTPUT);
 }
 
 void loop() {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
 }


 
