void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char n = Serial.peek();
    Serial.print(n); //character
    Serial.print("\n");
    Serial.print(n, DEC); //ascii value
    Serial.print("\n");
    Serial.println(n, HEX); //hexadecimal value
    Serial.println(n, OCT); //ln line chod deta hai
    Serial.println(n, BIN);
    Serial.println();
    
    while (Serial.available() > 0) {
      char x = Serial.read();
      Serial.println(x);
    }
  }
}
