int valor;
int cont = 0;
int aviso = 1;
int contAux = 0;
int n;
float res = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (aviso == 1) {
    Serial.println("Ingrese la longitud del lado 1.");
  } else if (aviso == 2) {
    Serial.println("Ingrese la longitud del lado 2.");
    aviso = -1;
  } else if (aviso == 3) {
    Serial.println("Ingrese la longitud del lado 3.");
    aviso = -1;
  } else if (aviso == 4) {
    Serial.println("Ingrese la longitud del lado 4.");
    aviso = -1;
  }

  if (Serial.available() > 0) {
    valor = Serial.readString().toInt();
    if (valor != -33) {
      res = res + valor;
      contAux = contAux + 1;
      if (contAux == 1) {
        aviso = 2;
      } else if (contAux == 2) {
        aviso = 3;
      } else if (contAux == 3) {
        aviso = 4;
      } else if (contAux == 4) {
        Serial.println("El resultado es: " + String(res));
      }
    }
    valor = -33;
  }
  delay(100);
}
