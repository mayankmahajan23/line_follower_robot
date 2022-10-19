void setup () {
Serial.begin(9600);
}

void loop () {
  while (true) {
    Serial.print("hey");
    while (true) {
      break;
    }
  }
  delay(1000);
  Serial.print("hi");
}
