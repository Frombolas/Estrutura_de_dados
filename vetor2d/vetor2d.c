#include <stdio.h>

int DimensaoMatriz(int i, int j) { return i * j; }
void criarMatriz(int i, int j) {
  int tam = DimensaoMatriz(i, j);
  int vet[tam];
}
void zerarMatriz(int vetor[], int tam) {
  int i;
  for (i = 0; i < tam; i++) {
    vetor[i] = 0;
  }
}

int buscarElemento(int vetor[], int i, int j, int tam) {
  return vetor[((i - 1) * tam) + (j - 1)];
}

void imprimirMatriz(int vetor[], int tam) {
	int i,j;
  	printf("\nMatriz:\n");
  	for ( i = 1; i <= 3; i++) {
    	for ( j = 1; j <= 3; j++) {
      	printf("%d ", buscarElemento(vetor, i, j, tam));
    	}
    	printf("\n");
  	}
}

void adicionarElementos(int vetor[], int num, int i, int j, int tam) {
  int pos = (i - 1) * tam + (j - 1);
  vetor[pos] = num;
}

void somaMatriz(int vetor1[], int vetor2[], int tam) {
	int i,j;
  	for (i = 1; i <= 3; i++) {
    	for (j = 1; j <= 3; j++) {
      		int soma =
          	buscarElemento(vetor1, i, j, tam) + buscarElemento(vetor2, i, j, tam);
      		printf("%d ", soma);
    		}
    	printf("\n");
  	}
}

void main() {
  // dimensinando a matriz
  int tam = DimensaoMatriz(3, 3);
  int vet[tam];
  int vet2[tam];
  // criando e limpando a matriz -- zerando--
  zerarMatriz(vet, tam);
  imprimirMatriz(vet, 3);
  // adicionando valores manualmente
  adicionarElementos(vet, 5, 1, 1, 3);
  adicionarElementos(vet, 10, 2, 2, 3);
  adicionarElementos(vet, 15, 3, 3, 3);
  // imprimindo a matriz preenchida
  imprimirMatriz(vet, 3);
  // buscando valores na matriz
  printf("\nO elemento que esta na linha 2 coluna 2 eh: %d \n",
         buscarElemento(vet, 2, 2, 3));
  // criando e limpando outra matriz -- zerando--
  zerarMatriz(vet2, tam);
  imprimirMatriz(vet2, 3);
  // adicionando valores manualmente
  adicionarElementos(vet2, 29, 1, 1, 3);
  adicionarElementos(vet2, 8, 2, 2, 3);
  adicionarElementos(vet2, 2, 3, 3, 3);
  imprimirMatriz(vet2, 3);
  // somando as duas matrizes
  printf("\nSoma das matrizes: \n");
  somaMatriz(vet, vet2, 3);
}
