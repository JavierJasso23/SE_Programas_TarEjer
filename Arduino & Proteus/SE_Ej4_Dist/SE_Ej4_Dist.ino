int valor;
int cont = 0;
int aviso = 1;
int contAux = 0;
int n;
float res = 0;
float x1;
float x2;
float y1;
float y2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (aviso == 1) {
    Serial.println("Ingrese la distancia X1.");
  } else if (aviso == 2) {
    Serial.println("Ingrese la distancia X2.");
    aviso = -1;
  } else if (aviso == 3) {
    Serial.println("Ingrese la distancia Y1.");
    aviso = -1;
  } else if (aviso == 4) {
    Serial.println("Ingrese la distancia Y2.");
    aviso = -1;
  }

  if (Serial.available() > 0) {
    valor = Serial.readString().toInt();
    if (valor != -33) {
      
      if (contAux == 0) {
        x1 = valor;
        aviso = 2;
        contAux = contAux + 1;
      } else if (contAux == 1) {
        x2 = valor;
        aviso = 3;
        contAux = contAux + 1;
      } else if (contAux == 2) {
        y1 = valor;
        aviso = 4;
        contAux = contAux + 1;
      } else if (contAux == 3) {
        y2 = valor;
        contAux = contAux + 1;
        res = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
        Serial.println("El resultado es: " + String(res));
      }
    }
    valor = -33; 
  }
  delay(100);
}
