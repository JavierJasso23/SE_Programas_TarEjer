int num;
int cont = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    num = Serial.readString().toInt();
    Serial.println("Se ingreso: "+String(num));
    if (num >= 0) {
      cont = cont + 1;
    } else {
      Serial.println("Se ingresaron un total de " + String(cont) + " numeros antes del negativo.");
      cont = 0;
    }
  }
  delay(100);
}
