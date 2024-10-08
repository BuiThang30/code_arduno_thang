const int ledPins[] = {6, 7, 8, 9, 10, 11, 12, 13}; 
const int buttonPin = 2; 
int mode = 0; 
bool buttonPressed = false; 
unsigned long lastDebounceTime = 0;  // Thời gian debounce nút nhấn
unsigned long debounceDelay = 50;    // 50ms để debounce

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Kiểm tra trạng thái nút bấm với debounce
  unsigned long currentMillis = millis();
  if (digitalRead(buttonPin) == HIGH) {
    if ((currentMillis - lastDebounceTime) > debounceDelay) {
      if (!buttonPressed) {
        buttonPressed = true; 
        mode++; 
        if (mode > 5) {
          mode = 0; 
        }
      }
      lastDebounceTime = currentMillis; // Đặt lại thời gian debounce
      turnOffAllLeds();
    }
  } else {
    buttonPressed = false; 
  }

  // Chạy chế độ hiện tại
  switch (mode) {
    case 0:
      mode1();
      break;
    case 1:
      mode2();
      break;
    case 2:
      mode3();
      break;
    case 3:
      mode4();
      break;
    case 4:
      mode5();
      break;
    case 5:
      mode6();
      break;
  }
}

void mode1() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], i % 2 == 0 ? HIGH : LOW);
  }
  delay(250);
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], i % 2 == 0 ? LOW : HIGH);
  }
  delay(250);
}

void mode2() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], HIGH);  
    delay(150);  
  }
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], LOW);  
    delay(150);  
  }
}

void mode3() {
  for (int i = 0; i < 8; i += 2) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i+1], HIGH);
    delay(150);
    digitalWrite(ledPins[i], LOW);
    digitalWrite(ledPins[i+1], LOW);
    delay(150);
  }
}

void mode4() {
  for(int i = 0; i < 8; i++){
    digitalWrite(ledPins[i], HIGH);
    delay(150);
  }
  for(int i = 7; i >= 0; i--){
    digitalWrite(ledPins[i], LOW);
    delay(150);
  }
}

int dem = 0;
void mode5() {
  for (int i = 0; i < 8 - dem; i++) {
    turnOffAllLeds();
    for (int j = 0; j <= dem; j++) {
      digitalWrite(ledPins[(i + j) % 8], HIGH);
    }
    delay(300);
  }
  dem++;
  if (dem > 7) {
    dem = 0;
  }
}

int dem1 = 0;
bool allLed = false;
void mode6() {
  if (allLed) {
    return;
  }
  for (int i = 0; i < 8 - dem1; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(150);
    if (i < 8 - dem1 - 1) {
      digitalWrite(ledPins[i], LOW);
    }
  }
  dem1++;
  if (dem1 > 7) {
    allLed = true;
  }
}

void turnOffAllLeds() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
