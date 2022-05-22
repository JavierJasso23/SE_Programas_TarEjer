int valor;
int aviso = 1;
int contAux = 0;
float res = 0;
float base;
float altura;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (aviso == 1) {
    Serial.println("Ingrese la base.");
  } else if (aviso == 2) {
    Serial.println("Ingrese la altura.");
    aviso = -1;
  }

  if (Serial.available() > 0) {
    valor = Serial.readString().toInt();
    if (valor != -33) {
      if (contAux == 0) {
        base = valor;
        aviso = 2;
        contAux = contAux + 1;
      } else if (contAux == 1) {
        altura = valor;
        aviso = 3;
        contAux = contAux + 1;
        res = (base*altura)/2;
        Serial.println("El resultado es: " + String(res));
      }
    }
    valor = -33; 
  }
  delay(100);
}
