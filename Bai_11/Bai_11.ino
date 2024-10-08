#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Bluetooth đã sẵn sàng, hãy nhập tin nhắn từ Serial Monitor.");
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();
    bluetooth.write(data);
  }

  if (bluetooth.available()) {
    char data = bluetooth.read();
    Serial.write(data);
  }
}
