//two : cw and acw, detects merge

//if they work change in all
//plus modify and then add for ACW codes
void merge_cw (void) {
  Serial.println("enter function : merge_cw");
  count--;

  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);

    switch (x) {
      case 0 : switch (y) {
                 case 0 : clockwise();
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
void cut_left (void) {
  Serial.println("enter function : cut_left");
  count--;

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
//unpark with cw is very risky!
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
                            merge_cw();
                            return;
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
}
void merge_acw (void) {
  Serial.println("enter function : merge_cw");
  count--;

  while (true) {
    x = digitalRead(A0);
    y = digitalRead(A1);

    switch (x) {
      case 0 : switch (y) {
                 case 0 : anti_clockwise();
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

//note: parseInt picks a long int from the buffer
//Characters that are not integers (or the minus sign) are skipped.
//hence this will work s1dsfdskjfdskj, but this wont s1564564
//note: buffer is 64 bytes long, limit your input accordingly
//input: sdfgf1kjnsbfg gives on and off - because if no digit is found it returns 0 by default
//Parsing stops when no characters have been read for a configurable time-out value, or a non-digit is read ?

/*Syntax
Serial.parseInt() or
Serial.parseInt(char skipChar)

Parameters
skipChar: used to skip the indicated char in the search. Used for example to skip thousands divider ?

Returns
long*/
