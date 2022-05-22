int valor;
int cont = 0;
int aviso = 1;
int contAux = 0;
int n;
float a;
float l;
float p;
float A;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (aviso == 1) {
    Serial.println("Debe ingresar el número de lados del poligono.");
  } else if (aviso == 2) {
    Serial.println("Ingrese la longitud del lado.");
    aviso = -1;
  }

  if (Serial.available() > 0) {
    valor = Serial.readString().toInt();
    if (valor != -33) {
      if (contAux == 0) {
        
        n = valor;
        aviso = 2;
        contAux = 1;
        
      } else if (contAux == 1) {
        
        l = valor;
        a = l / (2 * tan((180 / n)));
        p = l * n;
        A = (p * a) / 2;
        contAux = 2;
        Serial.println("El area del poligono es: " + String(A));
        aviso = 3;
        
      }
    }
    valor = -33;
  }
  delay(100);
}
