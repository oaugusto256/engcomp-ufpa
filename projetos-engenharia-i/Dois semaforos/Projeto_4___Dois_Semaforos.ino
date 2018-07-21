// Semáforo para duas Avenidas //

// Trafico de luz na avenida A
int avenidaAVermelho = 10;
int avenidaAAmarelo  =  9;
int avenidaAVerde    =  8;

// Trafico de luz na avenida B
int avenidaBVermelho =  2;
int avenidaBAmarelo  =  3;
int avenidaBVerde    =  4;

// Entrada de parametros da função void
void setup(){
  
// Parametros para os pinos da Avenida A    
  pinMode(avenidaAVermelho, OUTPUT);
  pinMode(avenidaAAmarelo, OUTPUT);
  pinMode(avenidaAVerde, OUTPUT);

// Parametros para os pinos da Avenida B
  pinMode(avenidaBVermelho, OUTPUT);
  pinMode(avenidaBAmarelo, OUTPUT);
  pinMode(avenidaBVerde, OUTPUT);
}

void abrirAvenidaA(){
  digitalWrite(avenidaAVermelho, LOW);
  digitalWrite(avenidaAAmarelo, LOW);
  digitalWrite(avenidaAVerde, HIGH);
}

void fecharAvenidaA(){
  digitalWrite(avenidaAVermelho, HIGH);
  digitalWrite(avenidaAAmarelo, LOW);
  digitalWrite(avenidaAVerde, LOW);
}

void PrepararparafecharAvenidaA(){
  digitalWrite(avenidaAAmarelo, HIGH);
  digitalWrite(avenidaAVerde, LOW);
  delay(500);
  digitalWrite(avenidaAVerde,HIGH);
  delay(500);
  digitalWrite(avenidaAVerde, LOW);
  delay(500);
  digitalWrite(avenidaAVerde,HIGH);
  delay(500);
  digitalWrite(avenidaAVerde, LOW);
  delay(500);
  digitalWrite(avenidaAVerde,HIGH);
  delay(500);
  digitalWrite(avenidaAVerde, LOW);
}

void abrirAvenidaB(){
  digitalWrite(avenidaBVermelho, LOW);
  digitalWrite(avenidaBAmarelo, LOW);
  digitalWrite(avenidaBVerde, HIGH);
}

void PrepararparafecharAvenidaB(){
  digitalWrite(avenidaBAmarelo, HIGH);
  digitalWrite(avenidaBVerde,HIGH);
  delay(500);
  digitalWrite(avenidaBVerde,LOW);
  delay(500);
  digitalWrite(avenidaBVerde,HIGH);
  delay(500);
  digitalWrite(avenidaBVerde,LOW);
  delay(500);
  digitalWrite(avenidaBVerde,HIGH);
  delay(500);
  digitalWrite(avenidaBVerde,LOW);
  delay(500);
}

void fecharAvenidaB(){
  digitalWrite(avenidaBVermelho, HIGH);
  digitalWrite(avenidaBAmarelo, LOW);
  digitalWrite(avenidaBVerde, LOW);
}

void loop(){
  abrirAvenidaA();
  fecharAvenidaB();
  delay(5000);
  
  PrepararparafecharAvenidaA();
  delay(3500);
  
  fecharAvenidaA();
  abrirAvenidaB();
  delay(5000);
  
  PrepararparafecharAvenidaB();
  delay(3500);
  
}
