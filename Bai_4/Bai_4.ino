int count = 0;

const int segmentPins1[7] = {2, 3, 4, 5, 6, 7, 8}; // Chân cho LED 7 đoạn 1 (Hàng Chục)
const int segmentPins2[7] = {10, 11, 12, 13, A0, A1, A2}; // Chân cho LED 7 đoạn 2 (Hàng Đơn Vị)
const int code7seg[10] = {0xC0, 0x79, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
void setup() {
    for (int i = 0; i < 7; i++) {
        pinMode(segmentPins1[i], OUTPUT);
        pinMode(segmentPins2[i], OUTPUT);
    }
}

void loop() {
    for (count = 0; count < 100; count++) {
        display(count);
        delay(1000);
    }
}

void display(int num) {
    int tens = num / 10;
    int ones = num % 10;

    for (int i = 0; i < 7; i++) {
        bool isBitSet = bitRead(code7seg[tens], i); 
        digitalWrite(segmentPins1[i], isBitSet);
    }
//  delay(5);
    for (int i = 0; i < 7; i++) {
        bool isBitSet = bitRead(code7seg[ones], i);
        digitalWrite(segmentPins2[i], isBitSet);
    }
//  delay(5);
}
