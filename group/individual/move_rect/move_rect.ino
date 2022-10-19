void forward (int);
void backward (int);
void clockwise (int);
void anti_clockwise (int);
void right_forward (int);
void left_forward (int);
void righ_tbackward (int);
void left_backward (int);

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  forward(2);
  right_forward(4);
  forward(3);
  right_forward(4);
}

void forward (int x) {
  digitalWrite(5, HIGH);
  digitalWrite(8, HIGH);
  delay(x*1000);
  digitalWrite(5, LOW);
  digitalWrite(8, LOW);
  Serial.println("done");
}
void backward (int x) {
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(x*1000);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  Serial.println("done");
}
void clockwise (int x) {
  digitalWrite(8, HIGH);
  digitalWrite(6, HIGH);
  delay(x*1000);
  digitalWrite(8, LOW);
  digitalWrite(6, LOW);
  Serial.println("done");
}
void anti_clockwise(int x) {
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
  delay(x*1000);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  Serial.println("done");
}
void right_forward(int x) {
  digitalWrite(8, HIGH);
  delay(x*1000);
  digitalWrite(8, LOW);
  Serial.println("done");
}
void left_forward(int x) {
  digitalWrite(5, HIGH);
  delay(x*1000);
  digitalWrite(5, LOW);
  Serial.println("done");
}
void right_backward(int x) {
  digitalWrite(7, HIGH);
  delay(x*1000);
  digitalWrite(7, LOW);
  Serial.println("done");
}
void left_backward(int x) {
  digitalWrite(6, HIGH);
  delay(x*1000);
  digitalWrite(6, LOW);
  Serial.println("done");
}
