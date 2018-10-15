#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct principal{
    int *auxiliar;
    int quantidade;
    int contador;
    int *ordenaEstrutura;
};

int menu();
void *Malloc(struct principal *Posicao, int posicao);
void *Realloc(struct principal Posicao[], int num, int pos);
void inserir(struct principal *Posicao, int tam, int pos);
int contSpace(struct principal *Posicao, int elemento, int pos);
void listarPorEstrutura(struct principal *Posicao, int tam);
void listarOrdPorEstr(struct principal *Posicao, int tam);
void listarTodos(struct principal *Posicao, int tam);
void passarValores(struct principal *Posicao, int tam);
void insertionSort(struct principal *Posicao, int tam);
void insertionSort_Todos(int *ordenaTotal, int *total);
int validarEntrada(char *dado, int *num);
int validarElemento(char *dados, int *elemento);
void saberPosicao(int *pos, int tam);
void pegarElemento(int *elemento);
void excluir(struct principal *Posicao, int tam, int pos);
void mostrarPosicoes(struct principal *Posicao, int tam);
void aumentar(struct principal *Posicao, int pos);
int somaTotal(struct principal *Posicao, int tam);
int separar_Numero(char *dados, int *vetor, int *cont, int *multiplicador, int negativo);

int main(){

    int tam=10;
    struct principal Posicao[tam];
    int opcao, i, pos;

    for(i=0; i<tam; i++){
        Posicao[i].quantidade=0;
        Posicao[i].contador=0;
        Posicao[i].auxiliar=NULL;
        Posicao[i].ordenaEstrutura=NULL;
    }
   printf("\n************ESTRUTURA DE DADOS***********\n\n");     

    do{
       opcao=menu();

       if(opcao==1){

          saberPosicao(&pos, tam);

          inserir(Posicao,tam, pos);

       }else if(opcao==2){

           listarPorEstrutura(Posicao, tam);

       }else if(opcao==3){

           listarOrdPorEstr(Posicao, tam);

       }else if(opcao==4){

           listarTodos(Posicao, tam);

       }else if(opcao==5){

           saberPosicao(&pos, tam);

           if(Posicao[pos-1].quantidade!=0)
              excluir(Posicao, tam, pos);
           else
              printf("\nPosicao nao criada\n");

       }else if(opcao==6){

            mostrarPosicoes(Posicao,tam);

            saberPosicao(&pos, tam);

            aumentar(Posicao, pos);

       }else if(opcao<1 || opcao>7)

           printf("\nOpcao invalida, escolha novamente\n");

    }while(opcao!=7);

    for(i=0; i<tam; i++){
        free(Posicao[i].auxiliar);
        free(Posicao[i].ordenaEstrutura);
    }


    return 0;
}

//-------MOSTRAR POSICÕES QUE EXISTE PARA AUMENTAR-----------------------------
void mostrarPosicoes(struct principal *Posicao, int tam){

    int i;
   
    printf("\nPosicoes existentes que podem ter o tamanho aumentado: ");
      for(i=0; i<tam; i++){
        if(Posicao[i].quantidade!=0)
            printf(" %d ", i+1);
      }

    printf("\n");

}

//---------PEGAR A POSICAO DA ESTRUTURA PRINCIPAL--------------
void saberPosicao(int *pos, int tam){

    char dado[10];

      do{
          setbuf(stdin,NULL);
          printf("\nInforme a posicao (1-10) da estrutura principal: ");
          fgets(dado,sizeof(dado),stdin);

          if(validarEntrada(dado,pos)==0 || (*pos<1 || *pos>tam))
              printf("\nPosicao invalida\n");

      }while(validarEntrada(dado,pos)==0 || (*pos<1 || *pos>tam));

}

//-----------PEGA O ELEMENTO (NUMERO INTEIRO)----------------
void pegarElemento(int *elemento){

    char dado[10];

    do{

         setbuf(stdin,NULL);
         printf("\nInforme o elemento [numero inteiro]: ");
         fgets(dado,sizeof(dado),stdin);

            if(validarElemento(dado,elemento)==0)
                printf("\nElemento invalido\n");

    }while(validarElemento(dado,elemento)==0);

}

//----------------MENU-------------------
int menu(){

    char dado[10];

    int op;

    do{
        printf("\n\nEscolha a opcao desejada:\n");
        printf("1 - Inserir\n");
        printf("2 - Listar os numeros de todas as estrutura\n");
        printf("3 - Listar os numeros ordenados para cada estrutura\n");
        printf("4 - Listar todos os numeros ordenados\n");
        printf("5 - Excluir um elemento\n");
        printf("6 - Aumentar o tamanho de uma estrutura auxiliar\n");
        printf("7 - Sair\n");
        fgets(dado,sizeof(dado),stdin);

          if(validarEntrada(dado,&op)==0 || (op<1 || op>7))
                printf("\nOpcao invalida\n");

    }while(validarEntrada(dado,&op)==0 || (op<1 || op>7));

    return op;

}

//-------------------VALIDAR ENTRADAS---------------
int validarEntrada(char *dado, int *num){

    int i, cont=0;
    int valida=1, multiplicador=1, valor=0;

    while(dado[cont]!='\0')
        cont++;

    if(cont-1>=2){

        for(i=0; i<cont-1;i++)
            multiplicador*=10;

          multiplicador/=10;

            for(i=0; i<cont-1; i++){

                if(dado[i]-48>=0 && dado[i]-48<=9){
                    valor+=(dado[i]-48)*multiplicador;
                     multiplicador/=10;

                }else{
                    valida=0;
                    break;
                }
            }

    }else{

      if(dado[0]-48>=0 && dado[0]-48<=9)
        valor=dado[0]-48;
      else
        valida=0;
    }

   *num=valor;

    return valida;
}


//--------------VALIDAR ELEMENTOS (NUMEROS INTEIROS)------------
int validarElemento(char *dado, int *elemento){

    int valida=1, i, cont=0, multiplicador=1, negativo=0, valor=0;
    int vetor[10];

    if(dado[0]==45)
      negativo=1;

      for(i=0; i!=strlen(dado)-1; i++){
        if(dado[i]-48>=0 && dado[i]-48<=9){
            vetor[cont++]=dado[i]-48;
            multiplicador*=10;
        }else if(dado[i]!=45 && (dado[i]-48<0 || dado[i]-48>9)){
            valida= 0;
            break;
        }
      }

    if(valida==0)
        return valida;
    else{
        multiplicador/=10;//pois sai a mais do for

        if(cont>1){

          for(i=0; i<cont; i++){
              valor+=vetor[i]*multiplicador;
              multiplicador/=10;
          }

        }else
          valor=vetor[0];

        if(negativo==1)//se for negativo multiplica por -1, o traço é 45 na ascii
            valor*=-1;

        valida=1;
    }

       *elemento=valor;

    return valida;
}

//---------------------FUNÇÃO INSERIR---------------
void inserir(struct principal *Posicao, int tam, int pos){

    int i, elemento, cont=0, num;
    char dado[10];

    if(Posicao[pos-1].quantidade==0){

        do{
            printf("\nEstrutura nao criada, quantos elementos deseja inserir: ");
            fgets(dado,sizeof(dado),stdin);

            if(validarEntrada(dado,&num)==0 || num==0)
                printf("\nEntrada invalida\n");

        }while(validarEntrada(dado,&num)==0 || num==0);

            Posicao[pos-1].quantidade=num;

            Malloc(Posicao, pos);//aloca o vetor auxiliar com a quantidade

            pegarElemento(&elemento);//solicita o numero e verifica se é válido

            Posicao[pos-1].auxiliar[0]=elemento;
            Posicao[pos-1].contador=1;//contador pra a quantidade de elementos naquele vetor

    }else if(Posicao[pos-1].quantidade!=0){//se já tiver alocado

          pegarElemento(&elemento);

          cont=contSpace(Posicao, elemento, pos);//vai contar os espaços vazios no vetor para poder colocar o elemento

            if(cont==1)
                printf("\n Nao ha espaco para inserir numeros!!\n");

    }

}

//-------------------CONTA A QUANTIDADE DE ESPAÇOS PREENCHIDOS NO VETOR----------------
int contSpace(struct principal *Posicao, int elemento, int pos){

    int i, cont=0;

    if(Posicao[pos-1].contador==Posicao[pos-1].quantidade)
      cont=1;
    else if(Posicao[pos-1].contador<Posicao[pos-1].quantidade){

      Posicao[pos-1].auxiliar[Posicao[pos-1].contador]=elemento;
      Posicao[pos-1].contador+=1;

    }

    return cont;
}


//---------LISTA POR ESTRUTURA-----------------------------
void listarPorEstrutura(struct principal *Posicao, int tam){

    int i, j, cont;

    for(i=0; i<tam; i++){

        if(Posicao[i].quantidade!=0){
            printf("\nPosicao principal %d cabe %d elementos: ", i+1, Posicao[i].quantidade);
            cont=0;
            for(j=0; j<Posicao[i].contador; j++){
                    printf(" %d ", Posicao[i].auxiliar[j]);
                cont=1;
            }
            if(cont==0)
              printf(" Lista vazia ");
        }

    }
}

//---------------LISTA ORDENADO POR ESTRUTURA-----------------
void listarOrdPorEstr(struct principal *Posicao, int tam){

    int i, j, cont;

    insertionSort(Posicao,tam);

    for(i=0; i<tam; i++){

        if(Posicao[i].quantidade!=0){

            printf("\nPosicao principal %d de %d elementos: ", i+1, Posicao[i].quantidade);
            cont=0;
            for(j=0; j<Posicao[i].contador;j++){

                    printf(" %d ", Posicao[i].ordenaEstrutura[j]);
                cont=1;
            }
            if(cont==0)
              printf(" Lista vazia");
        }
    }

}


//-----------LISTA TODOS ORDENADO-----------
void listarTodos(struct principal *Posicao, int tam){

    int *ordenaTotal;
    int total, i,j, cont=0;

    total=somaTotal(Posicao, tam);

    ordenaTotal=(int*)malloc(total*sizeof(int));

    if(ordenaTotal==NULL)
        exit(1);

    for(i=0; i<tam;i++){
      if(Posicao[i].auxiliar!=NULL){
        for(j=0; j<Posicao[i].contador; j++)
          ordenaTotal[cont++]=Posicao[i].auxiliar[j];
      }
    }

    insertionSort_Todos(ordenaTotal, &total);

    printf("\n Elementos ordenados: ");
    for(i=0; i<total; i++)
      printf(" %d ", ordenaTotal[i]);

    free(ordenaTotal);

}

//-------------FUNÇÃO QUE ORDENA TODOS-----------------
void insertionSort_Todos(int *ordenaTotal, int *total){

    int i, j, atual;

    for(i=1; i<*total; i++){
      atual=ordenaTotal[i];
      for(j=i-1; (j>=0) && (atual< ordenaTotal[j]); j--)
        ordenaTotal[j+1]=ordenaTotal[j];

        ordenaTotal[j+1]=atual;
    }

}

//------FUNÇÃO QUE SOMA O TOTAL DE ELEMENTOS QUE HÁ ----------------
int somaTotal(struct principal *Posicao, int tam){

    int i, soma=0;

    for(i=0; i<tam; i++)
        soma+=Posicao[i].contador;

    return soma;
}


//----------PASSA OS VALORES DA AUXILIAR PARA O VETOR QUE VAI ARMAZENAR O ORDENADO---------------
void passarValores(struct principal *Posicao, int tam){

    int i, j;

    for(i=0; i<tam; i++){

      if(Posicao[i].quantidade!=0){

        for(j=0; j<Posicao[i].contador; j++)
                Posicao[i].ordenaEstrutura[j]=Posicao[i].auxiliar[j];

      }

    }

}

//-------------------------FUNÇÃO EXCLUIR-------------------
void excluir(struct principal *Posicao, int tam, int pos){

    int elemento, i, j, find;

      pegarElemento(&elemento);

      for(i=0; i<Posicao[pos-1].contador;i++){
      	find=0;
        if(Posicao[pos-1].auxiliar[i]==elemento){
        	find=1;
          for(j=i; j<Posicao[pos-1].contador-1;j++){
            Posicao[pos-1].auxiliar[j]=Posicao[pos-1].auxiliar[j+1];
          }
          Posicao[pos-1].contador-=1;
          break;
        }
      }

      if(find==0)
          printf("\nEste numero nao existe nesta estrutura auxiliar.\n");
      else if(find==1)
          printf("\nExclusao realizada com sucesso!!\n");

}

//----------------------FUNÇÃO PARA ORDENAR POR ESTRUTURA--------------------------
void insertionSort(struct principal *Posicao, int tam){

    int i, j,k, atual;

    passarValores(Posicao, tam);

    for(i=0; i<tam; i++){

        if(Posicao[i].quantidade!=0){

          if(Posicao[i].contador>1){

            for(j=1; j<Posicao[i].contador; j++){
                atual=Posicao[i].ordenaEstrutura[j];

                for(k=j-1; (k>=0) && (atual < Posicao[i].ordenaEstrutura[k]); k--){
                    Posicao[i].ordenaEstrutura[k+1]=Posicao[i].ordenaEstrutura[k];
                }

                Posicao[i].ordenaEstrutura[k+1]=atual;
            }
          }
        }

    }


}

//--------------FUNÇÃO QUE AUMENTA O VETOR AUXILIAR------------------
void aumentar(struct principal *Posicao, int pos){

    char dado[10];
    int num;

    do{
      printf("\nEm quanto deseja aumentar: ");
      fgets(dado,sizeof(dado),stdin);

       if(validarEntrada(dado,&num)==0)
          printf("\nEntrada invalida\n");

    }while(validarEntrada(dado,&num)==0);

    Realloc(Posicao, num, pos);
    Posicao[pos-1].quantidade+=num;

}

//-------------------------FUNÇÃO DE ALOCAÇÃO---------------------
void *Malloc(struct principal *Posicao, int pos){

    int i, qtd;
    qtd=Posicao[pos-1].quantidade;

    Posicao[pos-1].auxiliar=(int*)malloc(qtd*sizeof(int));
    Posicao[pos-1].ordenaEstrutura=(int*)malloc(qtd*sizeof(int));

    if(Posicao[pos-1].auxiliar==NULL || Posicao[pos-1].ordenaEstrutura==NULL){
        printf("\nNao foi possivel alocar memoria\n");
        exit(1);
    }

    for(i=0; i<qtd; i++)
        Posicao[pos-1].auxiliar[i]=0;


}

//---------------FUNÇÃO DE REALOCAÇÃO-----------------------------
void *Realloc(struct principal Posicao[], int num, int pos){

    int i;
    Posicao[pos-1].auxiliar= (int*)realloc(Posicao[pos-1].auxiliar,num*sizeof(int));
    Posicao[pos-1].ordenaEstrutura=(int*)realloc(Posicao[pos-1].ordenaEstrutura,num*sizeof(int));

    if(Posicao[pos-1].auxiliar==NULL || Posicao[pos-1].ordenaEstrutura==NULL)
        exit(1);

    for(i=Posicao[pos-1].quantidade; i<num+Posicao[pos-1].quantidade; i++)
      Posicao[pos-1].auxiliar[i]=0;


}
