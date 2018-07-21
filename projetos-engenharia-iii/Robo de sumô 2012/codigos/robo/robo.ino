#include <Ultrasonic.h>

#define RELAY1  11
#define RELAY2  10
#define RELAY3  9
#define RELAY4  8

#define trigger 5
#define echo 4

int pinoSensorDireito = A0;
int pinoSensorEsquerdo = A1;

int valorSensorDireito = 0;
int valorSensorEsquerdo = 0;
int valorPreto;

/** --------------------------------- SEÇÃO DE MULTITAREFA -------------------------------------- **/
struct Timer  
{  
 unsigned long start;     // Armazena o tempo de quando foi iniciado o timer  
 unsigned long timeout;   // Tempo após o start para o estouro  
};
  
unsigned long Now ( void )  {  
 return millis ( );       //Retorna os milisegundos depois do reset  
}

 // Verifica se o timer estourou    
boolean TimerEstorou (struct Timer * timer) {  
 if ( Now () > timer->start + timer->timeout) {  
   return true;  
 }  
 return false;   
}
 
// Após o tempo estourar temos que iniciar o timer com o tempo atual  
void timerStart(struct Timer * timer ){  
  timer->start = Now();  
}
  
void timerDesloc(struct Timer * timer, unsigned long tempo) {  
  timer->start = Now()+tempo;  
}
  
Timer timerBorda = {0, 10};     // Verifica se achou a borda a cada 10 milisegundos  
Timer timerAchou = {0, 100};    // verifica se achou o oponente a cada 100 milisegundos  
Timer timerFrente = {0, 800};   // Tempo que o robô passa indo pra frente  
Timer timerGira = {0, 3250};    // Tempo que o robô passa girando para frente
Timer timerfinal = {0, 85000};  // Tempo de 1:30 minutos, final do round  
boolean sentidoGiro=true;       // Variável criada para o robô girar hora pra direita, hora pra esquerda 

/** --------------------------------- SEÇÃO DE PREPARAÇÃO -------------------------------------- **/
void setup() {
  Serial.begin(9600);
  
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  digitalWrite(trigger, LOW);

  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
  digitalWrite(RELAY3, LOW);
  digitalWrite(RELAY4, LOW);

  calibrar();
  
  delay(5000);

  timerFrente.start= Now() - timerFrente.timeout; // Atrasamos o Start do tempo de ir pra frente de modo ao robô começar a luta indo pra frente.  
  timerGira.start= Now();  
  timerAchou.start= Now(); 
}

/** --------------------------------- SEÇÃO DE LOOP -------------------------------------- **/
int i = 0;
void loop(){
  if(TimerEstorou(&timerfinal)){  
    while(1)  
     parado();          // Função a ser chamada no final de cada round. Se o robô continuar andando isso caracteriza punição.
  } 
   
  if(i=0){  
    timerStart(&timerBorda);  
    timerStart(&timerGira);  
    timerStart(&timerAchou);  
    i+=1;  
  }  
   
  if(TimerEstorou(& timerFrente)){  
    andaFrente();  
    timerStart(& timerFrente);    
  }  
   
  if(TimerEstorou(& timerBorda)){  
    if(achouLinha()){                 // Verifica se achou a borda.
     andaTras();  
     delay(1000);                     // Delay de sobrevivência.  
     timerStart(& timerFrente);       // Colocar o timer frente no início de seu ciclo.
     timerDesloc(& timerGira, -timerGira.timeout); // Faz com que o robô gire.
     timerStart(& timerAchou);  
    }  
    timerStart(& timerBorda);  
   }  

   if(TimerEstorou(& timerAchou)){  
    if(achouOponente()){  
     andaFrente();  
     timerStart(& timerGira);  
    }  
    timerStart(& timerAchou);  
   }  
   
   if(TimerEstorou(& timerGira)){  
    if(sentidoGiro){  
     giraDireita();  
     sentidoGiro=!sentidoGiro;  
    }  
    else  
    {  
     giraEsquerda();  
     sentidoGiro=!sentidoGiro;  
    }  
    timerStart(& timerGira);  
   } 
}

/** --------------------------------- SEÇÃO DE MOVIMENTAÇÃO -------------------------------------- **/
void parado() {
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
  digitalWrite(RELAY3, LOW);
  digitalWrite(RELAY4, LOW);
}

void andaFrente() {
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, LOW);
  digitalWrite(RELAY4, HIGH);
}

void andaTras() {
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, LOW);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, LOW);
}

void giraDireita() {
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, LOW);
}

void giraEsquerda() {
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, LOW);
  digitalWrite(RELAY3, LOW);
  digitalWrite(RELAY4, HIGH);  
}

/** --------------------------------- SEÇÃO DE CALCULO DE DISTANCIA -------------------------------------- **/
float distanciaOponente() {  
  float tempo, dist;  
  digitalWrite(trigger, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigger, LOW);  
 
  tempo = pulseIn(echo, HIGH);  
  dist = tempo / 29.4 / 2;

  return dist;  
}

void calibrar() {
   valorSensorDireito = analogRead(pinoSensorDireito);
   valorSensorEsquerdo = analogRead(pinoSensorEsquerdo);

   valorPreto = (valorSensorDireito + valorSensorEsquerdo)/2;
}

boolean achouLinha() {
   valorSensorDireito = analogRead(pinoSensorDireito);
   valorSensorEsquerdo = analogRead(pinoSensorEsquerdo);
   
  if((valorSensorDireito > valorPreto+125) || (valorSensorEsquerdo > valorPreto+125))
    return true; 
  else 
    return false;
}

boolean achouOponente() {
  if(distanciaOponente() < 45)
    return true;
  else
    return false;
}




