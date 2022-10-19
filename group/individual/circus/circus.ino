int x = 13;
int y = 8;

void setup() {
  Serial.begin(9600);
  for(int i=x; i>=y; i--) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for(int i=x; i>=y; i--) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
  }
}
