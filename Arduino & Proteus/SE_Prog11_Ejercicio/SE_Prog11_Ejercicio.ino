//funcion map
//potenciometro
int leds[8] = {6, 7, 8, 9, 10, 11, 12, 13};
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
}
int v, vNueva, ant = -1;
void loop() {
  // put your main code here, to run repeatedly:
  //10bits de resolucion, 5v de referencia, ADC=>0-1023
  v = analogRead(A0);
  vNueva = map(v, 0, 1023, 0, 7);
  //v= valor a mapear
  //0 =limite inferior intervalo origen
  //1023 = lim sup intervalo origen
  //0=lim inf intervalo destino
  //7=kim sup intervalo destino
  Serial.println("v: " + String(v) + "vNueva: " + String(vNueva));
  if (ant != vNueva) {
    ant = vNueva;
    limpiar();
    digitalWrite(leds[vNueva], 1);
  }

  delay(100);
}//tarea ejercicio cuando este el 6 se prendera el led 6 y asi todo los demas apagados

void limpiar() {
  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], 0);
  }
}
