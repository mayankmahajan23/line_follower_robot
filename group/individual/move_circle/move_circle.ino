void forward (float);
void backward (float);
void clockwise (float);
void anti_clockwise (float);
void right_forward (float);
void left_forward (float);
void righ_tbackward (float);
void left_backward (float);

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  forward(0.05);
  right_forward(0.1);
}

void forward (float x) {
  digitalWrite(5, HIGH);
  digitalWrite(8, HIGH);
  delay(x*1000);
  digitalWrite(5, LOW);
  digitalWrite(8, LOW);
  Serial.println("done");
}
void backward (float x) {
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(x*1000);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  Serial.println("done");
}
void clockwise (float x) {
  digitalWrite(8, HIGH);
  digitalWrite(6, HIGH);
  delay(x*1000);
  digitalWrite(8, LOW);
  digitalWrite(6, LOW);
  Serial.println("done");
}
void anti_clockwise(float x) {
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
  delay(x*1000);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  Serial.println("done");
}
void right_forward(float x) {
  digitalWrite(8, HIGH);
  delay(x*1000);
  digitalWrite(8, LOW);
  Serial.println("done");
}
void left_forward(float x) {
  digitalWrite(5, HIGH);
  delay(x*1000);
  digitalWrite(5, LOW);
  Serial.println("done");
}
void right_backward(float x) {
  digitalWrite(7, HIGH);
  delay(x*1000);
  digitalWrite(7, LOW);
  Serial.println("done");
}
void left_backward(float x) {
  digitalWrite(6, HIGH);
  delay(x*1000);
  digitalWrite(6, LOW);
  Serial.println("done");
}
