
  Serial.begin (9600);
}

void loop() {
  pinMode(distPin, OUTPUT);
  digitalWrite(distPin, LOW);
  delayMicroseconds(5);
  digitalWrite(distPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(distPin, LOW);

  delayMicroseconds(10);
  pinMode(distPin, INPUT);
  duration = pulseIn(distPin, HIGH);

  inches = (duration/2) / 74;

  Serial.print(inches);
  Serial.print("in, ");
  Serial.println();

  delay(25 );
}
