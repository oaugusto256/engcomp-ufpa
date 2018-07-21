#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

double f(double y);

int main(){
    int i,n;
    float aux[MAX],aux2[MAX],x,a,b,h,pi;
    
    printf("\t\t-- CALCULO DO VALOR DE PI --");
    
    printf("\n\nDigite os limites de integracao, inicial e final,respectivamente: ");
    scanf("%f%f", &a,&b);

    printf("\nDigite o passo do intervalo de integracao: ");
    scanf("%f", &h);

    x = a+h; // Primeira posição 
    n = (b-a)/h;  // Numero de intervalos de Integração

    // Loop para receber todos os valores da função f(x) em aux em todos os 'n' intervalos
    
    for(i=0;i<n;i++){
        aux[i]=f(x);
        x += h;
       }

    // Loop calcular o valor de pi
    
    for(i=0;i<n;i++){
        aux2[i]= ((aux[i]+aux[i+1])/2)*h;
        pi += aux2[i];
        }
    
    // Amostragem do resultado de pi

    printf("\nO valor de pi e igual a: %f\n", 4*pi);

    system("PAUSE");
    return(0);
    }

double f(double x){
       double y;
       y = 1/(1+(x*x));
       return y ;
      }

