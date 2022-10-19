int x = 0;

int initial_park_position = 2;
int final_park_position = 2;
void setup() {
  Serial.begin(9600);

  Serial.print("enter initial_park_position : ");
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
}

void loop() {
  if ( Serial.available() ) {
    x = Serial.parseInt();
    Serial.print(x);
  }
}
