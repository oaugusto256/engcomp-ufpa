#include <stdio.h>
#include <stdlib.h>

struct data{
       int dia;
       int mes;
       int ano;
       };

int main(){
    struct data dados;
    int meses[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int diasdomes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i,m,totaldias1,auxmes,auxdia,totaldias2 = 0,diferenca;
    int mesvalido = 1;
    
    printf("\t\t -- VERIFICACAO CORRETA DE DATA --\n");  // Abaixo esta um loop para setagem manual da quantidade de dias de cada mes 
    /*
    printf("\nDigite os numeros dos meses em ordem crescente: ");
    
    for(i=0;i<12;i++){
        printf("\nDigite o numero do %d mes: ",i+1);         
        scanf("%d", &mes[i]);
        printf("\nDigite a quantidade de dias do %d mes: ",i+1);         
        scanf("%d", &diasdomes[i]);
                    if(i == 11){
                         printf("\n -- LEITURA DE DIAS E MESES COMPLETA ! --");
                         system("PAUSE");
                         system("cls");
                         }
        }
    
    */
    // Loop paa contar a quantidade de dias
    
    totaldias1 = 21;
    for(i=0;i<5;i++){
        totaldias1 = totaldias1 + diasdomes[i];
        }
    
    //Loop para verificar se a data esta correta como estabelecido 21/06/1985  e seu flag 00/01/0000
    
    while(dados.dia != 0  || dados.mes != 1 || dados.ano != 0){
          printf("\nDigite o dia da sua data: ");
          scanf("%d", &dados.dia);
          printf("Digite o mes: ");
          scanf("%d", &dados.mes);
          printf("Digite o ano: ");
          scanf("%d", &dados.ano);
          
          
       if(dados.ano == 1985){
           m = 0;
           while(dados.mes != meses[m] && m != 12){
                 m = m+1;
                 }         
           
           if(dados.mes != meses[m]){
                     mesvalido == 0;   
                     }
                      
           if(mesvalido == 1){
                  if(dados.dia >= 0 && dados.dia <= diasdomes[m]){
                     totaldias2 = dados.dia;
                     i=0;
                     while(i != m){
                       totaldias2 = totaldias2 + diasdomes[i];
                       i++;
                       }
                     
                     diferenca = totaldias1 - totaldias2;
                           printf("\nA data fornecida fornecida foi:  %d/%d/%d", dados.dia, dados.mes, dados.ano);
                           printf("\nDiferenca de dias da data fornecida para o dia 21: %d\n", diferenca);

                   }else{
                        printf("\nA data fornecida fornecida foi:  %d/%d/%d", dados.dia, dados.mes, dados.ano);
                        printf("\n\nData Incorreta!\n");
                        }
               }else{
                    printf("\nA data fornecida fornecida foi:  %d/%d/%d", dados.dia, dados.mes, dados.ano);
                    printf("\nData Incorreta!\n");
                    }
           }else{
               printf("\nA data fornecida fornecida foi:  %d/%d/%d", dados.dia, dados.mes, dados.ano);
               printf("\nData Incorreta!\n");
               }          
          
          system("PAUSE");
          system("cls");
          printf("\t\t -- VERIFICACAO CORRETA DE DATA --\n");
          }
             
    system("PAUSE");
    return(0);
    }
