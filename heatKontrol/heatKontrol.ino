int sensorpin= A0;
int sensorval;
int ledpin1=13;
int ledpin2=12;
void setup() {
  pinMode(sensorpin,INPUT); 
  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
  Serial.begin(9600);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2,LOW);
}
  void loop() {
   sensorval=analogRead(sensorpin);
  sensorval=sensorval/2.0741;
  sensorval++;
  if(sensorval>30)
  {
    digitalWrite(ledpin1,HIGH);
    digitalWrite(ledpin2,LOW);
    delay(500);
  }
  if(sensorval<20)
  {
    digitalWrite(ledpin1,LOW);
    digitalWrite(ledpin2,HIGH);
    delay(500);
  }
  Serial.print("Sicaklik = ");
  Serial.println(sensorval);
  Serial.print(" C");
}