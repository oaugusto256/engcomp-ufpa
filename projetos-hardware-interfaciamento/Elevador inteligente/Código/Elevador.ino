#include "Ultrasonic.h"

#define RELAY1  11
#define RELAY2  10
#define ECHOPIN 13 //Pino 13 recebe o pulso
#define TRIGPIN 12 //Pino 12 envia o pulso

byte botoes[] = {2, 3, 4, 5, 6};
int qntdBotoes = 5;

Ultrasonic ultrasonic(12,13); //gera um objeto ultrasonic para a medida da distancia

void setup() {
  // put your setup code here, to run once:
  byte i;
  
  Serial.begin(9600);
  
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);

  for (i=0; i < qntdBotoes; i++) pinMode(botoes[i], INPUT_PULLUP); //Leitura de cada pino setado para HIGH

}

void loop() {
  // put your main code here, to run repeatedly:
  apertaBotao();
}

void parar() {
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
}

void subir() {
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, LOW);
}

void descer() {
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, HIGH);
}

/*----------CALCULO DA DISTANCIA/ALTURA-----------*/
float distancia() {
  digitalWrite(TRIGPIN, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(TRIGPIN, LOW);

  int dist = (ultrasonic.Ranging(CM)); //retorna a distancia em CM
  return dist;
}
 /*----------CONFIGURAÇÃO DOS BOTOES--------------*/
void apertaBotao() {
  byte i;
  float distAndar = 0;
  for(i=0; i < qntdBotoes; i++) { //Leitura de cada botão, para verificação de qual será pressionado
    if(digitalRead(botoes[i] == LOW)) {
      distAndar += 15*i; //COmo cada andar tem uma diferença de 15 cm, distAndar calcula a altura em que o elevador deverá estar de acordo com o botão pressionado
    }
  }
  //verifica se o elevador está acima ou abaixo do andar onde o botão foi pressionado para, assim, poder subir ou descer
  if(distancia() < distAndar) {
    while(distancia() < distAndar) {
      subir();
    }
    parar();
  } else {
    while(distancia() > distAndar) {
      descer();
    }
    parar();
  }  
}

