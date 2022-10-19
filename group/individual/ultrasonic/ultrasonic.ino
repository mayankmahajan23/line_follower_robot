#include <NewPing.h>
const int trig_pin = 13;
const int echo_pin = 12;
const int max_dist = 15;
NewPing sonar(trig_pin, echo_pin, max_dist);
int pulse_width = 0;
float dist = 100;

void ultrasonic (void);

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  ultrasonic();
  delay(1000);
  /*if ( dist<=15 ) {
    buggy_stop();
    while (true) {
      ultrasonic();
      if ( dist>=15 )
        break;
    }
  }*/
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
  pulse_width = pulseIn(echo_pin, HIGH);
  dist = pulse_width*0.034/2;
  Serial.print("distance : ");
  Serial.print(dist);
  Serial.println(" cm");
}

/*
  what is actually pulse_width in this case
  frequency = 40KHz //if frequency is so high, then shouldn't there be many pulses in a few microseconds
                      no because our pulse width (10) is less than time period (25)
                      after 12.5 microseconds, the direction will change?
    corresponding time period = 25 microseconds
  total pins : gnd, vcc, trigger, echo
      trig and echo - digital i/o
  speed of sound = 340m/s = 0.034cm/us
  let the pulse_width = 't' us
  distance = t*0.034/2 cm

  ultrasonic transmitter and receiver module
  range : 2 cm to 400 cm
  acoustically, soft materials like cloth can be difficult to detect

  pulseIn : detects the pulse, return time in microseconds, or returns zero if timeout is exceeded
    range 10 microseconds to 3 minutes
  Syntax
    pulseIn(pin, value)
    pulseIn(pin, value, timeout)
*/
