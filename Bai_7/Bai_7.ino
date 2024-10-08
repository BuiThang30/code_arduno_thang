int ledPin = 13;
char incomingByte;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    if (incomingByte == '1') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED is ON");
    }

    else if (incomingByte == '0') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED is OFF");
    }
  }
}
