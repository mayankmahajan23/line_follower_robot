void forward (int);
void backward (int);
void clockwise (int);
void anti_clockwise (int);
void right_forward (int);
void left_forward (int);
void righ_tbackward (int);
void left_backward (int);

int pin_rightf = 5;
int pin_rightb = 6;
int pin_leftb = 7;
int pin_leftf = 8;

void setup() {
  for (int i = 5; i<=8; i++)
    pinMode(i, OUTPUT);
    
  Serial.begin(9600);
}

void loop() {
  if ( Serial.available() > 0 ) {
    char c = Serial.read();
    int n = Serial.parseInt();
    switch(c) {
      case 'f' :  forward(n);
                  break;
      case 'b' :  backward(n);
                  break;
      case 'c' :  clockwise(n);
                  break;
      case 'a' :  anti_clockwise(n);
                  break;
      case 'r' :  right_forward(n);
                  break;
      case 'l' :  left_forward(n);
                  break;
      case 'R' :  right_backward(n);
                  break;
      case 'L' :  left_backward(n);
                  break;
      default  :  Serial.println("invalid input");
                  break;
    }
    while ( Serial.available() ) {
      Serial.read();
    }
  }
}

void forward (int x) {
  digitalWrite(pin_leftf, HIGH);
  digitalWrite(pin_rightf, HIGH);
  delay(x*1000);
  digitalWrite(pin_leftf, LOW);
  digitalWrite(pin_rightf, LOW);
  Serial.println("done");
}
void backward (int x) {
  digitalWrite(pin_leftb, HIGH);
  digitalWrite(pin_rightb, HIGH);
  delay(x*1000);
  digitalWrite(pin_leftb, LOW);
  digitalWrite(pin_rightb, LOW);
  Serial.println("done");
}
void clockwise (int x) {
  digitalWrite(pin_rightf, HIGH);
  digitalWrite(pin_leftb, HIGH);
  delay(x*1000);
  digitalWrite(pin_rightf, LOW);
  digitalWrite(pin_leftb, LOW);
  Serial.println("done");
}
void anti_clockwise(int x) {
  digitalWrite(pin_leftf, HIGH);
  digitalWrite(pin_rightb, HIGH);
  delay(x*1000);
  digitalWrite(pin_leftf, LOW);
  digitalWrite(pin_rightb, LOW);
  Serial.println("done");
}
void right_forward(int x) {
  digitalWrite(pin_rightf, HIGH);
  delay(x*1000);
  digitalWrite(pin_rightf, LOW);
  Serial.println("done");
}
void left_forward(int x) {
  digitalWrite(pin_leftf, HIGH);
  delay(x*1000);
  digitalWrite(pin_leftf, LOW);
  Serial.println("done");
}
void right_backward(int x) {
  digitalWrite(pin_rightb, HIGH);
  delay(x*1000);
  digitalWrite(pin_rightb, LOW);
  Serial.println("done");
}
void left_backward(int x) {
  digitalWrite(pin_leftb, HIGH);
  delay(x*1000);
  digitalWrite(pin_leftb, LOW);
  Serial.println("done");
}
