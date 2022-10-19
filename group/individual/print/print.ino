void setup() {
  Serial.begin(9600);
}
int x = 0;

void loop() {
  if ( Serial.available() ) {
    
    Serial.println(x);
    x = Serial.parseInt();
    
    /*Serial.println(78);
    Serial.println(1.23456); //floats are defaulted to 2 decimal places
    Serial.println('N');
    Serial.println("Hello world.");

    //allowed bases
    Serial.println(78, BIN);
    Serial.println(78, OCT);
    Serial.println(78, DEC);
    Serial.println(78, HEX);

    //decimal digits for floats
    Serial.println(1.23456, 0);
    Serial.println(1.23456, 2);
    Serial.println(1.23456, 4);

    //flash memory strings
    Serial.print(F("Hello World"));*/
  }
}
