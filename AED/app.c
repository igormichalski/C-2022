/*  Resolva beecrowd | 2358 (Bact�ria II)

- Considere um caso de teste para cada execu��o;

- Os dados de execu��o dever�o ser recebidos via argumento do programa
  na linha de comando;

- Caso haja mais de uma solu��o, imprima todas elas, sem repeticoes;

- Aten��o, a sua solu��o n�o precisa necessariamente rodar tamb�m no
  ambiente beecrowd. L� exige-se o uso de t�cnicas avan�adas de organiza��o
  de dados para a constru��o de uma solu��o que atenda aos testes do
  ambiente beecrowd.



    Exemplos de execu��es

    app 3 GCTTTCGACGAT GATCGAGCTTCGAA GGTCTAGCTAAT TCGA
    SAIDA_2 = Quantidade de bacterias: 3
    SAIDA_3 = Bacteria: GCTTTCGACGAT
    SAIDA_3 = Bacteria: GATCGAGCTTCGAA
    SAIDA_3 = Bacteria: GGTCTAGCTAAT
    SAIDA_4 = Virus: TCGA
    SAIDA_5 = Bacteria infectada: GCTT
    SAIDA_5 = Bacteria infectada: GAGCTA
    SAIDA_5 = Bacteria infectada: GGTCTAGCTAAT
    SAIDA_6 = DNA resultante: GCT


    app 5 AGCT TGC CGCAA TGTC ATGTTC T
    SAIDA_2 = Quantidade de bacterias: 5
    SAIDA_3 = Bacteria: AGCT
    SAIDA_3 = Bacteria: TGC
    SAIDA_3 = Bacteria: CGCAA
    SAIDA_3 = Bacteria: TGTC
    SAIDA_3 = Bacteria: ATGTTC
    SAIDA_4 = Virus: T
    SAIDA_5 = Bacteria infectada: AGC
    SAIDA_5 = Bacteria infectada: GC
    SAIDA_5 = Bacteria infectada: CGCAA
    SAIDA_5 = Bacteria infectada: GC
    SAIDA_5 = Bacteria infectada: AGC
    SAIDA_6 = DNA resultante: GC


    app 2 AAAACGTGAGTGTAT AAAATGTAGGTGAAAA T
    SAIDA_2 = Quantidade de bacterias: 2
    SAIDA_3 = Bacteria: AAAACGTGAGTGTAT
    SAIDA_3 = Bacteria: AAAATGTAGGTGAAAA
    SAIDA_4 = Virus: T
    SAIDA_5 = Bacteria infectada: AAAACGGAGGA
    SAIDA_5 = Bacteria infectada: AAAAGAGGGAAAA
    SAIDA_6 = DNA resultante: AAAA
    SAIDA_6 = DNA resultante: GAGG

    app 2 AGTC AG
    SAIDA_1 = Quantidade invalida de argumentos!
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LIMITE_BACTERIAS 20
#define COMPR_BACTERIAS 1000
#define COMPR_VIRUS 1000

#define SAIDA_1 "\nSAIDA_1 = Quantidade invalida de argumentos!"
#define SAIDA_2 "\nSAIDA_2 = Quantidade de bacterias: %d"
#define SAIDA_3 "\nSAIDA_3 = Bacteria: %s"
#define SAIDA_4 "\nSAIDA_4 = Virus: %s"
#define SAIDA_5 "\nSAIDA_5 = Bacteria infectada: %s"
#define SAIDA_6 "\nSAIDA_6 = DNA resultante: %s"

//FUNÇÕES

char *reverse(char s[]){
    int length = strlen(s) ;
    int c, i, j;
    for (i = 0, j = length - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

void sInfeccionada (char sBacteria[][10000], char sVirus[], int n){
    int i = 0;
    char *pch;
    for(i = 0; i < n; i++){
        if(strstr(sBacteria[i],sVirus) != NULL){
            do{
                pch = strstr(sBacteria[i],sVirus);
                if(pch != NULL){
                    reverse(pch);
                    pch[(strlen(pch)-1) - (strlen(sVirus)-1)]='\0';
                    reverse(pch);
                }
            }while(strstr(sBacteria[i],sVirus) != NULL);
        }
    }
}

void imprimirStringLexicograficamente (char subsStrings[][1000], int quantBac){
    int menorString = 1, i;
    char stringPrint[1000];    
    if(quantBac != 1){
        for(i = 0; i<quantBac; i++){
            if(subsStrings[menorString] > subsStrings[i])
                menorString = i;
        strcpy(stringPrint,subsStrings[menorString]);
        }
    }else
    {
        strcpy(stringPrint,subsStrings[0]);
    }
    printf(SAIDA_6,stringPrint);
}

void localizarSubstring (char sBacteria[][10000], int N){
    int cont2 = 0, i = 0, length = 0, k = 0, menorString = 1, cont = 0, maiorSub = 1, mudarQuantComparacao = 1, comecoString = 0, findSubstring = 0;
    char subString[1000][1000], comparator[1000], *pch;
    for(i = 0; i<N; i++){
        if(strlen(sBacteria[menorString]) > strlen(sBacteria[i]))
            menorString = i;
    }
    length = strlen(sBacteria[menorString]);
    strcpy(comparator,sBacteria[menorString]);
    do{
        i = 0;
        cont = 0;
        while(i != N){
            pch = strstr(sBacteria[i++], comparator);
            if(pch != NULL){
                cont++;
                if(cont == N){
                    cont2++;
                    strcpy(subString[k++],comparator);
                    findSubstring = 1;
                }
            }
        }
        if(findSubstring == 1 && length == strlen(sBacteria[menorString])){
            maiorSub = 0;
        }else{
            if(findSubstring == 1){
                if(mudarQuantComparacao == (strlen(sBacteria[menorString]) - length) + 1){
                    maiorSub = 0;
                }
            }else{
                if(mudarQuantComparacao == (strlen(sBacteria[menorString]) - length) + 1){
                    length--;
                    mudarQuantComparacao = 0;
                    comecoString = 0;
                    findSubstring = 0;
                }
            }
            comparator[0]='\0';
            strncpy(comparator,sBacteria[menorString] + comecoString, length);
            comparator[strlen(comparator) - 1] = '\0';
            mudarQuantComparacao++;
            comecoString++;
        }
    }while(maiorSub);
    imprimirStringLexicograficamente(subString, cont2);

}

//FIM FUNÇÕES

int main (int argc, char *argv[]){
    int nBacterias;
    char BACTERIAS[LIMITE_BACTERIAS][COMPR_BACTERIAS];
    char VIRUS[COMPR_VIRUS];

    if( argc<4 ) {
        printf(SAIDA_1);
    } else {
        nBacterias = atoi(argv[1]);
        if( argc != nBacterias + 3 ) {
            printf(SAIDA_1);
        } else {
        //INICIO
        int j, N = atoi(argv[1]), i = 0;
        char StringBacteria[N][10000], StringVirus[1000];
        printf(SAIDA_2, N);
        //JOGANDO ARGUMENTOS NAS VARIAVEIS
        for(j = 0; j < N; j++)
        {
        strcpy(StringBacteria[j],argv[j+2]);
        printf(SAIDA_3, StringBacteria[j]);
        }
        strcpy(StringVirus,argv[j+2]);
        printf(SAIDA_4, StringVirus);

        sInfeccionada(StringBacteria, StringVirus, N);
        localizarSubstring(StringBacteria, N);
        //FIM DE JOGANDO ARGUMENTOS NAS VARIAVEIS

        //FIM
        }
    }
    return 0;
}