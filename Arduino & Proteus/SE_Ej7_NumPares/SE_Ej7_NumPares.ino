int valor;
int par;
int aviso = 1;
int maximo;
int cont = 1;
int contPar = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (aviso == 1) {
    Serial.println("Ingrese la cantidad de valores que ingresara.");
  } else if (aviso == 2) {
    Serial.println("Ingrese los numeros.");
    aviso = -1;
  }

  if (Serial.available() > 0) {
    valor = Serial.readString().toInt();
    if (valor != -33) {
      if (aviso == 1) {
        maximo = valor;
        aviso = 2;
      }
      if (cont <= maximo) {
        if (aviso == -1) {
          cont = cont + 1;
          par = valor % 2;
          if (par == 0) {
            Serial.println("El numero " + String(valor) + " es par");
            contPar = contPar + 1;
          } else {
            Serial.println("El numero " + String(valor) + " no es par");
          }
        }
      } else {
        Serial.println("El total de numeros pares fueron " + String(contPar));
      }
    }
    valor = -33;
  }
  delay(100);
}
