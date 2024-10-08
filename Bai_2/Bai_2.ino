const int ledPins[] = {6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  // Cấu hình các chân LED là OUTPUT
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}
//bai1
/*
void loop() {
  // Bật các LED so le
  for (int i = 0; i < 8; i++) {
    if (i % 2 == 0) {
      digitalWrite(ledPins[i], HIGH);  // Bật LED ở vị trí chẵn
    } else {
      digitalWrite(ledPins[i], LOW);   // Tắt LED ở vị trí lẻ
    }
  }
  delay(500);  // Đợi 500ms

  // Đảo ngược trạng thái các LED
  for (int i = 0; i < 8; i++) {
    if (i % 2 == 0) {
      digitalWrite(ledPins[i], LOW);   // Tắt LED ở vị trí chẵn
    } else {
      digitalWrite(ledPins[i], HIGH);  // Bật LED ở vị trí lẻ
    }
  }
  delay(500);  // Đợi 500ms
}
*/
// bai2
/*
void loop() {
  // Bật lần lượt từng LED
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], HIGH);  // Bật LED i
    delay(250);  // Đợi 250ms
  }
  
  // Tắt lần lượt từng LED
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], LOW);  // Tắt LED i
    delay(250);  // Đợi 250ms
  }
}
*/
//bai3
/*
void loop() {
  for (int i = 0; i < 8; i+=2) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i+1], HIGH);
    delay(250);
    digitalWrite(ledPins[i], LOW);
    digitalWrite(ledPins[i+1], LOW);
    delay(250);
  }
}
*/
//bai4
/*
void loop(){
  for(int i=0; i<8; i++){
    digitalWrite(ledPins[i], HIGH);
    delay(250);
  }
  for(int i = 7; i >= 0; i--){
    digitalWrite(ledPins[i], LOW);
    delay(250);
  }
}
*/
//bai5
/*
int dem = 0;
void loop() {
  for (int i = 0; i < 8-dem; i++) {
    turnOffAllLeds();
    for (int j = 0; j <= dem; j++) {
      digitalWrite(ledPins[(i + j) % 8], HIGH);
    }
    delay(1000);
  }
  dem++;
  if (dem > 7) {
    dem = 0;
  }
}
void turnOffAllLeds() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
*/
//bai 6
int dem = 0;
bool allLed = false;
void loop() {
  if (allLed) {
    return;
  }
  for (int i = 0; i < 8-dem; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(150);
    if(i<8-dem-1){
      digitalWrite(ledPins[i], LOW);
    }
  }
  dem++;
  /*
  if (dem > 7) {
    dem = 0;
    for (int i = 0; i < 8-dem; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }
  */
  if(dem > 7){
    allLed=true;
  }
}