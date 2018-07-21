#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

int main(){
/*  Criação das variaveis para realização do programa, onde:
    i : O limite de contagem dos vetores h[n] e f[n]
    n : A quantidade de alunos 
    h[n] : Vetor contendo as medias do ens. medio
    f[n] : Vetor contendo as medias do ens. superior
    s1 a s5 : Funções somatorio da formula que foi dada
*/
    int i,n;
    float r,h[MAX],f[MAX],s1=0,s2=0,s3=0,s4=0,s5=0,s6;

// Apresentação do programa e sua funcionalidade
    
    printf("\t\t--CALCULO DE COEFICIENTE DE CORRELACAO--\n");
    printf("\nEntre com medias do ens. medio e media primeiro ano do ens. superior de N alunos\n\n");

// Leitura da quantidade de alunos envolvidos
    
    printf("Digite o numero de alunos que estaram envolvidos,menores ou igual a 100: ");
    scanf("%d", &n);
    getchar();
    
// Leitura dos valores das medias do ens. medio e superior
    
    for(i=0;i<n;i++){
                     printf("\nDigite a media do ensino medio para o %d aluno: ", i+1);
                     scanf("%f", &h[i]);
                     printf("Digite a media do ensino superior para o %d aluno: ", i+1);
                     scanf("%f", &f[i]);
                     }
    
// Implementação das medias do ens. superior e medio na somatoria

   for(i=0;i<n;i++){
                     s1=s1 + h[i]*f[i];
                     s2=s2 + h[i];
                     s3=s3 + f[i];
                     s4=s4 + h[i]*h[i];
                     s5=s5 + f[i]*f[i];
                     }
   
   s1 = n*s1;
   s4 = n*s4;
   s5 = n*s5;
   s6 = sqrt((s4 - s2*s2)*(s5 - s3*s3));
 
// Formula para calcular o coeficiente de correlação
   
    r = (s1 - (s2*s3))/s6;
    
    printf("\nO valor de do coeficiente de correlacao: %3.4f", r);

            
    printf("\n");
    system("PAUSE");
    return(0);
    }
