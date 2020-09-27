/*
  Blink SoS beacon
  by Bang
*/

int led = 10;           // the PWM pin the LED is attached to
int waitTimeShort = 500;
int waitTimeLong = 1000;

void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

void loop() {
  S();
  O();
  S();

  delay(5000);
}

void S() {
  ShortSequence();
  ShortSequence();
  ShortSequence();
}

void O() {
  LongSequence();
  LongSequence();
  LongSequence();
}

void LongSequence() {
  TurnOn(waitTimeLong);
  TurnOff(waitTimeLong);
}

void ShortSequence() {
  TurnOn(waitTimeShort);
  TurnOff(waitTimeShort);
}

void TurnOn(int miliseconds) {
  digitalWrite(led, HIGH);
  delay(miliseconds);
}

void TurnOff(int miliseconds) {
  digitalWrite(led, LOW);
  delay(miliseconds);
}
