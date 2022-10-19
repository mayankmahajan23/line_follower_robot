int a = 11;
int b = 10;
int c = 9;
int d = 6;
int e = 5;
int f = 3;

int x = 250;
int y = 0;

void setup() {
  pinMode(11 ,OUTPUT);
  pinMode(10 ,OUTPUT);
  pinMode(9 ,OUTPUT);
  pinMode(6 ,OUTPUT);
  pinMode(5 ,OUTPUT);
  pinMode(3 ,OUTPUT);
}

void loop() {
  int n = y;
  for (int i = 6; i<0; i--) {
    analogWrite(11, n);
    delay(50);
    n = n + 25;
    analogWrite(10, n);
    delay(50);
    n = n + 25;
    analogWrite(9, n);
    delay(50);
    n = n + 25;
    analogWrite(6, n);
    delay(50);
    n = n + 25;
    analogWrite(5, n);
    delay(50);
    n = n + 25;
    analogWrite(3, n);
    delay(50);
    n = n + 25;
  }
}
