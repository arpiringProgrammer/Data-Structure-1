\\Faça uma função que receba um valor n e crie dinamicamente um vetor de n elementos e retorne
um ponteiro. Crie uma função que receba um ponteiro para um vetor e um valor n e imprima os n
elementos desse vetor. Construa também uma função que receba um ponteiro para um vetor e
libere esta área de memória. Ao final, crie uma função principal que leia um valor n e chame a
função criada acima. Depois, a função principal deve ler os n elementos desse vetor. Então, a
função principal deve chamar a função de impressão dos n elementos do vetor criado e, finalmente,
liberara memória alocada através da função criada para liberação.
\\

#include <stdio.h>
#include <stdlib.h>

// Função para criar o vetor dinamicamente
int *createVector(int number) {
   int *vector = (int*)malloc(number * sizeof(int));
   if (!vector){
      printf("an error ocurried\n");
      return NULL;
   }
   return vector;
}

// Função para informar os valores do vetor
int informValues(int *vector,int number) {
   for(int i = 0; i < number; i++) {
      printf("%d number:\t",i + 1);
      scanf("%d",&vector[i]);
   }
}

// Função para imprimir os valores do vetor
int printTheValues(int *vector,int number) {
   for(int i = 0; i < number; i++) {
      printf("%d value:\t %d \n",i + 1,vector[i]);
   }
}

// Função para liberar o vetor
int freeVector(int *vector) {
   free(vector);// Liberar a memória
}

int main()
{
    int number = 0;
    int *vector = NULL; // Inicializar o ponteiro como NULL
    
   // Ler o tamanho do vetor
    printf("please,inform the size of the vector:\n");
    scanf("%d",&number);

  //Criar o vetor e armazenar o ponteiro retornado em "vector"
    vector = createVector(number);

  if (!vector) 
    return 1;// Se a alocação falhar, encerrar o programa com erro
  
  // Ler os valores do vetor
  printf("please,inform the values of the vector:\n");
  
  informValues(vector,number);
  
  printf("\n\n\n");
  // Imprimir os valores do vetor
  printf("here are the values printed:\n");
  
  printTheValues(vector,number);
  
  // Liberar a memória alocada
  freeVector(vector);

  return 0;
    
}


