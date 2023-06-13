#define echo 9
#define trig 10
#define buzz 8
int min_range = 0;
int max_range = 220;
void setup(){
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(buzz, OUTPUT);
}

int rangeCalculation(int maxrange, int minrange){
  long duration, distance;
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration / 58.2;
  delay(50);
  if(distance >= max_range || distance <= minrange){
  return 0;
  }else{
  return distance;
  }
}
int melodi(int measur){
  tone(buzz, 440);
  delay(measur);
  noTone(buzz);
  delay(measur);
}
void loop(){
  int measur = rangeCalculation(max_range, min_range);
  melodi(measur*10);
}
  

