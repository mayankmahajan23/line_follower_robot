void setup() {
  Serial.begin(9600);
  digitalWrite(13, HIGH);
}

void loop() {
  if (Serial.available()) {
    Serial.read();
    
    Serial.println(sizeof(int));
    Serial.println(sizeof(short int));
    Serial.println(sizeof(long int));
    Serial.println(sizeof(byte));
    Serial.println(sizeof(short));
    Serial.println(sizeof(long));
    Serial.println(sizeof(unsigned int));
    Serial.println(sizeof(unsigned long int));
    Serial.println(sizeof(char));

    Serial.println();
  }
}
