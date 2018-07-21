#include <stdio.h>
#include <stdlib.h>

int main(){
    int troco,valorc,n,aux;

// Valores iniciais da quantidade de moedas e seus respectivos valores em centavos    
    
    int quant[4]={0,0,0,0};
    int m[4]={25,10,5,1};

    printf("\t\t-- CALCULO DE TROCO EM MOEDAS --");
    printf("\n\nEntre com o valor da compra: ");
    scanf("%d", &valorc);
    troco = 100 - valorc;
    aux = troco;

// Loop para verificação se o valor da compra é aceitavel  
    if(valorc > 100 || valorc <= 0){
              do{    
                 printf("O valor da compra devera ser menor ou igual a 100 centavos e maior que zero!\n");
                 printf("\nEntre com o valor da compra: ");
                 scanf("%d", &valorc);
                 troco = 100 - valorc;
                 aux = troco;
              }while(valorc > 100 || valorc < 0);
    }
    
// Uso de funções do sistema para melhor organização    
    printf("O valor da compra valido !\n");
    system("PAUSE");
    system("cls");
    getchar();

// Verificação se será necessario uso de moedas de 25 centavos no troco
    if(aux >= m[0]){
          n = 0;    
          while(aux >= m[0]){
                n++;
                aux = aux - m[0];
                } 
          quant[0] = n;     
          }
//  Verificação se será necessario uso de moedas de 10 centavos no troco

     if(aux >= m[1]){
          n = 0;
          while(aux >= m[1]){
                n++;
                aux = aux - m[1];
                }           
          quant[1] = n;
          }
//  Verificação se será necessario uso de moedas de 5 centavos no troco          
          if(aux >= m[2]){
          n = 0;
          while(aux >= m[2]){
                n++;
                aux = aux - m[2];
                }           
          quant[2] = n;
          }
  
// Verificação se será necessario uso de moedas de 1 centavo no troco    
    if(aux >= m[3]){
          n = 0;
          while(aux >= m[3]){
                n++;
                aux = aux - m[3];
                }
          quant[3] = n;
          }  

// Amostragem dos resultados obtidos
    printf("\t\t-- TROCO -- ");
    printf("\n\nValor da compra: %d centavos.\n", valorc);
    printf("Valor do troco: %d centavos.\n\n", troco);
    printf("  %d moedas de 25 centavos. \n\n", quant[0]);    
    printf("  %d moedas de 10 centavos. \n\n", quant[1]);
    printf("  %d moedas de 5 centavos. \n\n", quant[2]);     
    printf("  %d moedas de 1 centavos. \n\n", quant[3]);
    
    system("PAUSE");
    return(0);
    }
