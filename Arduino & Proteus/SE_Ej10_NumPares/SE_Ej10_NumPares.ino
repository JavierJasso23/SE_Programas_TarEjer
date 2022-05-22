String valor;
int valorIJ;
int par;
int aviso = 1;
int maximo;
int cont = 1;
int contPar = 0;
int a[] = {0, 0, 0, 0};
int b[] = {0, 0, 0, 0};
int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (aviso == 1) {
    Serial.println("Ingrese los valores del arreglo 'a' separados por comas ejemplo: 2,4,66,1, ");
  }

  if (Serial.available() > 0) {
    aviso = -1;
    valor = Serial.readString(); 
    valor.trim();                

    while (valor.length() != 0) {
      valorIJ = valor.substring(0, valor.indexOf(",")).toInt();            
      valor = valor.substring(valor.indexOf(",") + 1, valor.length()); 
      if (cont == 1) {
        a[i] = valorIJ;
      } else {
        b[i] = valorIJ;
      }
      i = i + 1;
    }
    i = 0;
    if (cont == 1) {
      Serial.println("Los valores ingresados son a[" + String(a[0]) +","+ String(a[1]) +","+ String(a[2]) +","+ String(a[3]) + "] ahora igrese b");
      cont = 2;
    } else {
      Serial.println("Los valores ingresados son b[" + String(b[0]) +","+ String(b[1]) +","+ String(b[2]) +","+ String(b[3]) + "]");
      Serial.println("C = [" + String((a[0]*b[0]) + (a[1]*b[2])) +","+ String((a[0]*b[1]) + (a[1]*b[3])) +","+ String((a[2]*b[0]) + (a[3]*b[2])) +","+ String((a[2]*b[1]) + (a[3]*b[3])) + "]");
    }

  }
  delay(100);
}
