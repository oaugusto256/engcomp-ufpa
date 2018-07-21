int ponto=9;
int botao=13;
int st=0;
int pins[16][8]= { 
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
  
  

void setup()
{
pinMode(2, OUTPUT); 
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(ponto, OUTPUT);
pinMode(botao, INPUT);

  
}

void numeros(int num)
{
  int pin=2;
  for (int ct=0; ct<7; ct++)
  {
    digitalWrite(pin, pins[num][ct]);
    pin++;
  }
}
void loop() 
{
  contador();
}

void contador()
{
  crescente(st);
  
}

int crescente(int cresc)
{
  for(byte count = cresc; count < 16; count++)
  {
    numeros(count);
    delay(1000);
    int state = digitalRead(botao);
    if(state == HIGH)
    {
      st=count;
      break;
    }
    if(count==15)
    {
      count=-1;
    }
  }
  decrescente(st);
}


int decrescente(int decresc)
{
  for(byte count = decresc; count > 0; count--)
  {
    numeros(count - 1);
    delay(1000);
    int state = digitalRead(botao);
    if(state == HIGH)
    {
      st = count;
      break;
    }
    if(count==1)
    {
      count=17;
    }
  }
  crescente(st);
}
