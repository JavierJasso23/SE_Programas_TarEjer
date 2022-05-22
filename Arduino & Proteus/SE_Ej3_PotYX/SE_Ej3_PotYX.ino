int valor;
int aviso = 1;
int contAux = 0;
int res = 0;
int pot;
int num;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (aviso == 1) {
    Serial.println("Ingrese potencia (Y).");
  } else if (aviso == 2) {
    Serial.println("Ingrese el numero (X).");
    aviso = -1;
  }

  if (Serial.available() > 0) {
    valor = Serial.readString().toInt();
    if (valor != -33) {
      contAux = contAux + 1;
      if (aviso == 1) {
        pot = valor;
        aviso = 2;
      } else if (contAux == 2) {
        num = valor;
        for (int i = 0; i < pot; i++) {
          res = num * num;
        }
        Serial.println("El resultado es: " + String(res));
        aviso = 3;
      }
    }
    valor = -33;
  }
  delay(100);
}
