#include <Servo.h>

Servo meuServo;  // Cria um objeto do tipo Servo
int posicaoInicial = 90;  // Posição inicial do servo motor
int grausGirados = -90;    // Quantos graus vamos girar o servo motor
bool girar = false;  // Variável para controlar se o servo deve girar

void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial
  meuServo.attach(9);   // Define o pino ao qual o servo está conectado (no meu caso, é o pino 9)
  meuServo.write(posicaoInicial);  // Move o servo para a posição inicial
  delay(1000);  // Aguarda 1 segundo
}

void loop() {
  // Verifica se há dados disponíveis na porta serial
  if (Serial.available() > 0) {
    // Lê o caractere recebido pela porta serial
    char entrada = Serial.read();
    
    // Se o caractere recebido for um espaço, define a variável 'girar' como true
    if (entrada == ' ') {
      girar = true;
    }
  }

  // Se a variável 'girar' estiver como true, gira o servo 30 graus e retorna à posição inicial
  if (girar) {
    int posicaoFinal = posicaoInicial + grausGirados;
    meuServo.write(posicaoFinal);  // Move o servo para a nova posição
    delay(1000);  // Aguarda 1 segundo

    meuServo.write(posicaoInicial);  // Move o servo para a posição inicial
    delay(1000);  // Aguarda 1 segundo
    
    girar = false;  // Reseta a variável 'girar' para false
  }
}
