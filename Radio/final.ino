#include <RDA5807.h> 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

Adafruit_7segment display = Adafruit_7segment();
//void updateDisplay(int value);
// 7 segment display segmentlerinin bağlı olduğu pinler
const int SEGMENT_A_PIN = 7;
const int SEGMENT_B_PIN = 6;
const int SEGMENT_C_PIN = 4;
const int SEGMENT_D_PIN = 2;
const int SEGMENT_E_PIN = 1;
const int SEGMENT_F_PIN = 9;
const int SEGMENT_G_PIN = 10;

RDA5807 rx; 
int currentChannel = 0;

void setup() {
  rx.setup();
  setRadioChannel(currentChannel);

  // 7 segment display pinlerini çıkış olarak ayarla
  pinMode(SEGMENT_A_PIN, OUTPUT);
  pinMode(SEGMENT_B_PIN, OUTPUT);
  pinMode(SEGMENT_C_PIN, OUTPUT);
  pinMode(SEGMENT_D_PIN, OUTPUT);
  pinMode(SEGMENT_E_PIN, OUTPUT);
  pinMode(SEGMENT_F_PIN, OUTPUT);
  pinMode(SEGMENT_G_PIN, OUTPUT);

  display.begin(0x70);
  display.print(currentChannel);
  display.writeDisplay();
}   

void loop() {
  // Kanal değişimi için buton kontrolü
  if (digitalRead(BUTTON1_PIN) == LOW) {
    delay(50);
    if (currentChannel > 1) {
      currentChannel--;
      setRadioChannel(currentChannel);
      updateDisplay(currentChannel); // Display'i güncelle
    }
  }

  if (digitalRead(BUTTON2_PIN) == LOW) {
    delay(50);
    if (currentChannel < 10) {
      currentChannel++;
      setRadioChannel(currentChannel);
      updateDisplay(currentChannel); // Display'i güncelle
    }
  }
}

void setRadioChannel(int channel) {
  switch (channel) {
    case 1:
      rx.setFrequency(89600); // 89.6 MHz - Anadolu’nun Sesi
      break;
    case 2:
      rx.setFrequency(89800); // 89.8 MHz - Show Radyo
      break;
    case 3:
      rx.setFrequency(90000); // 90.0 MHz - Radyo Viva
      break;
    case 4:
      rx.setFrequency(90200); // 90.2 MHz - A Haber Radyo
      break;
    case 5:
      rx.setFrequency(90400); // 90.4 MHz - Haber Türk Radyo
      break;
    case 6:
      rx.setFrequency(90600); // 90.6 MHz - Radyo 2000
      break;
    case 7:
      rx.setFrequency(90800); // 90.8 MHz - Süper FM
      break;
    case 8:
      rx.setFrequency(91000); // 91.0 MHz - Radyo Alaturka
      break;
    case 9:
      rx.setFrequency(91200); // 91.2 MHz - Slow Time
      break;
    case 10:
      rx.setFrequency(91400); // 91.4 MHz - TRT FM
      break;
  }
}
void updateDisplay(int value) {
  boolean segments[7];

  switch (value) {
    case 0:
      segments[0] = HIGH;
      segments[1] = HIGH;
      segments[2] = HIGH;
      segments[3] = HIGH;
      segments[4] = HIGH;
      segments[5] = HIGH;
      segments[6] = LOW;
      break;
    case 1:
      segments[0] = LOW;
      segments[1] = HIGH;
      segments[2] = HIGH;
      segments[3] = LOW;
      segments[4] = LOW;
      segments[5] = LOW;
      segments[6] = LOW;
      break;
    case 2:
      segments[0] = HIGH;
      segments[1] = HIGH;
      segments[2] = LOW;
      segments[3] = HIGH;
      segments[4] = HIGH;
      segments[5] = LOW;
      segments[6] = HIGH;
      break;
    case 3:
      segments[0] = HIGH;
      segments[1] = HIGH;
      segments[2] = HIGH;
      segments[3] = HIGH;
      segments[4] = LOW;
      segments[5] = LOW;
      segments[6] = HIGH;
      break;
    case 4:
      segments[0] = LOW;
      segments[1] = HIGH;
      segments[2] = HIGH;
      segments[3] = LOW;
      segments[4] = LOW;
      segments[5] = HIGH;
      segments[6] = HIGH;
      break;
    case 5:
      segments[0] = HIGH;
      segments[1] = LOW;
      segments[2] = HIGH;
      segments[3] = HIGH;
      segments[4] = LOW;
      segments[5] = HIGH;
      segments[6] = HIGH;
      break;
    case 6:
      segments[0] = HIGH;
      segments[1] = LOW;
      segments[2] = HIGH;
      segments[3] = HIGH;
      segments[4] = HIGH;
      segments[5] = HIGH;
      segments[6] = HIGH;
      break;
    case 7:
      segments[0] = HIGH;
      segments[1] = HIGH;
      segments[2] = HIGH;
      segments[3] = LOW;
      segments[4] = LOW;
      segments[5] = LOW;
      segments[6] = LOW;
      break;
    case 8:
      segments[0] = HIGH;
      segments[1] = HIGH;
      segments[2] = HIGH;
      segments[3] = HIGH;
      segments[4] = HIGH;
      segments[5] = HIGH;
      segments[6] = HIGH;
      break;
    case 9:
      segments[0] = HIGH;
      segments[1] = HIGH;
      segments[2] = HIGH;
      segments[3] = HIGH;
      segments[4] = LOW;
      segments[5] = HIGH;
      segments[6] = HIGH;
      break;
    default:
      // Varsayılan durum: Display kapalı
      segments[0] = LOW;
      segments[1] = LOW;
      segments[2] = LOW;
      segments[3] = LOW;
      segments[4] = LOW;
      segments[5] = LOW;
      segments[6] = LOW;
      break;
  }

  digitalWrite(SEGMENT_A_PIN, segments[0]);
  digitalWrite(SEGMENT_B_PIN, segments[1]);
  digitalWrite(SEGMENT_C_PIN, segments[2]);
  digitalWrite(SEGMENT_D_PIN, segments[3]);
  digitalWrite(SEGMENT_E_PIN, segments[4]);
  digitalWrite(SEGMENT_F_PIN, segments[5]);
  digitalWrite(SEGMENT_G_PIN, segments[6]);
}
