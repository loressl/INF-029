
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lorena-2017216024.h"

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. 
	dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */

void TransformaNumero(int *num, int a, int *multiplicador, int *data){
  
  int i;
  
  for(i=0; i<a; i++){
      *data+=num[i]*(*multiplicador);
      *multiplicador/=10;
  }
}


void ValorStringEmInteiro(char *data, int *dia, int *mes, int *ano){

    int i=0, j=0, a, x, multiplicador, verifica=0, finaliza=0;
    int vetor[5];

    *dia=*mes=*ano=0;

     while(j<3){
       multiplicador=1;
        a=0;
        while(i<strlen(data)){
            if(data[i]-48==-1)
              break;
            else if(data[i]-48<0 || data[i]-48>9){
                verifica=1;
                break;
            }else if(data[i]-48>=0 || data[i]<=9){
                vetor[a++]=data[i]-48;
            }
            i++;
        }
        if(verifica){
           finaliza=1;
           break;
        }

        for(x=0; x<a-1; x++)
          multiplicador*=10;

        if(j==0 && (a>=0 && a<=2))
            
          TransformaNumero(vetor,a,&multiplicador,dia);
        
        else if(j==1 && (a>=0 && a<=2))
            
          TransformaNumero(vetor,a,&multiplicador,mes);
        
        else if(j==2 && (a==2 || a==4))
            
          TransformaNumero(vetor,a,&multiplicador,ano);
        
        else
            
          finaliza=1;


        j++;
        i++;
    }

    if(finaliza)
      *dia=*mes=*ano=0;

}


int q1(char *data){

    int datavalida = 1;
    int dia, mes, ano;

    ValorStringEmInteiro(data, &dia, &mes, &ano);

    if(dia<0 || dia>31 || mes<1 || mes>12 || ano<0)
        datavalida=0;
    else{
        if(ano%4==0 && (ano%100!=0 || ano%400==0)){

            if(mes==2){
                if(dia>=1 && dia<=29)
                    datavalida=1;
                else
                    datavalida=0;
            }

        }else{

            if(mes==2){
                if(dia>=1 && dia<=28)
                    datavalida=1;
                else
                    datavalida=0;
            }else if(mes==4 || mes==6 || mes==9 || mes==11){
                if(dia>=1 && dia<=30)
                    datavalida=1;
                else
                    datavalida=0;
            }else{
                if(dia>=1 && dia<=31)
                    datavalida=1;
                else
                    datavalida=0;
            }

        }
    }


    if (datavalida)
        return 1;
    else
        return 0;

}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */

void CalculoMesesDias(struct data DATA[], int *total, int divisor, int *qtdMeses, int *qtdDias){

    if(DATA[0].ano==DATA[1].ano)
    {
        *qtdMeses=(total[1]-total[0])/divisor;
        *qtdDias=(total[1]-total[0])%divisor;
    }
    else
    {
        *qtdMeses=(total[1]+total[0])/divisor;
        *qtdDias=(total[1]+total[0])%divisor;
    }

}


int comparaData(char *dataInicial, char *dataFinal){

    struct data DATA[2];

    ValorStringEmInteiro(dataInicial, &DATA[0].dia, &DATA[0].mes, &DATA[0].ano);
    ValorStringEmInteiro(dataFinal, &DATA[1].dia, &DATA[1].mes, &DATA[1].ano);

    if(DATA[0].ano > DATA[1].ano)
        return 1;
    else if(DATA[0].ano < DATA[1].ano)
        return 0;
    else{
        if(DATA[0].mes > DATA[1].mes)
            return 1;
        else if(DATA[0].mes < DATA[1].mes)
            return 0;
        else{
            if(DATA[0].dia > DATA[1].dia)
                return 1;
            else if(DATA[0].mes < DATA[1].mes)
                return 0;
        }
    }

}

int anoBissexto(int ano){

    if(ano%4==0 && (ano%100!=0 || ano%400==0))
        return 1;
    else
        return 0;

}

void TotalDias(int *vetorDias, struct data DATA[], int *dias, int *total){

    int i, j=0, inicio, fim;
    int aux[2];


     while(j<2){
            total[j]=0;
            aux[j]=0;
            if(DATA[0].ano==DATA[1].ano){
                inicio=1;
                fim=DATA[j].mes;
            }else{
                if(j==0){
                    inicio=DATA[j].mes+1;
                    fim=13;
                    if(DATA[j].mes==2)
                        DATA[j].dia=dias[j]-DATA[j].dia;
                    else
                        DATA[j].dia=vetorDias[DATA[j].mes]-DATA[j].dia;
                }else{
                    inicio=1;
                    fim=DATA[j].mes;
                }

            }
                
            for(i=inicio;i<fim; i++){
                if(i!=2)
                    total[j]+=vetorDias[i];
                else
                    total[j]+=dias[j];
            }

            total[j]+=DATA[j].dia;
            j++;
     }
   

}

void CalculoDiferenca(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){

    struct data DATA[2];
    int dias[2], i, total[2];
    int qtdDiasMeses[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

    ValorStringEmInteiro(datainicial, &DATA[0].dia, &DATA[0].mes, &DATA[0].ano);
    ValorStringEmInteiro(datafinal, &DATA[1].dia, &DATA[1].mes, &DATA[1].ano);
    
    for(i=0; i<2; i++){

        if(anoBissexto(DATA[i].ano))
            dias[i]=29;
        else
            dias[i]=qtdDiasMeses[2];
    }


     if(DATA[0].ano==DATA[1].ano){

        *qtdAnos=0;

            TotalDias(qtdDiasMeses, DATA, dias, total);

         if(DATA[0].mes==4 || DATA[0].mes==6 || DATA[0].mes==9 || DATA[0].mes==11){
           CalculoMesesDias(DATA,total, qtdDiasMeses[DATA[0].mes], qtdMeses, qtdDias);
            
         }else if(DATA[0].mes==1 || DATA[0].mes==3 || DATA[0].mes==5 || DATA[0].mes==7 || DATA[0].mes==8 || DATA[0].mes==10 || DATA[0].mes==12){
                if((total[1]-total[0])==30){
                    *qtdDias=(total[1]-total[0]);
                    *qtdMeses=0;
                }else if((total[1]-total[0])>=31)
                    CalculoMesesDias(DATA,total, qtdDiasMeses[DATA[0].mes], qtdMeses, qtdDias);

        }else if(DATA[0].mes==2){

                if(dias[0]==28)
                  CalculoMesesDias(DATA,total, dias[0], qtdMeses, qtdDias);
                  
                else
                  CalculoMesesDias(DATA, total, dias[0], qtdMeses, qtdDias);
          
        }

     }else{
             
        if(DATA[0].mes==DATA[1].mes){
         
            if(DATA[0].dia==DATA[1].dia){
                
                *qtdAnos=DATA[1].ano-DATA[0].ano;
                *qtdMeses= *qtdDias= 0;
               
            }else{
                
                    TotalDias(qtdDiasMeses, DATA, dias, total);
                    
                *qtdAnos=DATA[1].ano-DATA[0].ano;
                
                if(anoBissexto(DATA[0].ano) && anoBissexto(DATA[1].ano)){
                    
                    if(total[0]+total[1]<366){
                        
                        *qtdAnos-=(366/365);
                        
                        if(366-(total[0]+total[1])<30){
                            
                            *qtdMeses=12-1;
                            *qtdDias=31-(366-(total[0]+total[1])); 
                            
                        }else{
                            
                            *qtdMeses=12-((366-(total[0]+total[1]))/30);
                            *qtdDias=31-((366-(total[0]+total[1]))%30);
                        }
                    }
                }else if(total[0]+total[1]==365 || total[0]+total[1]==366)

                    *qtdMeses= *qtdDias= 0;
            }

        }else{
            TotalDias(qtdDiasMeses, DATA, dias, total);
            
            if(dias[0]==28){

                if(total[0]+total[1]>=365){
                    
                    *qtdAnos=(total[0]+total[1])/365;
                    *qtdMeses=((total[0]+total[1])%365)/30;
                    *qtdDias=((total[0]+total[1])%365)%30;
                    
                }else if(total[0]+total[1]<365){
                    
                    *qtdAnos=0;
                    
                    if(DATA[0].mes==4 || DATA[0].mes==6 || DATA[0].mes==9 || DATA[0].mes==11)
                        
                        CalculoMesesDias(DATA,total, qtdDiasMeses[DATA[0].mes], qtdMeses, qtdDias);
                    
                    else if(DATA[0].mes==2)
                        
                        CalculoMesesDias(DATA, total, dias[0], qtdMeses, qtdDias);
                    
                    else
                        
                       CalculoMesesDias(DATA,total, qtdDiasMeses[DATA[0].mes], qtdMeses, qtdDias);

                }

            }else{
               
                if(total[0]+total[1]>=366){
                    
                    *qtdAnos=(total[0]+total[1])/366;
                    *qtdMeses=((total[0]+total[1])%366)/30;
                    *qtdDias=((total[0]+total[1])%366)%30;
                    
                }else if(total[0]+total[1]<366){
                    
                    *qtdAnos=0;
                    
                    if(DATA[0].mes==4 || DATA[0].mes==6 || DATA[0].mes==9 || DATA[0].mes==11)
                        
                        CalculoMesesDias(DATA, total, dias[0], qtdMeses, qtdDias);
                    
                    else if(DATA[0].mes==2){
                        
                        *qtdMeses=(total[0]+total[1])/dias[0];
                        *qtdDias=(total[0]+total[1])%dias[0];
                        
                    }else
                        
                        CalculoMesesDias(DATA,total, qtdDiasMeses[DATA[0].mes], qtdMeses, qtdDias);

                }
            }

        }

     }

}

int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){

    int nDias, nMeses, nAnos;
    int dataInicialValida=1, dataFinalValida=1;
    int resultado=1;

    dataInicialValida=q1(datainicial);
    dataFinalValida=q1(datafinal);

    if(!dataInicialValida)

        return 2;

    else if(!dataFinalValida)

        return 3;

    else if(dataInicialValida && dataFinalValida){

        resultado=comparaData(datainicial, datafinal);

        if(resultado)
            
            return 4;
        
        else
            
            CalculoDiferenca(datainicial, datafinal, &nDias, &nMeses, &nAnos);

    }

    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferências entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferências entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){

    int qtdOcorrencias = 0;
    int i;

    for(i=0; texto[i]!='\0'; i++){
        if(isCaseSensitive==1){
            if(texto[i]== c)
                qtdOcorrencias++;
        }else if(isCaseSensitive!=1){
            if(texto[i]== c)
                qtdOcorrencias++;
            else if(texto[i]== c+32)
                qtdOcorrencias++;
            else if(texto[i]==c-32)
                qtdOcorrencias++;
        }
    }



    return qtdOcorrencias;

}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */


int q4(char *strTexto, char *strBusca, int posicoes[30]){
 
    int qtdOcorrencias = 0;
     int i, j, x, k, pos=0, cont, cont3=0;

 
     for(i=0; strTexto[i]!='\0'; i++){
        cont=0;
      
        if(strTexto[i]==-61)
           cont3++;
        
        for(j=0; strBusca[j]!='\0'; j++){
            if(strTexto[i]==strBusca[j]){
                cont++;
                for(x=i+1, k=j+1; strBusca[k]!='\0';x++, k++){
                    if(strTexto[x]==strBusca[k])
                        cont++;
                    else
                        break;
                }

                if(cont==strlen(strBusca)){
                    posicoes[pos++]=(i+1)-cont3;
                    if(strTexto[i]==strBusca[j]){
                        posicoes[pos++]=x-cont3;
                        qtdOcorrencias++;
                    }
                }

            }else
                break;
        }
     }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){

    int vetor[10], pos=0, i, multiplicador=1;

    if(num>=10){

        do{

            vetor[pos++]=num%10;
            num/=10;
            multiplicador*=10;

        }while(num>=10);

            vetor[pos++]=(num*10)/10;
            num=0;

        for(i=0; i<pos; i++){

            num+=multiplicador*vetor[i];
            multiplicador/=10;

        }

    }

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

void SeparaNumero(int num, int vetor[], int *cont){

    int pos=0, i, aux[20], count=0;
   
    if(num>=10){
      
        do{
            aux[pos++]=num%10;
       
            num/=10;
        }while(num>10);
           
            aux[pos++]=(num*10)/10;

          for(i=pos-1; i>=0; i--)
              vetor[count++]=aux[i];

    }else{
      vetor[pos]=num;
      pos=1;
    }

    *cont=pos;

}

int q6(int numerobase, int numerobusca){

  int qtdOcorrencias=0, contador;
  int i=0, j=0, Base[20],Busca[20], contBase, contBusca;
  int x, k;

    SeparaNumero(numerobase, Base, &contBase);
    SeparaNumero(numerobusca, Busca,&contBusca);
    

    while(i<contBase){
      contador=0;
      if(Base[i]==Busca[j]){
        contador++;
        for(x=i+1, k=j+1; k<contBusca;x++, k++){
          if(Base[x]==Busca[k]){
            contador++;
          }else
            break;
        }
        
      }
        if(contador==contBusca){
          i++;
          qtdOcorrencias++;
        }

      i++;
    }


    return qtdOcorrencias;
}
