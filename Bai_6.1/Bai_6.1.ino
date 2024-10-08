const int ntcPin = A0; // Chân cảm biến NTC
const int ldrPin = A1; // Chân cảm biến LDR

const float BETA = 3950;

const float GAMMA = 0.7;
const float RL10 = 50;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int ntcValue = analogRead(ntcPin);  
  float celsius = 1 / (log(1 / (1023. / ntcValue - 1)) / BETA + 1.0 / 298.15) - 273.15;

  int ldrValue = analogRead(ldrPin);
  float voltage = ldrValue / 1024. * 5;
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.print(" °C, LDR Value: ");
  Serial.println(lux);

  delay(1000);
}
