
void setup() {
  pinMode(D7, OUTPUT);
}

void loop() {
  //newfunction(1000000, 10000);
  //blinkitbitch(1000,50000);
  blinkdecay(1500,15000);
  delay(1000);
  blinkdecay(2000,5000);
  delay(1000);
  blinkdecay(500,20000);
  delay(1000);
}

void blinkdecay(float initial, float duration){
  float a = initial / duration;
  float y = initial;
  float t = 0;
  while( y > 15 ){
    y = initial - (a * t);
    digitalWrite(D7, HIGH);
    delay(y);
    digitalWrite(D7, LOW);
    delay(y);
    t += 2 * y;
  }
}
