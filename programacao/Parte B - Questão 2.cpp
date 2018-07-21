#include <stdio.h>
#include <stdlib.h>

int main(){
    int voos[10],ldispi[10],ldispf[10],ldispti=0,ldisptf=0;
    int aviao[10],rg=1,nvoo,aux,i;
    float preco[10];
    
    printf("\t-- CONTROLE DE RESERVAS DE PASSAGEM DE VOOS -- ");
    
    // Loop para leitura dos dados dos 10 voos 
   
    for(i=0;i<10;i++){
       printf("\n\t\t-- LEITURA DE DADOS DO %d VOO --",i+1);
       printf("\n\nDigite o numero  do %d voo: ", i+1);
       scanf("%d", &voos[i]);
       printf("Digite o tipo do aviao do %d voo: ", i+1);
       scanf("%d", &aviao[i]);
       
       // Loop para verificação se tipo de avião é aceitavel e estipulação de capacidade             
       
          while(aviao[i]!=707 || aviao[i]!=727 || aviao[i]!=737){
                  printf("\nTipo de aviao invalido !\n");
                  printf("Digite o tipo do aviao do %d voo: ", i+1);
                  scanf("%d", &aviao[i]);
                  };
       
                  if(aviao[i] == 707){
                       ldispi[i] = 200;
                       ldispf[i] = 200;
                       }
                  if(aviao[i] == 727){
                       ldispi[i] = 170;
                       ldispf[i] = 170;
                       }
                  if(aviao[i] == 737){
                       ldispi[i] = 120;
                       ldispf[i] = 120;
                       }
       
       // Fim do lopp verificação do tipo do avião e estipulação da capacidade total
                  
                  printf("Digite o preco da passagem do %d voo: ",i+1);
                  scanf("%f", &preco[i]);
                  printf("\n\n\t\t-- LEITURA DE DADOS DO %d VOO FINALIZADA! --\n", i+1);
                       if(i==9){
                                printf("\n\t\t-- LEITURA DE DADOS DE TODOS OS %d VOO COMPLETA ! --\n",i+1);
                                system("PAUSE");
                                system("cls");
                                }else{
                                     system("PAUSE");
                                     system("cls");
                                     }
                  }
       
       for(i=0;i<10;i++){
           ldispti = ldispti + ldispi[i];
           ldisptf = ldisptf + ldispi[i];
           }
       
       // Fim do loop para leitura dos 10 voos
       
       printf("\t\t-- LUGARES DISPONIVEIS --\n");
       for(i=0;i<10;i++){
                        printf("\nLugares disponiveis no %d voo: %d\n", i+1,ldispi[i]);
                        printf("Tipo do aviao do %d voo: %d\n", i+1,aviao[i]);
                        
                        if(i == 9){
                             printf("\n\n-- TOTAL DE LUGARES DISPONIVEIS --: %d", ldispti);
                             printf("\n");
                             }
                        }
       system("PAUSE");
       system("cls");
       
      // Loop para pedido de reservas  
      while(rg != 0){
         printf("\t\t -- PEDIDO DE RESERVAS -- ");
         printf("\n\nDigite a RG do cliente: ");
         scanf("%d", &rg);
         printf("Digite o numero de voo: ");
         scanf("%d", &nvoo);
         
         i=0;
         while(i!=10 && voos[i] != nvoo){
               i++;     
               }                 
         if(voos[i] == nvoo){
                    aux = i;
                    if(ldispf[aux]> 0){
                        printf("\nRG do cliente : %d    Numero de Voo:  %d", rg, nvoo);
                        printf("\nPreco da passagem : %3.2f", preco[aux]);
                        printf("\n\t\t -- RESERVA CONFIRMADA -- ");
                        ldispf[aux] = ldispf[aux]-1;
                        ldisptf = ldisptf - 1;
                        printf("\nTotal de lugares disponiveis na companhia: %d", ldisptf);
                        printf("\nTotal de lugares disponiveis restantes no %d voo: %d\n", i+1,ldispf[aux]);
                        system("PAUSE");
                        system("cls");
                        }else{
                              printf("\nRG do cliente : %d    Numero de Voo:  %d", rg, nvoo);
                              printf("\n-- VOO LOTADO ! --\n");
                                      }
            }else{
               printf("\n -- VOO NAO EXISTE ! -- !\n");
                          
                          aux = 0;
                          }

         }
    system("PAUSE");
    system("cls");
    // Fim do loop para pedidos de reserva
    
    // Loop para imprimir estatitica de lucros e prejuizos de cada voo
    
    for(i=0;i<10;i++){
       printf("\t\t-- ESTATISTICA DO %d VOO --\n",i+1);
       if(ldispf[i] < ldispi[i]*(0.6)){
                    printf("\nVoo %d  obtve lucro !\n",i+1);
                    system("PAUSE");
                    system("cls");
                    }else{
                          printf("\nVoo nao %d obtve lucro !\n",i+1);
                          system("PAUSE");
                          system("cls");
                          }
                    }
    
    // Fim do loop para Lucros e prejuizos de cada voo
    
    // Impressão de estatistica total do voo
    
    printf("\t\t-- ESTATISTICA TOTAL DA COMPANHIA --\n",i+1);
    if(ldisptf < ldispti*(0.6)){
                  printf("\nCompanhia de voos obteve Lucro !\n");
                 }else{
                       printf("\nCompanhia de voos nao obteve Lucro !\n");
                       }
    
    system("PAUSE");
    return(0);
    }
