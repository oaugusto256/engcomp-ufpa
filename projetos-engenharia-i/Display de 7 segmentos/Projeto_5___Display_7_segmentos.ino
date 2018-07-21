int botao = 13;
int aux;
byte sete_seg[16][8] = { 
{ 1,1,1,1,1,1,0,1 }, // = 0
{ 0,1,1,0,0,0,0,1 }, // = 1
{ 1,1,0,1,1,0,1,1 }, // = 2
{ 1,1,1,1,0,0,1,1 }, // = 3
{ 0,1,1,0,0,1,1,1 }, // = 4
{ 1,0,1,1,0,1,1,1 }, // = 5
{ 1,0,1,1,1,1,1,1 }, // = 6
{ 1,1,1,0,0,0,0,1 }, // = 7
{ 1,1,1,1,1,1,1,1 }, // = 8
{ 1,1,1,0,0,1,1,1 }, // = 9
{ 1,1,1,0,1,1,1,0 }, // = A
{ 0,0,1,1,1,1,1,0 }, // = B
{ 1,0,0,1,1,1,0,0 }, // = C
{ 0,1,1,1,1,0,1,0 }, // = D
{ 1,0,0,1,1,1,1,0 }, // = E
{ 1,0,0,0,1,1,1,0 }, // = F
};

void setup() { 
pinMode(2, OUTPUT); 
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(13, INPUT);

}


void loop() 
{
  cres();
}


void escrita(byte linha){
  byte pin = 2;
  for (byte coluna = 0; coluna < 8; ++coluna)
  {
      digitalWrite(pin, sete_seg[linha][coluna]);
      ++pin;
  }
}



void cres(){
  for (byte count = 1; count < 17; ++count)
  {
    int state = digitalRead(botao);
    if(state == HIGH){
    aux = count;
    decres();
    }
    delay(1000);
    escrita(count - 1);
  }
}

void decres(){
  for (byte count = aux; count > 0; --count)
  {  
    int state = digitalRead(botao);
    if(state == HIGH){
    cres();
    }
    delay(1000);
    escrita(count - 1);
  }
}
