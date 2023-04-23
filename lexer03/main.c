#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum token {
	Mais = '+',
	Menos = '-',
	Vezes = '*',
	Divisão = '/'
}tokens;

typedef struct {
	char token;
	char valor;
}caracteres;



int potencia (int casa, char prox){

	if (prox == '*'){
		printf("Potência \n");
		return casa + 1;
	} 
	else {
		printf("Vezes \n");
		return casa;
	}
	
}



void lexer(FILE *string){

	char ch;
	int count = 0;
	
	while((ch=fgetc(string))  != EOF ){
      count++;
	}

	char *texto = (char *) malloc(count);
	
	rewind(string);

	for (int i = 0; i < count; i++){
		texto[i] = fgetc(string);
	}	

	for (int i = 0; i < count; i++){
		switch(texto[i]) {
			case Mais:
				printf("Mais \n"); 
				break;
			case Menos:
				printf("Menos \n");
				break;
			case Vezes:
				i = potencia(i, texto[i+1]);
				break;
			case Divisão:
				printf("Divisão \n");	
				break;
			case ' ':
				break;
			case '\n':
				break;
			default:
				if (isdigit(texto[i])){
					
					char numero[61];
					int c = 0;
					int pontos = 0;
					
					
					while(pontos != 2){
						
						if(isdigit(texto[i])){
							numero[c] = texto[i];
							c++;	
						}
						else if (texto[i] == '.' && pontos == 0){
							if(isdigit(texto[i+1])){
								numero[c] = texto[i];
								pontos++;
								c++;
							}
							else{
								pontos = 2;
							}
						}
						else if (texto[i] == '.' && pontos == 1){
							
							pontos = 2;
						}
						else {
							pontos = 2;
						}
						i++;
					}
					
					for (int j = 0; j < c; j++){
						printf("%c", numero[j]);
					}
					
					i = i-2;
					break;
				}	
				printf("\n");
				printf("Indeterminado ' %c '\n", texto[i]);
				break;
		}
		printf("\n");
	}
	free(texto);
}



int main(int numargs, char *arg[]) {

	char nome_arquivo[100];
	FILE *arquivo = fopen(arg[1], "r");

	if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return 1;
  }

  // // Lê o conteúdo do arquivo
  //   char caractere;
  //   while ((caractere = fgetc(arquivo)) != EOF) {
			
		// }

		lexer(arquivo);

  // Fecha o arquivo
  fclose(arquivo);
	
  return 0;
}