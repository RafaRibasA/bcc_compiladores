#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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



int potencia (int casa, char prox){

	if (prox == '*'){
		printf(" Potência \n");
		return casa + 1;
	} 
	else {
		printf(" Vezes \n");
		return casa;
	}
	
}

int leNum(char caractere, char prox, char pprox, char ppprox, int casa) {
	
	int numero;
	int i = casa;
	
    if (isdigit(caractere)) {
        // Se o caractere é um dígito, converte para inteiro e imprime na tela
        numero = caractere - '0';
        printf(" %d\n", numero);

			// if(prox == '.'){
			// 	printf(" .");
			// 	i = leNum(pprox, ppprox, "", "", i+1);
			// 	return 0;
			// }
    }

	return i;
}


// int verificaProximo(int casa, char prox, char pprox){
// 	char c = prox;
// 	int a = c - '0';
	
// 	if (prox != '.') {
// 		return 1;
// 	} 
// 	else if (isdigit(a)){
// 		printf(".");
// 		leNum(pprox);
// 		return casa;
// 	}
// 	else return 0;
// }

int verificaNum (char valor, char prox, char pprox){

	int casa;


	return casa;
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
			case '+':
				printf(" Mais \n"); 
				break;
			case '-':
				printf(" Menos \n");
				break;
			case '*':
				i = potencia(i, texto[i+1]);
				break;
			case '/':
				printf(" Divisão \n");	
				break;
			case ' ':
				break;
			case '1':
				i = leNum(texto[i], texto[i+1], texto[i+2], texto[i+3],i);	
				break;
			case '2':
				i = leNum(texto[i], texto[i+1], texto[i+2], texto[i+3],i);	
				break;
			case '3':
				i = leNum(texto[i], texto[i+1], texto[i+2], texto[i+3],i);	
				break;
			case '4':
				i = leNum(texto[i], texto[i+1], texto[i+2], texto[i+3],i);	
				break;
			case '5':
				i = leNum(texto[i], texto[i+1], texto[i+2], texto[i+3],i);	
				break;
			case '6':
				i = leNum(texto[i], texto[i+1], texto[i+2], texto[i+3],i);	
				break;
			case '7':
				i = leNum(texto[i], texto[i+1], texto[i+2], texto[i+3],i);	
				break;
			case '8':
				i = leNum(texto[i], texto[i+1], texto[i+2], texto[i+3],i);	
				break;
			case '9':
				i = leNum(texto[i], texto[i+1], texto[i+2], texto[i+3],i);	
				break;
			case '0':
				i = leNum(texto[i], texto[i+1], texto[i+2], texto[i+3],i);	
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