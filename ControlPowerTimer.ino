// กำหนดพินที่เชื่อมต่อรีเลย์
const int relayPin = 8;

// กำหนดเวลาเปิดและปิด (หน่วยเป็นมิลลิวินาที)
const unsigned long onDuration = 1800000; // 30 นาที
const unsigned long offDuration = 1800000; // 30 นาที

// ตัวแปรสำหรับเก็บเวลาเริ่มต้น
unsigned long previousMillis = 0;
// สถานะของรีเลย์
bool relayState = false;

void setup() {
  // ตั้งค่าพินของรีเลย์เป็น output
  pinMode(relayPin, OUTPUT);
  // เริ่มต้นปิดรีเลย์
  digitalWrite(relayPin, HIGH);
}

void loop() {
  // อ่านเวลาปัจจุบัน
  unsigned long currentMillis = millis();

  if (relayState && (currentMillis - previousMillis >= onDuration)) {
    // ถ้ารีเลย์เปิดและถึงเวลาให้ปิด
    relayState = false; // ปิดรีเลย์
    digitalWrite(relayPin, LOW);
    previousMillis = currentMillis; // อัปเดตเวลาเริ่มต้น
  } else if (!relayState && (currentMillis - previousMillis >= offDuration)) {
    // ถ้ารีเลย์ปิดและถึงเวลาให้เปิด
    relayState = true; // เปิดรีเลย์
    digitalWrite(relayPin, LOW);
    previousMillis = currentMillis; // อัปเดตเวลาเริ่มต้น
  }
}
