#include <SoftwareSerial.h> // biblioteca externa do arduino

// criando um objeto chamado BT usando a biblioteca, onde:
// pino 10 = RX do Arduino (recebe dados do módulo)
// pino 11 = TX do Arduino (envia dados para o módulo)
SoftwareSerial BT(10, 11);


#define pinMotor1A 2   // pino ligado no motor 1 (lado A), no caso(IN1) e eles também correspondem às letras(vd)
#define pinMotor1B 4   // pino ligado no motor 1 (lado B), no caso(IN2), letras(az)
#define pinMotor2A 3   // pino ligado no motor 2 (lado A), no caso(IN3), letras(br)
#define pinMotor2B 5   // pino ligado no motor 2 (lado B), no caso(IN4), letras(cz)
// aq n tem o ENA e nem o ENB pois tem um "jumper" preto pequeno q deixa ligado o tempo todo a passagem da corrente,
// por isso n é preciso colocar as entradas para os dois pinos

// variável que vai armazenar o comando recebido pelo bluetooth
char mensagem = "Paralelepipedo";

void setup() {
    Serial.begin(9600); // habilita comunicação USB do Arduino com o computador
    BT.begin(9600);     // habilita comunicação serial com o módulo Bluetooth

    
    pinMode(pinMotor1A, OUTPUT);
    pinMode(pinMotor1B, OUTPUT);
    pinMode(pinMotor2A, OUTPUT);
    pinMode(pinMotor2B, OUTPUT);
}

void loop() {
    // esse while só roda quando existe algo disponível para ler na porta bluetooth
    while (BT.available() > 0) {

        mensagem = BT.read(); // lê o caractere enviado pelo celular
        Serial.println(mensagem); // mostra no monitor serial (debug)

        // o switch escolhe qual função executar de acordo com
        // a letra enviada pelo bluetooth
        // nesse caso, a letra enviada está associada a uma letra do app(arduino bluetooth control)
        // letras do app( F(seta pra cima), B(seta pra trás), R(seta pra direita), L(seta pra esquerda), S(padrão para parar os motores))
        switch(mensagem) {

            case 'F':   // F = ir para frente
                // Motor 1 gira no sentido horário
                digitalWrite(pinMotor1A, HIGH);
                digitalWrite(pinMotor1B, LOW);
                // Motor 2 gira no sentido anti-horário
                digitalWrite(pinMotor2A, LOW);
                digitalWrite(pinMotor2B, HIGH);
                break; // usado para saidar do condicional do case, pois se n ele continua lendo o case "b", "R" e etc

            case 'B':   // B = ir para trás
                digitalWrite(pinMotor1A, LOW);
                digitalWrite(pinMotor1B, HIGH);
                digitalWrite(pinMotor2A, HIGH);
                digitalWrite(pinMotor2B, LOW);
                break;

            case 'R':   // R = virar para a direita
                // Motor 1 para
                digitalWrite(pinMotor1A, LOW);
                digitalWrite(pinMotor1B, LOW);
                // Motor 2 gira para puxar o carrinho para a direita
                digitalWrite(pinMotor2A, HIGH);
                digitalWrite(pinMotor2B, HIGH);
                break;

            case 'L':   // L = virar para a esquerda
                // Motor 1 gira
                digitalWrite(pinMotor1A, HIGH);
                digitalWrite(pinMotor1B, HIGH);
                // Motor 2 para
                digitalWrite(pinMotor2A, LOW);
                digitalWrite(pinMotor2B, LOW);
                break;

            case 'S':   // S = parar tudo
                digitalWrite(pinMotor1A, LOW);
                digitalWrite(pinMotor1B, LOW);
                digitalWrite(pinMotor2A, LOW);
                digitalWrite(pinMotor2B, LOW);
                break;
        }
    }
}
