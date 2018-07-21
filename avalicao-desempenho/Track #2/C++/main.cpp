#include <climits>
#include <cstdint>
#include <iostream>
 
using namespace std;

void ClearScreen() {
int n;
for (n = 0; n < 10; n++)
  printf( "\n\n\n\n\n\n\n\n\n\n" );
}

int main(void) {
	ClearScreen();
	
	clock_t t_inicial, t_final;
	
	unsigned long t,z;
	float soma=0.0, media=0.0;
	int n = 10;
	FILE *fp;
	
	fp = fopen("arq1.txt","w+");
	
	for(int i = 0; i < n; i++) {
		t_inicial = clock(); 
		
		for(int j = 0; j < 10000000; j++)
		    int nothing = rand() % 100;
		
		t_final = clock(); 
		soma = soma + ((t_final - t_inicial) / CLOCKS_PER_SEC);
		
		printf ("O laço precisou de %f segundos.\n",(t_final - t_inicial),((float)(t_final - t_inicial))/CLOCKS_PER_SEC);
	}
	
	media = soma/n;
	
	cout << "\nA media é " << media << " segundos." ;
	fclose(fp);
	
	return 0;
}