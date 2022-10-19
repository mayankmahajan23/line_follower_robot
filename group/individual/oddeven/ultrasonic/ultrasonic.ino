#include <NewPing.h>
#define trig_pin 13
#define echo_pin 12
#define max_dist 200
NewPing sonar(trig_pin, echo_pin, max_dist);
int duration;
int dist;

void buggy_stop (void);

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);

//give a pulse of 10 microseconds
//this will give an 8 cycle sonic burst, which will travel at the speed of sound
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  duration = pulseIn(echo_pin, HIGH);
  dist = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");

  if ( dist>=0 && dist<=15 ) {
    buggy_stop;
  }
}

void buggy_stop (void){
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}

/*
    frequency = 40KHz
    total pins : gnd, vcc, trigger, echo
        trig and echo - digital i/o
    speed of sound = 340m/s = 0.034cm/us
    let the duration = 't' us
    distance = t*0.034/2 cm

    ultrasonic transmitter and receiver module
    range : 2 cm to 400 cm
    acoustically, soft materials like cloth can be difficult to detect
*/
