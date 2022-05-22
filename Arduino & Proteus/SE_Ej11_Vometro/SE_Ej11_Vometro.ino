int leds[9] = {2, 3, 4, 5, 6, 7, 8, 9};
int a1;
int maximo;
String nInStr;
int nInst = -1;

void setup() {
  // put your setup code here, to run once:
  for (int i  = 0; i < 9; i++) {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  a1 = analogRead(A0);
  maximo = map(a1, 0, 1023, 1, 9);
  
  for (int i  = 0; i < maximo; i++) {
    digitalWrite(leds[i], 1);
  }
  for (int i = maximo; i < 9; i++){
    pinMode(leds[i], 0);
  }

  delay(200);
}
