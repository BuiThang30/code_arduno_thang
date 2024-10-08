#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL647N8Mu6t"
#define BLYNK_TEMPLATE_NAME "NTC LDR"
#define BLYNK_AUTH_TOKEN "Lo3TpRo__FbWO-WDkJhwKtNJgBo6Cvuw"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "Lo3TpRo__FbWO-WDkJhwKtNJgBo6Cvuw";
char ssid[] = "ha_nam";
char pass[] = "15011996";

int ntcPin = 34;
int ldrPin = 35;

const float BETA = 3950;

const float GAMMA = 0.7;
const float RL10 = 33;

BlynkTimer timer;

void sendSensorData() {
  
  int ntcValue = analogRead(ntcPin);  
  float celsius = 1 / (log(1 / (4095. / ntcValue - 1)) / BETA + 1.0 / 298.15) - 273.15;

  int ldrValue = analogRead(ldrPin);
  float voltage = ldrValue / 4095. * 3.3;
  float resistance = 2000 * voltage / (1 - voltage / 3.3);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));
  
  
  Blynk.virtualWrite(V0, celsius);
  Blynk.virtualWrite(V1, lux);
  
  Serial.print("Nhiệt độ (°C): ");
  Serial.print(celsius);
  Serial.print(" | Độ sáng (lux): ");
  Serial.println(lux);
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  // Đọc cảm biến và gửi dữ liệu mỗi giây
  timer.setInterval(1000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}

