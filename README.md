/*
 Criar uma estrutura , contendo nome, data de nascimento e CPF. Crie uma variável que é um
ponteiro para esta estrutura (no programa principal). Depois crie uma função que receba este
ponteiro e preencha os dados da estrutura e também uma uma função que receba este ponteiro e
imprima os dados da estrutura. Finalmente, faça a chamada a esta função na função principal.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
   char name[10];
   char age[10];
   char cpf[12];
};



struct Person *createStruct() {
   struct Person *info = (struct Person*)malloc(sizeof(struct Person));
   if(!info) {
      printf("an error ocurried.\n");
      return NULL;
   }
   return info;
}

void informInfo(struct Person *info) {
   printf("inform your cpf:\n");
   fgets(info->cpf,sizeof(info->cpf),stdin);
   
   printf("inform your name:\n");
   fgets(info->name,sizeof(info->name),stdin);
   
   printf("inform your age:dd/mm/yyyy \n");
   fgets(info->age,sizeof(info->name),stdin);
  
   
}

void printingInfo(struct Person *info) {
   printf("Name:%s \n",info->name);
   printf("age:%s \n",info->age);
   printf("cpf:%s \n",info->cpf);
}

void freeStruct(struct Person *info) {
   free(info);
}



int main()
{
    struct Person *info;
    
  info = createStruct();
  if(!info) {
     printf("an error ocurried.\n");
     return 1;
  }
  
  printf("give some of your information.\n");
  
  informInfo(info);
  
  printingInfo(info);
  
  freeStruct(info);

  return 0;
}
