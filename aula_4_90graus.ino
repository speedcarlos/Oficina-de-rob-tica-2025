// Pinos Motor A
int ENA = 13;
int IN1 = 12;
int IN2 = 11;

// Pinos Motor B
int IN3 = 10;
int IN4 = 9;
int ENB = 8;

int tempo_90 = 290;

// uma função tem q ser feita antes dos compiladores(setup e loop), para dar tempo de ser chamada, lida e entendida pelo sistema(C++/arduino)
// essa foi função feita para ajustar a velocidade dos motores, no caso ir para frente, para ir para trás é só ajustar a direção do giro
void frente() {
  analogWrite(ENA, 255); // velocidade máxima
  analogWrite(ENB, 255); // velocidade máxima
  delay(100); // tempo que os motores tem q girar na velocidade máxima
  zerar(); // função criada depois para zerar os motores, pq se não eles ficam girando enquanto tiver o delay
}

void virar() {
  analogWrite(ENA, 255); // velocidade máxima
  analogWrite(ENB, 0); // velocidade nula, ent o motor vai parar
  delay(tempo_90); // tempo q faz o carrinho girar aproximadamente 90 graus, foi obtido por meio de testes
  zerar(); // função criada depois para zerar os motores, pq se não eles ficam girando enquanto tiver o delay
}

void zerar() {
  analogWrite(ENA, 0); // velocidade nula
  analogWrite(ENB, 0); // velocidade nula
}

void setup() { // passando as entradas(output)
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  // falando o sentido q devem girar, nesse caso seria o sentido horário para ambos
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(5000); // 5s para esparar antes de começar, sem ele a função já é executada logo no início
  frente(); // função para seguir reto
  delay(2000); // se zerar(); n fosse usada ele ainda estaria indo para frente durante esses dois segundos de espera pois o código n teria mudado
  virar(); // função para girar aproximadamente 90 graus
  delay(2000);// se zerar(); n fosse usada ele ainda estaria virando durante esses dois segundos de espera pois o código n teria mudado
  frente();
  delay(2000);
  virar();
  delay(2000);
  frente();
  delay(2000);
  virar();
  delay(2000);
  frente();
  delay(2000);
  virar();
  delay(2000);
  zerar();

}
