void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    Serial.println(78);             //gives "78"
    Serial.println(1.23456);        //default: gives "1.23"
    Serial.println('N');            //gives "N"
    Serial.println("Hello world."); //gives "Hello world."

    Serial.println(1.23456, 0); //gives "1"
    Serial.println(1.23456, 2); //gives "1.23"
    Serial.println(1.23456, 4); //gives "1.2346"
    
    Serial.println(""); //carraige return
    Serial.println(78, BIN);

    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}

//note: wait a second after clicking on serial monitor before giving input, because arduino restarts then.
/*Prints data to the serial port as human-readable ASCII text. This command can take many forms.
Numbers are printed using an ASCII character for each digit.
Floats are similarly printed as ASCII digits, defaulting to two decimal places.
Bytes are sent as a single character. Characters and strings are sent as is.
An optional second parameter specifies the base (format) to use; permitted values are BIN (binary, or base 2),
OCT (octal, or base 8), DEC (decimal, or base 10), HEX (hexadecimal, or base 16).
For floating point numbers, this parameter specifies the number of decimal places to use. */
