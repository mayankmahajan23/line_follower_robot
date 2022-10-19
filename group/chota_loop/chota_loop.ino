void buggy_stop (void);
void forward (void);
void backward (void);
void clockwise (void);
void anti_clockwise (void);
void right_forward (void);
void left_forward (void);
void right_backward (void);
void left_backward (void);

void cut_right (void);
void cut_left (void);
void merge (void);

int pin_rightf = 5;
int pin_rightb = 6;
int pin_leftb = 7;
int pin_leftf = 8;

int loops = 2; //number of loops
int count = 0; //2*loops - 1;
int initial_park_position = 2;
int final_park_position = 2;
int x = 0;
int y = 0;

void setup() {
  for (int i = 5; i<=8; i++)
    pinMode(i, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

int temp_initial_park = initial_park_position; //don't need to preserve initial_park_position for future ues, still maybe nice to have
int temp_final_park = final_park_position; //don't need to preserve initial_park_position for future ues, still maybe nice to have

void loop() {
  x = digitalRead(A0);
  y = digitalRead(A1);
  Serial.print(x);
  Serial.println(y);

//movement code
  switch(x) {
    case 0 : switch(y) {
               case 0 : buggy_stop();
                        //choose();
                        //cut_left();
                        cut_right();
                        //merge();
                        park();
                        //unpark();
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

void choose (void) {
  Serial.print("enter function : choose");

  if (count == 0) {
    cut_right();
    park();
  }
  else if (count%2 == 0)
    cut_left();
  else if (initial_park_position != 0)
    unpark();
  else
    merge();
}
void cut_right (void) {
  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);
    Serial.print(x);
    Serial.println(y);

    switch (x) {
      case 0 : switch (y) {
                 case 0 : right_forward();
                          break;
                 case 1 : left_forward(); //wont happen irl
                          break;
               }
               break;
      case 1 : switch (y) {
                 case 0 : right_forward();
                          break;
                 case 1 : //cut_right_check();
                          return;
               }
               break;
    }
  }
}
void cut_left (void) {
  count--;

  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);
    Serial.print(x);
    Serial.println(y);

    switch (x) {
      case 0 : switch (y) {
                 case 0 : left_forward();
                          break;
                 case 1 : left_forward();
                          break;
               }
               break;
      case 1 : switch   (y) {
                 case 0 : right_forward(); //wont happen irl
                          break;
                 case 1 : forward();
                          //cut_left_check();
                          return;
               }
               break;
    }
  }
}
void merge (void) {
  count--;

  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);
    Serial.print(x);
    Serial.println(y);

    switch (x) {
      case 0 : switch (y) {
                 case 0 : forward();
                          break;
                 case 1 : left_forward();
                          break;
               }
               break;
      case 1 : switch (y) {
                 case 0 : right_forward();
                          break;
                 case 1 : forward();
                          return;
               }
               break;
    }
  }
}

void park (void) {
  Serial.print("enter function : park");
  int temp = final_park_position;

  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);
    Serial.print(x);
    Serial.println(y);

    switch (x) {
      case 0 : switch (y) {
                 case 0 : buggy_stop(); //recheck : is the processing fast enough so that we don't need this line
                          if (temp < 3) {
                            //hardcode
                            { forward();
                              delay(200);
                            }
                            //real deal
                            /*{ forward();
                              while (x==0 && y==0) {
                              x = digitalRead(A0);
                              y = digitalRead(A1);
                              }
                            }*/
                            temp++;
                          }
                          else {
                            buggy_stop();
                            delay(3000);
                            anti_clockwise();
                            delay(10000); //recheck : should stop permanently without further commands
                            return;
                          }
                          break;
                 case 1 : left_forward();
                          break;
               }
               break;
      case 1 : switch (y) {
                 case 0 : right_forward();
                          break;
                 case 1 : forward();
                          break;
               }
               break;
    }
  }
  initial_park_position = final_park_position;
}
void unpark (void) {
  Serial.print("enter function : unpark");

  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);
    Serial.print(x);
    Serial.println(y);

    switch (x) {
      case 0 : switch (y) {
                 case 0 : if (temp_initial_park > 0) {
                            //hardcode
                            { forward();
                              delay(200);
                            }
                            //real deal
                            /*{ forward();
                              while (x==0 && y==0) {
                              x = digitalRead(A0);
                              y = digitalRead(A1);
                              }
                            }*/
                            temp_initial_park--;
                          }
                          else {
                            merge();
                            return;
                          }
                          break;
                 case 1 : left_forward();
                          break;
               }
               break;
      case 1 : switch (y) {
                 case 0 : right_forward();
                          break;
                 case 1 : forward();
                          break;
               }
               break;
    }
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
