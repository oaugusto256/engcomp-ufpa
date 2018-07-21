# include <stdio.h>
# include <stdlib.h>
# include <string.h>   // Biblioteca de strings 
# define  TAM 100000


int main(){
    int x,tam,quanta=0,quantb=0;
    char cad[TAM],posa,posb;
    
    printf("\t\t --VERIFICAR O BALANCEAMENTO DE UMA CADEIA DE CARACTERES --\n");
    printf("\nDigite a cadeia de caracteres: "); 
    fgets(cad,TAM,stdin);
    
    tam = strlen(cad);
    for(x=0; x < tam ; x++){
             if(cad[x] == '$'){
                    x = tam +1;   
                       }
             if(cad[x] == '('){
                       posa = x;
                       quanta += 1;
                       }
             if(cad[x] == ')'){
                       posb = x;
                       quantb += 1;
                       }        
         }
             
    if(quanta == quantb && posb >= posa){
              printf("\nCadeia e balanceada !\n");
              }else{
                    printf("\nCadeia nao e balanceada !\n");
                    }   
           
    
    system("PAUSE");
    return(0);
    }
