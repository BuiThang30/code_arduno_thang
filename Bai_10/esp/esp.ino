#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "ha_nam";            
const char* password = "15011996";      

String apiKey = "a0eeea1b2aeeba7dfe869fcc4efc5ae2";  
String city = "HaNoi";     
String country = "VN";       

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);  

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Đang kết nối WiFi...");
  }
  Serial.println("Kết nối WiFi thành công!");

  getWeatherData();
}

void loop() {
}

void getWeatherData() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    String url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + country + "&appid=" + apiKey + "&units=metric";
    Serial.println("URL: " + url);

    http.begin(url);
    int httpCode = http.GET();

    if (httpCode > 0) { 
      String payload = http.getString();
      Serial.println("Dữ liệu nhận được:");
      Serial.println(payload);
      
      DynamicJsonDocument doc(4096);
      DeserializationError error = deserializeJson(doc, payload);

      if (!error) {
        float temp = doc["main"]["temp"];
        Serial.print("Nhiệt độ hiện tại: ");
        Serial.print(temp);
        Serial.println(" °C");

        int humidity = doc["main"]["humidity"];
        Serial.print("Độ ẩm hiện tại: ");
        Serial.print(humidity);
        Serial.println(" %");
      } else {
        Serial.print("Lỗi khi phân tích JSON: ");
        Serial.println(error.c_str());
      }
    } else {
      Serial.print("Lỗi khi gọi API. Mã phản hồi HTTP: ");
      Serial.println(httpCode); 
    }

    http.end();
  } else {
    Serial.println("WiFi bị ngắt, thử kết nối lại...");
    WiFi.begin(ssid, password);
  }
}
