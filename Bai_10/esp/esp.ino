#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "ha_nam";            // Tên WiFi của bạn
const char* password = "15011996";      // Mật khẩu WiFi của bạn

String apiKey = "a0eeea1b2aeeba7dfe869fcc4efc5ae2";  // API key từ OpenWeatherAPI
String city = "HaNoi";       // Tên thành phố
String country = "VN";        // Mã quốc gia

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);  // Kết nối WiFi

  // Chờ cho đến khi kết nối WiFi thành công
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Đang kết nối WiFi...");
  }
  Serial.println("Kết nối WiFi thành công!");

  // Gửi yêu cầu đến API sau khi kết nối
  getWeatherData();
}

void loop() {
  // Không cần thực hiện gì trong loop cho trường hợp này
}

void getWeatherData() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;  // Tạo đối tượng HTTP

    // Tạo URL để yêu cầu dữ liệu từ OpenWeatherAPI
    String url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + country + "&appid=" + apiKey + "&units=metric";
    Serial.println("URL: " + url);  // In ra URL để kiểm tra

    http.begin(url);  // Gửi yêu cầu HTTP
    int httpCode = http.GET();  // Lấy mã phản hồi HTTP

    if (httpCode > 0) {  // Kiểm tra phản hồi HTTP thành công (200)
      String payload = http.getString();  // Lưu dữ liệu trả về từ API
      Serial.println("Dữ liệu nhận được:");
      Serial.println(payload);  // In ra toàn bộ dữ liệu JSON nhận được

      // Xử lý JSON để lấy nhiệt độ và độ ẩm
      DynamicJsonDocument doc(4096);  // Tăng kích thước nếu cần
      DeserializationError error = deserializeJson(doc, payload);

      if (!error) {
        // Lấy nhiệt độ
        float temp = doc["main"]["temp"];  // Lấy nhiệt độ từ trường "main" -> "temp"
        Serial.print("Nhiệt độ hiện tại: ");
        Serial.print(temp);
        Serial.println(" °C");

        // Lấy độ ẩm
        int humidity = doc["main"]["humidity"];  // Lấy độ ẩm từ trường "main" -> "humidity"
        Serial.print("Độ ẩm hiện tại: ");
        Serial.print(humidity);
        Serial.println(" %");
      } else {
        Serial.print("Lỗi khi phân tích JSON: ");
        Serial.println(error.c_str());
      }
    } else {
      Serial.print("Lỗi khi gọi API. Mã phản hồi HTTP: ");
      Serial.println(httpCode);  // In mã lỗi HTTP nếu có
    }

    http.end();  // Kết thúc yêu cầu HTTP
  } else {
    Serial.println("WiFi bị ngắt, thử kết nối lại...");
    WiFi.begin(ssid, password);  // Thử kết nối lại WiFi nếu bị ngắt
  }
}
