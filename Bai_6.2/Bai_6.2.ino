int vrxPin = A0;  // Chân VRx của joystick kết nối với A0 (chân HERZ)
int vryPin = A1;  // Chân VRy của joystick kết nối với A1 (chân VERT)
int swPin = 2;    // Chân SW của joystick kết nối với chân D2 (chân SEL)

int xValue = 0;
int yValue = 0;
int swState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(swPin, INPUT);
}

void loop() {
  xValue = analogRead(vrxPin);  
  yValue = analogRead(vryPin);
  
  swState = digitalRead(swPin);  
  
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);

  if (swState == HIGH) {
    Serial.println(" | Button Pressed");
  } else {
    Serial.println(" | Button Released");
  }

  delay(200);
}
