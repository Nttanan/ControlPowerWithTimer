// กำหนดพินที่เชื่อมต่อรีเลย์
const int relayPin = 8;

// กำหนดเวลาเปิดและปิด (หน่วยเป็นมิลลิวินาที)
const unsigned long onDuration = 1800000; // 30 นาที
const unsigned long offDuration = 1800000; // 30 นาที

// ตัวแปรสำหรับเก็บเวลาเริ่มต้น
unsigned long previousMillis = 0;
// สถานะของรีเลย์
bool relayState = true; // เริ่มต้นให้รีเลย์เปิด

void setup() {
  pinMode(relayPin, OUTPUT);
  
  // เริ่มต้นเปิดรีเลย์ (Active Low)
  digitalWrite(relayPin, LOW);
  
  // บันทึกเวลาที่เริ่มต้นทำงาน
  previousMillis = millis();
}

void loop() {
  unsigned long currentMillis = millis();

  if (relayState && (currentMillis - previousMillis >= onDuration)) {
    // ถ้ารีเลย์เปิดและถึงเวลาให้ปิด
    relayState = false;
    digitalWrite(relayPin, HIGH);
    previousMillis = currentMillis;
  } 
  else if (!relayState && (currentMillis - previousMillis >= offDuration)) {
    // ถ้ารีเลย์ปิดและถึงเวลาให้เปิด
    relayState = true;
    digitalWrite(relayPin, LOW);
    previousMillis = currentMillis;
  }
}
