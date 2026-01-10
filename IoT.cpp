#include "TFT_eSPI.h"
TFT_eSPI tft;

const int BAR_WIDTH=25;
const int BAR_HEIGHT=60;
const int BAR_START_X=10;   // ตำแหน่งแนวนอน (X)
const int BAR_Y=100;  // ตำแหน่งแนวตั้ง (Y)
const int BAR_GAP=5;     // ระยะห่างแท่ง
const int MAX_BARS=10; // จำนวนแท่งสูงสุดบนจอ
int pins[] = {BCM0, BCM1, BCM2, BCM3, BCM4, BCM5, BCM6, BCM7, BCM8, BCM9};
int dl=200;

void setup() {
  tft.begin(); //เริ่มต้นการทำงานLCD
  tft.setRotation(3);
  tft.fillScreen(TFT_BLUE);
  tft.fillRoundRect(0,0,320,50,0,TFT_YELLOW);
  tft.fillRoundRect(0,190,320,100,0,TFT_YELLOW);
  tft.setTextSize(2);
  tft.setTextColor(TFT_BLACK);
  tft.drawString("WioIOdemo V.1.0", 70, 20);
  tft.setTextColor(TFT_BLACK);
  tft.drawString("By Chanathinart", 80, 210);

  pinMode(WIO_5S_LEFT, INPUT_PULLUP); //รับค่าจากการกดปุ่ม ถ้ากด=LOW
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);

  for (int i = 0; i < 10; i++) {
    pinMode(pins[i], OUTPUT); //ตั้งค่าโหมดของขาGPIOให้เป็นขาเอาต์พุต
  }
}

//delay min=20 max=200
int barCount = 0;
void loop() {
  // กดขวา เพิ่ม bar เร็วขึ้น
  if (digitalRead(WIO_5S_RIGHT) == LOW) {
    if (barCount < MAX_BARS) {
      int xpos = BAR_START_X + barCount * (BAR_WIDTH + BAR_GAP);
      tft.fillRoundRect(xpos, BAR_Y, BAR_WIDTH, BAR_HEIGHT, 0, TFT_WHITE);
      dl-=20;
      if(dl==0){dl=20;}
      barCount++;
    }
    // กดซ้าย ลด bar ล่าสุด ช้าลง
  }else if(digitalRead(WIO_5S_LEFT) == LOW) {
    if (barCount > 0) {
      barCount--;
      int xpos = BAR_START_X + barCount * (BAR_WIDTH + BAR_GAP);
      tft.fillRoundRect(xpos, BAR_Y, BAR_WIDTH, BAR_HEIGHT, 0, TFT_BLUE);
      dl+=20;
      if(dl==220){dl=200;}
    }
  }
  for (int i = 0; i < 10; i++) {
        digitalWrite(pins[i],1);
        delay(dl);
        digitalWrite(pins[i],0);
  }
  for (int i = 9; i >= 0; i--) {
        digitalWrite(pins[i],1);
        delay(dl);
        digitalWrite(pins[i],0);
  }
}
//660710589 ชนาธินาถ เรืองวิทยานนท์
