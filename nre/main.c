#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_SIZE 255
#define HEADER_VALUE 42   
#define NOP_CODE 00
#define STA_CODE 16
#define LDA_CODE 32
#define ADD_CODE 48
#define OR_CODE 64
#define AND_CODE 80
#define NOT_CODE 96
#define JMP_CODE 128
#define JN_CODE 144
#define JZ_CODE 160
#define HLT_CODE 240


int bit_negativo(uint8_t num){
  return num >> 7;
}

void verifica_extensao_arquivo(char *nome_arquivo){
	
  
	
}
 
void ler_arquivo_binario(char *nome_arquivo){
	
  static uint8_t comandos[MAX_SIZE];
	
  FILE *arquivo;
	
  arquivo = fopen(nome_arquivo, "rb");

	char *extensao = strrchr(nome_arquivo, '.');
  
  if (strcmp(extensao, ".nar") != 0){
    printf("Erro ao ler o arquivo\nO arquivo deve ser do formato .nar!\n");
    exit(0);
  }

	verifica_extensao_arquivo(nome_arquivo);
}

void verificar_bytes_do_arquivo(char *nome_arquivo){
	
  uint8_t comandos[MAX_SIZE], acumulador, PC;
	
  int contador_bytes = 3;
	
  int j = 0;
	
  FILE *arquivo;
	
  arquivo = fopen(nome_arquivo, "rb");
	
  fseek(arquivo, 0, SEEK_SET);
	
  int retorno = fread(comandos, MAX_SIZE, 1, arquivo);
  
  if(comandos[0] != HEADER_VALUE){
		
    printf("\nHeader inválido, o comando deve começar com 42");
		
    exit(0);
		
  }
	
  acumulador = comandos[1];
	
  PC = comandos[2];

	int contador = contador_bytes;
	
	while(comandos[contador_bytes] != HLT_CODE){
		
		contador_bytes++;
		contador_bytes++;
		
	}

  int i = 3;

  while(comandos[i] != HLT_CODE){
		
    switch(comandos[i]){
      case STA_CODE:
				
        comandos[comandos[i]] = acumulador;
				i++;
        break;
			
      case LDA_CODE:
				
				printf("LDA: %u\n", comandos[contador+j]);
        i++;
				j++;
        acumulador = comandos[comandos[i]];
        break;
			
      case ADD_CODE:
				
				printf("ADD: %u\n", comandos[contador+j]);
        i++;
				j++;
        acumulador += comandos[comandos[i]];
        break;
			
      case OR_CODE:
				
        i++;
        acumulador |= comandos[comandos[i]];
        break;
			
      case AND_CODE:
				
        i++;
        acumulador &= comandos[comandos[i]];
        break;
			 
      case NOT_CODE:
				
        acumulador = ~acumulador;
        break;
			
      case JMP_CODE:
				
        i++;
        i = comandos[i];
        i--;
        break;
			
      case JN_CODE:
				
        i++;
        if(bit_negativo(comandos[comandos[i]])){
					
          i = comandos[i];
          i--;
					
				}
        break;
			
      case JZ_CODE:
				
        if(acumulador == 0){
          i++;
          i = comandos[i];
          i--;
        }
				
        break;
    }
		
    i++;
  }

  PC = i;

	printf("RES:");
  printf("    Acumulador: %u", acumulador);
  printf("    PC: %u\n", PC);
}

int main(int argc, char **argv) {
	
  ler_arquivo_binario(argv[1]);
	
  verificar_bytes_do_arquivo(argv[1]);
	
	return 0;
}