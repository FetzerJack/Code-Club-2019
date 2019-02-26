int distPin = 9;    // Trigger
int distPin2 = 10;    // Trigger for Distance Sensor 2  
int distPin3 = 11;
int distPin4 = 12; 
int distPin5 = 13;
int score;
long duration, inches, duration2, inches2, duration3, inches3, duration4, inches4, duration5, inches5;    //Creats Variables for output data

void hole1(){
  
  digitalWrite(distPin, LOW);
  delayMicroseconds(5);
  digitalWrite(distPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(distPin, LOW);
  delayMicroseconds(10);
  pinMode(distPin, INPUT);
  duration = pulseIn(distPin, HIGH);
  inches = (duration/2) / 74;
  pinMode(distPin, OUTPUT);
}

void hole2(){
  
  digitalWrite(distPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(distPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(distPin2, LOW);
  delayMicroseconds(10);
  pinMode(distPin2, INPUT);
  duration2 = pulseIn(distPin2, HIGH);
  inches2 = (duration2/2) / 74;
  pinMode(distPin2, OUTPUT);
}

void hole3(){
  
  digitalWrite(distPin3, LOW);
  delayMicroseconds(5);
  digitalWrite(distPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(distPin3, LOW);
  delayMicroseconds(10);
  pinMode(distPin3, INPUT);
  duration3 = pulseIn(distPin3, HIGH);
  inches3 = (duration3/2) / 74;
  pinMode(distPin3, OUTPUT);
}

void hole4(){
  
  digitalWrite(distPin4, LOW);
  delayMicroseconds(5);
  digitalWrite(distPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(distPin4, LOW);
  delayMicroseconds(10);
  pinMode(distPin4, INPUT);
  duration4 = pulseIn(distPin4, HIGH);
  inches4 = (duration4/2) / 74;
  pinMode(distPin4, OUTPUT);
}

void hole5(){
  
  digitalWrite(distPin5, LOW);
  delayMicroseconds(5);
  digitalWrite(distPin5, HIGH);
  delayMicroseconds(10);
  digitalWrite(distPin5, LOW);
  delayMicroseconds(10);
  pinMode(distPin5, INPUT);
  duration5 = pulseIn(distPin5, HIGH);
  inches5 = (duration5/2) / 74;
}
 
void setup() {
  Serial.begin (9600);
}
 
void loop() {
  hole1();
  hole2();
  hole3();
  hole4();
  hole5();
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(inches2);
  Serial.print("in, ");
  Serial.print(inches3);
  Serial.print("in, ");
  Serial.print(inches4);
  Serial.print("in, ");
  Serial.print(inches5);
  Serial.print("in, ");
  Serial.println();
  
}
