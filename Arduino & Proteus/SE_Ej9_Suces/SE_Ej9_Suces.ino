int sus1 = 0;
int sus2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("\nSerie 1: "+String(sus1 += 5));
  Serial.println("Serie 2: "+String(sus2 += 7));
  
  if(sus1 == 50){
    sus1 = 0;
    Serial.println("\nSerie 1 terminada. Reiniciada.");
  }
  if(sus2 == 70){
    sus2 = 0;
    Serial.println("Serie 2 terminada. Reiniciada.");
  }
  
  delay(500);
}
