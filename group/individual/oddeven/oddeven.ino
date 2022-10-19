void setup() {
  Serial.begin(9600);
  for (int x = 13 ; x>=8; x--) {
    pinMode(x ,OUTPUT);
  }
}

void loop() {  
  while ( Serial.available() > 0 ) {
    int y = Serial.parseInt();
    Serial.println(y);
    
    if ( y%2 == 0){
      for (int x = 13 ; x>=8; x--) {
        if (x%2 == 0){
          digitalWrite(x, HIGH);
        }
        else{
          digitalWrite(x, LOW);
        }
        delay(100);
      }
    }
    else{
      for (int x = 13 ; x>=8; x--) {
        if (x%2 == 0){
          digitalWrite(x, LOW);
        }
        else{
          digitalWrite(x, HIGH);
        }
        delay(100);
      }
    }
    while( Serial.available() > 0) {
      Serial.read();
    }
  }
}
