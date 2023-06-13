int buttonState1 = 0;
int buttonState2 = 0;
int lastButtonState1 = LOW;
int lastButtonState2 = LOW;
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
const unsigned long debounceDelay = 50;
int sayici = 0 ;
int ledSayici = 0;
int temp;
byte ledState = LOW;

void setup()
{
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
  int reading1 = digitalRead(4);
  if (reading1 != lastButtonState1) {
    lastDebounceTime1 = millis();
  }
  if ((millis() - lastDebounceTime1) > debounceDelay) {
    if (reading1 != buttonState1) {
      buttonState1 = reading1;
      if (buttonState1 == HIGH) {
        sayici++;
        ledSayici++;
      }
    }
  }
  lastButtonState1 = reading1;
  

  int reading2 = digitalRead(5);
  if (reading2 != lastButtonState2) {
    lastDebounceTime2 = millis();
  }
  if ((millis() - lastDebounceTime2) > debounceDelay) {
    if (reading2 != buttonState2) {
      buttonState2 = reading2;
      if (buttonState2 == HIGH) {
        sayici--;
        ledSayici++;
      }
    }
  }
  lastButtonState2 = reading2;
  

  if (temp != sayici) {
    Serial.print("sayici degeri= ");
    Serial.println(sayici);
    temp = sayici;
  }
  

  if (ledSayici > 50) { 
    digitalWrite(13, HIGH);
  }
}