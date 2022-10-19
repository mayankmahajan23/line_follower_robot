//use short int, byte, bit, bool or other data types to save memory
//break not needed where return is already there
//code for default case
//remove code after testing that wont happen irl
//try code with and without rechecks
//try with bitwise operator of nor gate ~(x|y) or (~x)&(~y)
//buggy will remain in the park function after stopping
//check lines with the comment "recheck"
//ultrasonic and gantry not tested
//code after parking

//AAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHHHHHHHHHHHHHHH
//cw and acw in unpark, merge (depends alot on track contour)
//fix choose_cw, because merge doesn't work from outside and we -2 in cut_left
//reset after parking not completed

#include <NewPing.h>
#define trig_pin 13
#define echo_pin 12
#define max_dist 15
NewPing sonar(trig_pin, echo_pin, max_dist);
int pulse_width_us = 0;
float dist = 20;

int flag = 0; //0 for cw, 1 or acw
int loops = 1; //number of loops
int count = 3;
int initial_park_position = 1;
int final_park_position = 2;
int park_status = 0;
int x = 0;
int y = 0;

int pin_rightf = 5;
int pin_rightb = 6;
int pin_leftb = 7;
int pin_leftf = 8;

int z = 0;
int gantry_pin = 4;
int gantry_counter = 0;
int current_time = 0;
int last_gantry_time = 0;

void buggy_stop (void);
void forward (void);
void backward (void);
void clockwise (void);
void anti_clockwise (void);
void right_forward (void);
void left_forward (void);

void choose_cw (void);
void choose_acw (void);
void cut_right (void);
void cut_left (void);
void merge_cw (void);
void merge_acw (void);
void park (void);
void unpark (void);

void ultrasonic (void);
void gantry (void);
void on_my_command (void);
void turn_around_cw (void);
void turn_around_acw (void);
void park_fix (void);
void buggy_reset (void);

void setup() {
  for (int i = 5; i<=8; i++)
    pinMode(i, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(gantry_pin, INPUT);
  Serial.begin(9600);

  Serial.print("number of loops : ");
  while ( true ) {
    if ( Serial.available() ) {
      loops = Serial.parseInt();
      break;
    }
  }
  Serial.println(loops);

  Serial.print("count : ");
  while ( true ) {
    if ( Serial.available() ) {
      count = Serial.parseInt();
      break;
    }
  }
  Serial.println(count);

  Serial.print("press any character to start the buggy : ");
  on_my_command();
}

void loop() {
  x = digitalRead(A0);
  y = digitalRead(A1);

  //movement code
  switch(x) {
    case 0 : switch(y) {
               case 0 : buggy_stop(); //recheck : do I need this
                        if (flag==0)
                          choose_cw();
                        else
                          choose_acw();
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

  ultrasonic();
  if ( dist>=0 && dist<=15 ) {
    buggy_stop();
    while (true) {
      ultrasonic();
      Serial.print("distance from object : ");
      Serial.print(dist);
      Serial.println(" cm");
      delay(1000);

      if ( dist>=15 )
        break;
    }
  }

  //gantry
  z = digitalRead(gantry_pin);
  if ( z == 1) {
    current_time = millis();
    if ( (current_time - last_gantry_time) > 2000 ) {
      buggy_stop();
      gantry();
    }
  }
}

void choose_cw (void) {
  Serial.println("enter function : choose_cw");

  if ( count <= 0 ) { //recheck : should be equal to zero, for the sake to error removal just in case
    cut_right();
    park();
  }
  else if ( count%2 == 0 )
    cut_left();
  else
    unpark();
  //else
    //merge_cw();
}
void choose_acw (void) {
  Serial.println("enter function : choose_acw");

  if ( count <= 0 ) { //recheck : should be equal to zero, for the sake to error removal just in case
    cut_left();
    park();
  }
  else if ( count%2 == 0 )
    cut_right();
  else
    unpark();
  //else
    //merge_acw();
}
void cut_right (void) {
  Serial.println("enter function : cut_right");

  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);

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
                 case 1 : forward();
                          //cut_right_check();
                          return;
               }
               break;
    }
  }
}
void cut_left (void) {
  Serial.println("enter function : cut_left");
  count = count - 2; //recheck : make it - 1 by adjusting the choose_cw, this extra -1 is for merge from outwards

  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);

    switch (x) {
      case 0 : switch (y) {
                 case 0 : left_forward();
                          break;
                 case 1 : left_forward();
                          break;
               }
               break;
      case 1 : switch (y) {
                 case 0 : right_forward(); //won't happen irl
                          break;
                 case 1 : forward();
                          //cut_left_check();
                          return;
               }
               break;
    }
  }
}
void merge_cw (void) {
  Serial.println("enter function : merge_cw");
  int a = millis();
  int b = 0;

  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);
    b = millis();
    switch (x) {
      case 0 : switch (y) {
                 case 0 : clockwise();
                          break;
                 case 1 : left_forward();
                          break;
               }
               break;
      case 1 : switch (y) {
                 case 0 : clockwise();
                          break;
                 case 1 : forward();
                          if( (b-a)>3000 )
                            return;
                          else
                            break;
               }
               break;
    }
  }
}
void merge_acw (void) {
  Serial.println("enter function : merge_acw");
  int a = millis();
  int b = 0;

  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);
    b = millis();
    switch (x) {
      case 0 : switch (y) {
                 case 0 : anti_clockwise();
                          break;
                 case 1 : anti_clockwise();
                          break;
               }
               break;
      case 1 : switch (y) {
                 case 0 : right_forward();
                          break;
                 case 1 : forward();
                          if( (b-a)>3000 )
                            return;
                          else
                            break;
               }
               break;
    }
  }
}
void park (void) {
  Serial.println("enter function : park");
  int temp_final_park = final_park_position;

  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);

    switch (x) {
      case 0 : switch (y) {
                 case 0 : if (temp_final_park < 3) {
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
                            temp_final_park++;
                          }
                          else {
                            buggy_stop;
                            if ( flag == 0 )
                              turn_around_cw();
                            else
                              turn_around_acw();
                            park_fix();
                            goto here;
                          }
                          break;
                 case 1 : anti_clockwise();
                          break;
               }
               break;
      case 1 : switch (y) {
                 case 0 : clockwise();
                          break;
                 case 1 : forward();
                          break;
               }
               break;
    }
  }
  here:
  if ( loops == 0 ) {
    Serial.println("task finished. resetting.");
    Serial.print("enter number of loops : ");
    loops = Serial.parseInt();
    Serial.println(loops);
    flag = 0;
    count = 3;
  }
  else {
    Serial.print("press any character to resume : ");
    on_my_command();
    buggy_reset();
  }
}
void unpark (void) {
  Serial.println("enter function : unpark");
  int temp_initial_park = initial_park_position;

  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);

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
                            count--;
                            if ( flag == 0 )
                              merge_cw();
                            else
                              merge_acw();
                            return;
                          }
                          break;
                 case 1 : left_forward();
                          break;
               }
               break;
      case 1 : switch (y) {
                 case 0 : clockwise();
                          break;
                 case 1 : forward();
                          break;
               }
               break;
    }
  }
}

void ultrasonic (void) {
  //clears
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);
  //give a pulse of 10 microseconds
  //this will give an 8 cycle sonic burst, which will travel at the speed of sound
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);
    pulse_width_us = pulseIn(echo_pin, HIGH);
    dist = pulse_width_us*0.034/2;
}
void gantry (void) {
  int pulse_width_gantry = pulseIn(gantry_pin, HIGH);
  Serial.print("pulse width of gantry signal (in microseconds) : ");
  Serial.println(pulse_width_gantry);
  int gantry_frquency = 1/(2*pulse_width_gantry);
  Serial.print("gantry signal frquency : ");
  Serial.println(gantry_frquency);
  last_gantry_time = millis();
  gantry_counter++;

  if ( pulse_width_gantry>500 && pulse_width_gantry<1500 )
    Serial.println("gantry : 1");
  else if ( pulse_width_gantry>2000 && pulse_width_gantry<3000 )
    Serial.println("gantry : 2");
  else if ( pulse_width_gantry>3000 && pulse_width_gantry<4000 ) {
    Serial.println("gantry : 3");
    Serial.print("press any character to resume : ");
    on_my_command();
    goto here;
  }
  else
    Serial.println("gantry : Unknown");
  delay(3000);
  here:
  return;
}
void on_my_command (void) {
  buggy_stop();
  while (true) {
    if ( Serial.available() ) {
      char x = Serial.read();
      Serial.println(x);
      Serial.println("buggy will now resume.");
      return;
    }
  }
}
void turn_around_cw (void) {
  Serial.println("enter function : turn_around_cw");

  clockwise();
  delay(1500);
  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);
    if ( x==1 && y==0 ) {
      while (true) {
        x = digitalRead(A0);
        y = digitalRead(A1);
        if ( x==1 && y==1) {
          buggy_stop();
          break;
        }
      }
      break;
    }
  }
}
void turn_around_acw (void) {
  Serial.println("enter function : turn_around_acw");

  anti_clockwise();
  delay(1500);
  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);
    if ( x==0 && y==1) {
      while (true) {
        x = digitalRead(A0);
        y = digitalRead(A1);
        if ( x==1 && y==1) {
          buggy_stop();
          break;
        }
      }
      break;
    }
  }
}
void park_fix (void) {
  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);

    switch (x) {
      case 0 : switch (y) {
                 case 0 : buggy_stop();
                          return;
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
void buggy_reset (void) {
  loops--;
  if ( flag == 0 ) {
    flag = 1;
    count = 1;
  }
  else {
    flag = 0;
    count = 3;
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
