int valor;
int aviso = 1;
int bot;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Ingrese 1 para piedra, 2 para papel, 3 para tijeras.");

  if (Serial.available() > 0) {
    valor = Serial.readString().toInt();
    if (valor != -33) {
      if (valor == 1) {
        bot = random(1, 3);
        if (bot == 1) {
          Serial.println("Usuario = piedra, Bot = Piedra, esto es un empate");
        }
        if (bot == 2) {
          Serial.println("Usuario = piedra, Bot = papel, gano el bot");
        }
        if (bot == 3) {
          Serial.println("Usuario = piedra, Bot = tijeras, gano el usuario");
        }
      }
      if (valor == 2) {
        bot = random(1, 3);
        if (bot == 1) {
          Serial.println("Usuario = papel, Bot = Piedra, gano el usuario");
        }
        if (bot == 2) {
          Serial.println("Usuario = papel, Bot = papel, esto es un empate");
        }
        if (bot == 3) {
          Serial.println("Usuario = papel, Bot = tijeras, gano el bot");
        }
      }
      if (valor == 3) {
        bot = random(1, 3);
        if (bot == 1) {
          Serial.println("Usuario = tijeras, Bot = Piedra, gano el bot");
        }
        if (bot == 2) {
          Serial.println("Usuario = tijeras, Bot = papel, gano el usuario");
        }
        if (bot == 3) {
          Serial.println("Usuario = tijeras, Bot = tijeras, esto es un empate");
        }
      }

    }
    valor = -33;
  }
  delay(600);
}
