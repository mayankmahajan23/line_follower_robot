void setup() {
  Serial.begin(9600);
  digitalWrite(13, HIGH);
}

void loop() {
  if ( Serial.available() > 0 ) {
    int n = Serial.parseInt();
    Serial.println(n);

    while ( Serial.available() ) {
      char x = Serial.read();
      Serial.println(x);
    }
  }
}

//while ( Serial.available() ) : works too
//int : 2 bytes : 0 to 32767 and -32768 to 0
