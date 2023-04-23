#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum token {
	Mais,
	Menos,
	Vezes,
	Divisão
}tokens;

typedef struct {
	char token;
	char valor;
}caracteres;

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
			case '+':
				printf(" Mais \n"); 
				break;
			case '-':
				printf(" Menos \n");
				break;
			case '*':
				printf(" Vezes \n");
				break;
			case '/':
				printf(" Divisão \n");	
				break;
			case ' ':
				break;
			default:
				printf(" Indeterminado ' %c '\n", texto[i]);
				break;
		}

	}
	
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