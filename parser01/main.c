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
			case ' ':
				break;
			case '\n':
				break;
			default:
				if (isdigit(texto[i])){
					
					char numero[61];
					char segundoNum[61];
					int c = 0;
					int t = 0;
					int pontos = 0;
					double soma;
					
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
					
					i = i-1;
					
					if(texto[i] == '+'){
						int pontos2 = 0;

						while(pontos2 != 2){
						
							if(isdigit(texto[i+1])){
								segundoNum[t] = texto[i+1];
								t++;	
							}
							else if (texto[i] == '.' && pontos2 == 0){
								if(isdigit(texto[i+1])){
									segundoNum[t] = texto[i+1];
									pontos2++;
									t++;
								}
								else{
									pontos2 = 2;
								}
							}
							else if (texto[i] == '.' && pontos2 == 1){
								pontos2 = 2;
							}
							else {
								pontos2 = 2;
							}
							i++;
						}

						if (isdigit(segundoNum[0])){
							double num1 = atof(numero);
							double segundo = atof(segundoNum);
	
							soma = num1 + segundo;
	
							printf("%f", soma);
						}else {
							break;
						}
						
					} else {
							for (int j = 0; j < c; j++){
							printf("%c", numero[j]);
						}
					}
					break;
				}
				break;
		}
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