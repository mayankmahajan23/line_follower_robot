int x = 0;

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {
        // send data only when you receive data:
        if (Serial.available() > 0) { //gives the number of bytes available from serial port
                // read the incoming byte:
                x = Serial.read();
                Serial.println(x);

                while (Serial.available() > 0) {
                        Serial.read();
                }
        }
}

//note: serial buffer holds 64 bytes
//baud rate: bits per second (bps)
