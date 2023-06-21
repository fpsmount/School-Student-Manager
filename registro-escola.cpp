#include<string.h>
#include<conio.h>
#include<stdio.h>

struct agenda {
       int cod;
       char nome[30];
       int tel;
       int vazio; //VAZIO = 0 e DISPONIVEL = 1.
} registros[100];
       

void cadastrar(int cod, int pos);
void consultar();
int verifica_pos();
void zerar();
int verifica_cod(int cod);
void excluir();

main() {
zerar();
int op=0,retorno,codaux,posicao;
while(op!=4){
   printf("\n\n\t\t\t\t** AGENDA **\n\n\nMENU\n\n1 - Cadastrar\n2 - Consultar\n3 - Excluir\n4 - Sair\n\nOpcao:  ");
   scanf("%d",&op);
   fflush(stdin);
   switch(op) {
       case 1: {                  // CADASTRAR
            posicao=verifica_pos();
            if (posicao!=-1) {
            printf("\nEntre com o codigo desejado\n");
            scanf("%d",&codaux);fflush(stdin);
               retorno=verifica_cod(codaux);
               if (retorno==1)
                  cadastrar(codaux,posicao);
               else
                  printf("\nCodigo ja existente\n");
            } 
            else
              printf("\nA agenda esta cheia\n");    
       break;
       }
       
       case 2: {                  // CONSULTAR
            consultar();
       break;    
       }
       
       case 3: {
            excluir();
       break;
       }
       
       case 4: {
            printf("\n\nTchau");
       break;
       }
            
   }
}
     
getch();      
}

void cadastrar(int cod, int pos) {
pos=verifica_pos();
registros[pos].cod=cod;
printf("\nNome:\n");
gets(registros[pos].nome);
printf("\nTelefone\n");
scanf("%d",&registros[pos].tel);
registros[pos].vazio=1;
printf("\nCadastro Realizado com Sucesso!\n\n");
}

void consultar() {
int cont=0, cod;
printf("\nEntre com o codigo\n");
scanf("%d",&cod);
while(cont<=100) {
    if (registros[cont].cod==cod) {
       if (registros[cont].vazio==1) {
          printf("\nNome: %s",registros[cont].nome);
          printf("\nTelefone: %d",registros[cont].tel);
          break;
       }
    }
    cont++;
    if (cont>100)
       printf("\nCodigo nao encontrado\n"); 
}                         
}

int verifica_pos() {
int cont=0;
while (cont<=100) {
      if (registros[cont].vazio==0)
         return(cont);
      cont++;    
}
return(-1);
}

void zerar() {
int cont;
for (cont=0;cont<=100;cont++)
    registros[cont].vazio=0; 
}

int verifica_cod(int cod) {
int cont=0;
while (cont<=100) {
   if (registros[cont].cod==cod)
      return(0);
   cont++;
}
return(1);
}

void excluir() {
int cod, cont=0;
printf("\nEntre com o codigo do registro que deseja excluir\n");
scanf("%d",&cod);


while (cont<=100) {
      if (registros[cont].cod==cod)
         if (registros[cont].vazio==1) {
            registros[cont].vazio=0;
            printf("\nExclusao feita com sucesso\n");
            break;
         }
      cont++;
      if (cont>100)
         printf("\nCodigo nao encontrado\n");
}
}
