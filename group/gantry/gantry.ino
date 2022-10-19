//use short int, byte, bit, bool or other data types to save memory
//break not needed where return is already there
//code for default case
//remove code after testing that wont happen irl
//try code with and without rechecks
//try with bitwise operator of nor gate ~(x|y) or (~x)&(~y)
//buggy will remain in the park function after stopping
//check lines with the comment "recheck"

#include <NewPing.h>
#define trig_pin 13
#define echo_pin 12
#define max_dist 200
NewPing sonar(trig_pin, echo_pin, max_dist);
int pulse_width_us;
float dist;

int gantry_counter = 0;
int loops = 2; //number of loops
int count = 2*loops - 1;
int initial_park_position = 2;
int final_park_position = 2;
int x = 0;
int y = 0;
int z = 0;

int pin_rightf = 5;
int pin_rightb = 6;
int pin_leftb = 7;
int pin_leftf = 8;

int gantry_pin = 4;
int pulse_width_gantry = 0;
float gantry_frquency = 0;

void buggy_stop (void);
void forward (void);
void backward (void);
void clockwise (void);
void anti_clockwise (void);
void right_forward (void);
void left_forward (void);
void right_backward (void);
void left_backward (void);

void choose (void); //dependent on track
void cut_right (void);
void cut_right_check (void);
void cut_left (void);
void cut_left_check (void);
void merge_from_in_from_in (void);
void park (void);
void unpark (void);
void ultrasonic (void);

void setup() {
  for (int i = 5; i<=8; i++)
    pinMode(i, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(gantry_pin, INPUT);
  Serial.begin(9600);

  /*Serial.print("enter initial_park_position : ");
  while ( true ){
    if ( Serial.available() ) {
      initial_park_position = Serial.parseInt();
      break;
    }
  }
  Serial.println(initial_park_position);

  Serial.print("enter final_park_position : ");
  while ( true ){
    if ( Serial.available() ) {
      final_park_position = Serial.parseInt();
      break;
    }
  }
  Serial.println(final_park_position);*/
}

int temp_initial_park = initial_park_position; //don't need to preserve initial_park_position for future ues, still maybe nice to have
int temp_final_park = final_park_position; //don't need to preserve initial_park_position for future ues, still maybe nice to have

void loop() {
  /*ultrasonic();
  if ( dist>=0 && dist<=15 ) {
    buggy_stop();
    while (true) {
      ultrasonic();
      if ( dist>=15 )
        break;
    }
  }*/
  //gantry
  forward();
  z = digitalRead(gantry_pin);
  if ( z == 1) {
    buggy_stop();
    gantry();
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

  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");
}
void gantry (void) {
  pulse_width_gantry = pulseIn(gantry_pin,HIGH);
  Serial.print("pulse_width_gantry (in microseconds) : ");
  Serial.println(pulse_width_gantry);
  gantry_frquency = 1/(2*pulse_width_gantry);
  Serial.print("gantry_frquency : ");
  Serial.println(gantry_frquency);

  if ( pulse_width_gantry>500 && pulse_width_gantry<1500 ) {
    Serial.println("gantry : 1");
    gantry_counter = gantry_counter + 1;
    delay(3000);
  }
  else if ( pulse_width_gantry>2000 && pulse_width_gantry<3000 ) {
    Serial.println("Gantry: 2");
    gantry_counter = gantry_counter + 1;
    delay(3000);
  }
  else if ( pulse_width_gantry>3000 && pulse_width_gantry<4000 ) {
    Serial.println("Gantry: 3");
    gantry_counter = gantry_counter + 1;
    delay(3000);
  }
  else
    Serial.println("Gantry: Unknown");
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
