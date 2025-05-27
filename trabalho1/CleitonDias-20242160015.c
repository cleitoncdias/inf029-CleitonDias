// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Cleiton Conceição Dias
//  email: cleitondias2906@gmail.com
//  Matrícula: 20242160015
//  Semestre: 2º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "CleitonDias-20242160015.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int i;
  char *p;
  int tam[] = {0, 0, 0};

  p = (char *)data;

  for(i = 0; i <= 2; i++){
    while(*p != '/' && *p){
      tam[i]++;
      p++;
    }
    p++; 
  }

  if((tam[0] == 0 || tam[0] > 2) || (tam[1] == 0 || tam[1] > 2) || (tam[2] != 2 && tam[2] != 4)){
    return 0;
  }
  
  char *sDia = (char *) malloc((tam[0] + 1) * sizeof(char));
  char *sMes = (char *) malloc((tam[1] + 1) * sizeof(char));
  char *sAno = (char *) malloc((tam[2] + 1) * sizeof(char));

  p = (char *)data;

  for(i = 0; i < tam[0]; i++){
    sDia[i] = p[i];
  }
  sDia[tam[0]] = '\0';

  for(i = 0; i < tam[1]; i++){
    sMes[i] = p[tam[0] + 1 + i];
  }
  sMes[tam[1]] = '\0';

  for(i = 0; i < tam[2]; i++){
    sAno[i] = p[tam[0] + tam[1] + 2 + i];
  }
  sAno[tam[2]] = '\0';

  int dia = atoi(sDia);
  int mes = atoi(sMes);
  int ano = atoi(sAno);

  free(sDia);
  free(sMes);
  free(sAno);

  if (ano >=0 && ano <= 99){
    ano += 2000;
  }

  if (mes <= 0 || mes > 12){
    return 0;
  } else{
    if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia <= 0 || dia > 31)){
      return 0;
    }

    else if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia <= 0 || dia > 30)){
      return 0;
    }

    else if(mes == 2){
      if(dia <= 0 || dia > 29){
        return 0;
      }
      if(dia == 29){
        if((ano % 4 != 0) || (ano % 100 == 0 && ano % 400 != 0)) return 0;
      } 
    }
  }

  return 1;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
void extrairData(const char *data, int *dia, int *mes, int *ano){
  int i;
  char *p;
  int tam[] = {0, 0, 0};

  p = (char *)data;

  for(i = 0; i <= 2; i++){
    while(*p != '/' && *p){
      tam[i]++;
      p++;
    }
    p++; 
  }
  
  char *sDia = (char *) malloc((tam[0] + 1) * sizeof(char));
  char *sMes = (char *) malloc((tam[1] + 1) * sizeof(char));
  char *sAno = (char *) malloc((tam[2] + 1) * sizeof(char));

  p = (char *)data;

  for(i = 0; i < tam[0]; i++){
    sDia[i] = p[i];
  }
  sDia[tam[0]] = '\0';

  for(i = 0; i < tam[1]; i++){
    sMes[i] = p[tam[0] + 1 + i];
  }
  sMes[tam[1]] = '\0';

  for(i = 0; i < tam[2]; i++){
    sAno[i] = p[tam[0] + tam[1] + 2 + i];
  }
  sAno[tam[2]] = '\0';

  *dia = atoi(sDia);
  *mes = atoi(sMes);
  *ano = atoi(sAno);

  free(sDia);
  free(sMes);
  free(sAno);

  return;
}

int qtdDiasNoMes(int mes, int ano){
  if (mes == 2) {
    if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
      return 29;
    } else {
      return 28;
    }
  } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
    return 30;
  } else {
    return 31;
  }
}
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      const char *datas[2] = {datainicial, datafinal};
      int dia[2], mes[2], ano[2];

      for(int i = 0; i < 2; i++){
        extrairData(datas[i], &dia[i], &mes[i], &ano[i]);
      }

      if(ano[0] > ano[1]){
        dma.retorno = 4;
        return dma;
      }else if((ano[0] == ano[1]) && mes[0] > mes[1]){
        dma.retorno = 4;
        return dma;
      }else if((ano[0] == ano[1]) && (mes[0] == mes[1]) && dia[0] > dia[1]){
        dma.retorno = 4;
        return dma;
      }else{
        //calcule a distancia entre as datas
        //se tudo der certo
        if(dia[0] > dia[1]){
          mes[1] -= 1;
          dia[1] += qtdDiasNoMes(mes[1], ano[1]);
          dma.qtdDias = dia[1] - dia[0];
        } else{
          dma.qtdDias = dia[1] - dia[0];
        }

        if(mes[0] > mes[1]){
          ano[1] -= 1;
          mes[1] += 12;
          dma.qtdMeses = mes[1] - mes[0];
        } else{
          dma.qtdMeses = mes[1] - mes[0];
        }

        dma.qtdAnos = ano[1] - ano[0];
        dma.retorno = 1;
        return dma;
      }      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    if(isCaseSensitive == 1){
      while(*texto){
        if (c == *texto) qtdOcorrencias++;
        texto++;
      }
    }else{     
      if (c > 64 && c < 91){
        while(*texto){
          if (c == *texto || (c + 32) == *texto) qtdOcorrencias++;
          texto++;
        }
      } else{
        while(*texto){
          if (c == *texto || (c - 32) == *texto) qtdOcorrencias++;
          texto++;
        }
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
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;

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

int q5(int num)
{
  int numAux = 0, tamEncontrado = 0;
  int tam = 1, x, y, i;

  x = 10;

  do{    
    if (num % x != num){
      tam++;
      x *= 10;
    }
    else{
      tamEncontrado = 1;
    }
  }while(!tamEncontrado);

  x = 1;
  y = 1;

  for(i = 1; i < tam; i++){
    y *= 10;
  }

  for (i = 0; i < tam; i++){
    numAux += (((num / x) % 10) * y);
    x *= 10;
    y /= 10;
  }

  num = numAux;

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

int q6(int numerobase, int numerobusca)
{
    int numAux, qtdOcorrencias = 0;

    int tamBusca = 0, tamCorte, tamBase = 0, x, y, tamEncontrado = 0;

    y = 10;

    do{
        if (numerobase % y != numerobase){
            tamBase++;
            y *= 10;
        } else{
            tamEncontrado = 1;
        }
    }while(!tamEncontrado);

    y = 10;
    tamEncontrado = 0;

    do{    
        if (numerobusca % y != numerobusca){
            tamBusca++;
            y *= 10;
        }else{
            tamEncontrado = 1;
        }
    }while(!tamEncontrado);

    x = 1;
    numAux = numerobase;
    tamCorte = tamBusca;

    do{
        if (numerobusca == ((numAux / x) % y)){
            qtdOcorrencias++;
            numAux /= x * 10;
            x = 1;
            tamBase -= tamCorte;
        } else{
            x *= 10;
            tamCorte++;
        }
    }while(tamBusca > tamBase);

    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5]) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 10; j++) {
      int direcoes[8][2] = {
          {0, 1},{0, -1},{1, 0},{-1, 0},
          {1, 1},{1, -1},{-1, -1},{-1, 1}
      };

      for (int d = 0; d < 8; d++) {
          int variacaoLinha = direcoes[d][0], variacaoColuna = direcoes[d][1], k;

          for (k = 0; k < 5; k++) {
              int x = i + k * variacaoLinha, y = j + k * variacaoColuna;
              if (x < 0 || x >= 8 || y < 0 || y >= 10) break;
              if (matriz[x][y] != palavra[k]) break;
          }

          if (k == 5) return 1;
      }
    }
  }
    return 0;
}




DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
