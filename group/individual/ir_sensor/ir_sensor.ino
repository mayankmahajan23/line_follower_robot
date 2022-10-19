void buggy_stop (void);
void forward (void);
void backward (void);
void clockwise (void);
void anti_clockwise (void);
void right_forward (void);
void left_forward (void);
void right_backward (void);
void left_backward (void);

int pin_rightf = 5;
int pin_rightb = 6;
int pin_leftb = 7;
int pin_leftf = 8;

void setup() {
  for (int i = 5; i<=8; i++)
    pinMode(i, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  Serial.begin(9600);
}

void loop() {
  int x = digitalRead(A0);
  int y = digitalRead(A1);
  Serial.print("ir state : ");
  Serial.print(x);
  Serial.println(y);

//movement code
  switch(x) {
    case 0 : switch(y) {
               case 0 : forward();
                        break;
               case 1 : left_forward();
                        break;
             }
             break;
    case 1 : switch(y) {
               case 0 : right_forward();
                        break;
               case 1 : forward();
                        break;
             }
             break;
  }
}

void buggy_stop (void){
  digitalWrite(pin_rightf, LOW);
  digitalWrite(pin_rightb, LOW);
  digitalWrite(pin_leftb, LOW);
  digitalWrite(pin_leftf, LOW);
}
void forward (void) {
  digitalWrite(pin_rightb, LOW);
  digitalWrite(pin_leftb, LOW);

  digitalWrite(pin_rightf, HIGH);
  digitalWrite(pin_leftf, HIGH);
}
void backward (void) {
  digitalWrite(pin_rightf, LOW);
  digitalWrite(pin_leftf, LOW);

  digitalWrite(pin_rightb, HIGH);
  digitalWrite(pin_leftb, HIGH);
}
void clockwise (void) {
  digitalWrite(pin_rightf, LOW);
  digitalWrite(pin_leftb, LOW);

  digitalWrite(pin_leftf, HIGH);
  digitalWrite(pin_rightb, HIGH);
}
void anti_clockwise (void) {
  digitalWrite(pin_rightb, LOW);
  digitalWrite(pin_leftf, LOW);

  digitalWrite(pin_rightf, HIGH);
  digitalWrite(pin_leftb, HIGH);
}
void right_forward (void) {
  digitalWrite(pin_rightf, LOW);
  digitalWrite(pin_rightb, LOW);
  digitalWrite(pin_leftb, LOW);

  digitalWrite(pin_leftf, HIGH);
}
void left_forward (void) {
  digitalWrite(pin_rightb, LOW);
  digitalWrite(pin_leftb, LOW);
  digitalWrite(pin_leftf, LOW);

  digitalWrite(pin_rightf, HIGH);
}
void right_backward (void) {
  digitalWrite(pin_rightf, LOW);
  digitalWrite(pin_rightb, LOW);
  digitalWrite(pin_leftf, LOW);

  digitalWrite(pin_leftb, HIGH);
}
void left_backward (void) {
  digitalWrite(pin_rightf, LOW);
  digitalWrite(pin_leftb, LOW);
  digitalWrite(pin_leftf, LOW);

  digitalWrite(pin_rightb, HIGH);
}
