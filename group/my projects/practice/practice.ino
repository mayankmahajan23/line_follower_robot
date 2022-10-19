int led = 13;
int state;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(19200);
  digitalWrite(led, HIGH);
}

void loop() {  
  if (Serial.available() > 0) {
    if (Serial.peek() == 's') {
      state = Serial.parseInt();
      digitalWrite(led, state);
      Serial.println(state);
    }

    //if there are more characters, i.e. bytes in the input then it will clear the stream by taking all bytes one at a time
    while (Serial.available() > 0) {
      Serial.read();
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
Serial.parseInt(char skipChar)*/
