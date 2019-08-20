void setup() {
  // setup the digital pins for output
  pinMode(3, OUTPUT); // pin 3 to PWM
  pinMode(4, OUTPUT); // pin 4 to INA
  pinMode(5, OUTPUT); // pin 5 to INB

  digitalWrite(4, HIGH); // set INA to 1
  digitalWrite(5, LOW);  // set INB to 0

  Serial.begin(9600);
}

int analog_val = 0;
int dir = 1;

void loop() {
  // send PWM signal to pin 3
  analogWrite(3, analog_val);

  analog_val += dir;

  // recall that analogWrite takes values between 0 to 255
  if (analog_val == 255) {
    dir = -1;
  } else if (analog_val == 0) {
    dir = 1;
  }
  
  Serial.println(analog_val);
  delay(20);
}
