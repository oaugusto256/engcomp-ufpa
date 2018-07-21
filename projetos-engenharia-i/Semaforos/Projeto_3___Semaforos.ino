// Semáforo //

// Trafico de luz na avenida A
int avenidaAVermelho = 8;
int avenidaAAmarelo  =  9;
int avenidaAVerde    =  10;

void setup(){
   
  pinMode(avenidaAVermelho, OUTPUT);
  pinMode(avenidaAAmarelo, OUTPUT);
  pinMode(avenidaAVerde, OUTPUT);

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
  digitalWrite(avenidaAVerde ,LOW);
  delay(500);
  digitalWrite(avenidaAVerde, HIGH);
  delay(500);
  digitalWrite(avenidaAVerde, LOW);
  delay(500);
  digitalWrite(avenidaAVerde, HIGH);
  delay(500);
  digitalWrite(avenidaAVerde, LOW);
  delay(500);
}

void loop(){
  abrirAvenidaA();  
  delay(5000);
  PrepararparafecharAvenidaA();
  delay(1500);
  fecharAvenidaA();
  delay(5000);
}
