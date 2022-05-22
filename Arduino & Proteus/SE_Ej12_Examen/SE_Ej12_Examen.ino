String valor;
int valorIJ;
int aviso = 1;
int cont = 1;
int i = 1;
int respC;
int correctas = 0;
int nTabla;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (aviso == 1) {
    Serial.println("Ingrese la tabla de multiplicar que quiera contestar.");
  }

  if (Serial.available() > 0) {
    aviso = -1;
    valor = Serial.readString();
    valor.trim();
    if (cont == 1) {
      nTabla = valor.toInt();
      for (int i  = 0; i < 10; i++) {
        Serial.println(String(nTabla) + " x " + String(i + 1) + " = ?");
      }
      Serial.println("Ahora ingrese sus respuestas separadas por comas, ejemplo: 2,4,6,8,10,12,14,16,18,20,");
      cont = 2;
    } else {
      while (valor.length() != 0) {
        valorIJ = valor.substring(0, valor.indexOf(",")).toInt();
        valor = valor.substring(valor.indexOf(",") + 1, valor.length());
        
        respC = nTabla * i;
        if (respC == valorIJ) {
          correctas = correctas + 1;
        }
        i = i + 1;
      }
      Serial.println("Tuviste un total de " + String(correctas) + " de 10 respuestas correctas.");
    }
  }
  delay(100);
}
