#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL62YsHO04p"
#define BLYNK_TEMPLATE_NAME "đk sevor"
#define BLYNK_AUTH_TOKEN "mV8JsbAfNQlaspo2_8A5ZhNS28JbmzzQ"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

char ssid[] = "ha_nam";
char pass[] = "15011996";

char auth[] = "mV8JsbAfNQlaspo2_8A5ZhNS28JbmzzQ";

Servo myServo;

BLYNK_WRITE(V0) {
  int sliderValue = param.asInt();
  myServo.write(sliderValue);
  Serial.print("Giá trị nhận từ Blynk: ");
  Serial.println(sliderValue);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Đang kết nối WiFi...");
  }
  Serial.println("Kết nối thành công!");

  Blynk.begin(auth, ssid, pass);
  
  myServo.attach(23);
}

void loop() {
  Blynk.run();
}
