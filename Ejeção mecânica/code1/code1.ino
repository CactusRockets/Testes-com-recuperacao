#include <Servo.h>

// Cria um objeto do tipo Servo
Servo meuServo;
// Posição inicial do servo motor
int posicaoInicial = 90;
// Quantos graus vamos girar o servo motor
int grausGirados = 90;   
// Variável para controlar se o servo deve girar
bool girar = false;  

void setup() {
  Serial.begin(9600);
  // Define o pino ao qual o servo está conectado
  meuServo.attach(9);
  // Move o servo para a posição inicial
  meuServo.write(posicaoInicial);

  delay(1000);
}

void loop() {
  // Verifica se há dados disponíveis na porta serial
  if (millis() > 20000) {
    // Lê o caractere recebido pela porta serial
    char entrada = Serial.read();
    
    // Se o caractere recebido for um espaço, define a variável 'girar' como true
    if (entrada == ' ') {
      girar = true;
    }
  }

  // Se a variável 'girar' estiver como true
  // gira o servo 30 graus e retorna à posição inicial
  if (girar) {
    int posicaoFinal = posicaoInicial + grausGirados;

    // Move o servo para a nova posição
    meuServo.write(posicaoFinal);
    delay(1000);

    // Move o servo para a posição inicial
    meuServo.write(posicaoInicial);
    delay(1000);
    
    // Reseta a variável 'girar' para false
    girar = false;
  }
}
