int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};  
volatile bool buttonPressed = false;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(10, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(10), handleButtonPress, FALLING);
}

void handleButtonPress() {
  buttonPressed = true;
}

void loop() {
  if (buttonPressed) { 
    for (int i = 0; i < 8; i++) {
      digitalWrite(leds[i], LOW);
    }
    buttonPressed = false;
  } else {
    for (int i = 0; i < 8; i++) {
      digitalWrite(leds[i], HIGH);
      delay(250);             
      digitalWrite(leds[i], LOW);
    }
  }
}