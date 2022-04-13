/*
  Traffic lights something something
  by Bang
*/

// Light LEDs

// Intersection
int greenLed1 = 10;
int yellowLed = 11;
int redLed1 = 12;

// crosswalk
int greenLed2 = 7;
int redLed2 = 8;

// switch read pin
int ctrlSwitchPin = 9;

// Global Control flow
int recentlyPressed = 0;

// Prototype
void changeLights();

void setup()
{
    // Configure pinMode, some might not output if not configured.
    pinMode(greenLed1, OUTPUT);
    pinMode(greenLed2, OUTPUT);
    pinMode(yellowLed, OUTPUT);
    pinMode(redLed1, OUTPUT);
    pinMode(redLed2, OUTPUT);

    // Start these LEDs turned on
    digitalWrite(greenLed1, HIGH);
    digitalWrite(redLed2, HIGH);
}

void loop()
{
    int pressed = digitalRead(ctrlSwitchPin);

    if (pressed == 1 && recentlyPressed == 0)
    {
        recentlyPressed = 1;
        changeLights();
    }
}

void changeLights()
{
    digitalWrite(greenLed1, LOW);
    digitalWrite(yellowLed, HIGH);
    delay(2500);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed1, HIGH);
    delay(2000);

    digitalWrite(redLed2, LOW);
    digitalWrite(greenLed2, HIGH);
    delay(6000);

    digitalWrite(redLed2, HIGH);
    digitalWrite(greenLed2, LOW);
    delay(2000);

    digitalWrite(redLed1, LOW);
    digitalWrite(yellowLed, HIGH);
    delay(2500);

    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed1, HIGH);
    recentlyPressed = 0;
}
