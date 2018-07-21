# include <stdio.h>
# include <stdlib.h>
# include <string.h>   // Biblioteca de strings 
# define  TAM 100000

int main(){
    int x,y,tam;
    char cad[TAM];
    
    printf("\t\t --COMPRESSAO DE ESPACOS DE UMA CADEIA DE CARACTERES --\n");
    printf("\nDigite a cadeia de caracteres: "); 
    fgets(cad,TAM,stdin);
    
    tam = strlen(cad);
    for(x=0; x < tam ; x++){
             while(cad[x] == ' ' && cad[x+1] == ' '){
                   for(y=x; y < tam; y++){
                       cad[y] = cad[y+1];
                       }
                   } 
             if(cad[x] == '.'){
                       x += tam;
                       }
             putchar(cad[x]);
             }

    
    system("PAUSE");
    return(0);
    }
