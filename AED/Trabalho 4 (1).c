#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// objetivo: Iniciar uma matriz com o indicador de cada linha
// parametros: char matriz[200][100]
// retorno: matriz[200][100]
void inicia_matriz(char matriz[200][100])
{
    int i;
    for (i = 0; i < 200; i++)
    {
        matriz[i][0] = '/';
        matriz[i][1] = '\0';
    }
}

// objetivo: Copiar o texto de uma matriz para a outra
// parametros: char matriz[200][100] e char matriz_modificada[200][100]
// retorno: char matriz_modificada[200][100]
void organiza_matriz(char matriz[200][100], char matriz_modificada[200][100])
{
    int i;
    inicia_matriz(matriz_modificada);

    for (i = 0; i < 200; i++)
        strcpy(matriz_modificada[i], matriz[i]);

    inicia_matriz(matriz);
}

// objetivo: Copiar o texto de um vetor para o outro
// parametros: char vetor[9999] e char vetor_modificado[9999]
// retorno: vetor_modificado[9999]
void organiza_vetor(char vetor[9999], char vetor_modificado[9999])
{
    vetor_modificado[0] = '\0';
    strcpy(vetor_modificado, vetor);
    vetor[0] = '\0';
}

// objetivo: Separa e informa as linhas e a quantidade de caracteres por linha
// parametros: char texto[200][100]
// retorno: Nenhum
void separa_linhas(char texto[200][100])
{
    int i;
    for (i = 0; i < 200; i++)
    {
        if (texto[i][0] != '/')
        {
            if (i < 9)
                printf(" %d \t%s\n", i + 1,  texto[i]);
            else
                printf(" %d \t%s\n", i + 1,  texto[i]);
        }
    }
}

// objetivo: Colocar todos os carecteres alfabéticos em maiuscula
// parametros: char texto[] e char texto_modificado[]
// retorno: char texto_modificado[]
void maiuscula(char texto[], char texto_modificado[])
{
    int i;
    for (i = 0; i < 9999; i++)
        texto_modificado[i] = toupper(texto[i]);
}

// objetivo: Colocar todos os carecteres alfabéticos em minuscula
// parametros: char texto[] e char texto_modificado[]
// retorno: char texto_modificado[]
void minuscula(char texto[], char texto_modificado[])
{
    int i;
    for (i = 0; i < 9999; i++)
        texto_modificado[i] = tolower(texto[i]);
}

// objetivo: Colocar todos os carecteres alfabéticos em minuscula
// parametros: char palavra[] e char palavra_modificada[]
// retorno: char palavra_modificada[]
void minuscula_palavras(char palavra[], char palavra_modificada[])
{
    int i;
    for (i = 0; i < 100; i++)
        palavra_modificada[i] = tolower(palavra[i]);
}

// objetivo: Formatar o texto em linhas com 80 caracteres no máximo em cada linha
// parametros: char texto[] e char textoarrumado[200][100]
// retorno: char textoarrumado[200][100]
void formata_texto(char texto[], char textoarrumado[200][100])
{
    int i = 0;
    char texto_auxiliar[9999];
    char aux[1000];
    const char espaco[] = " ";
    char *token;

    strcpy(texto_auxiliar, texto);
    token = strtok(texto_auxiliar, espaco);
    strcpy(aux, token);
    strcat(aux, espaco);
    strcpy(textoarrumado[i], token);
    strcat(textoarrumado[i], espaco);

    do
    {
        token = strtok(NULL, espaco);
        if (token != NULL)
        {
            strcat(aux, token);
            strcat(aux, espaco);
            if (strlen(aux) < 80)
            {
                strcat(textoarrumado[i], token);
                strcat(textoarrumado[i], espaco);
            }
            else
            {
                i++;
                strcpy(aux, "\0");
                strcpy(aux, token);
                strcat(aux, espaco);
                strcpy(textoarrumado[i], token);
                strcat(textoarrumado[i], espaco);
            }
        }
    } while (token != NULL);
}
// objetivo: Separar as palavras da pontuação no texto
// parametros: char texto[] e char texto_atual[]
// retorno: char texto_atual[]
void separa_pontuacao(char texto[], char texto_atual[])
{
    const char espaco[] = " ";
    const char separador_espaco[] = "*";
    const char separador[] = "&";
    const char virgula[] = ",";
    const char ponto[] = ".";
    const char parenteses_1[] = "(";
    const char parenteses_2[] = ")";
    const char dois_pontos[] = ":";
    const char barra[] = "/";
    const char traco[] = "-";
    const char underline[] = "_";
    char texto_auxiliar[9999], texto_formatado[9999];
    char *aux_espaco, *aux_virgula, *aux_parenteses_1, *aux_parenteses_2, *aux_barra, *aux_dois_pontos, *aux_underline, *aux_ponto, *aux_traco;
    char *token_espaco, *token_separador;
    int cont;

    texto_formatado[0] = '\0';

    strcpy(texto_auxiliar, texto);

    // Arruma os eespaços
    aux_espaco = strtok(texto_auxiliar, espaco);

    while (aux_espaco != NULL)
    {
        strcat(texto_formatado, aux_espaco);
        strcat(texto_formatado, separador_espaco);

        aux_espaco = strtok(NULL, espaco);
    }

    // Virgula
    organiza_vetor(texto_formatado, texto_auxiliar);
    aux_virgula = strtok(texto_auxiliar, virgula);

    cont = 1;
    while (aux_virgula != NULL)
    {
        strcat(texto_formatado, aux_virgula);
        strcat(texto_formatado, separador);
        if (cont < 43)
            strcat(texto_formatado, virgula);
        strcat(texto_formatado, separador);

        cont++;
        aux_virgula = strtok(NULL, virgula);
    }

    // Parenteses (
    organiza_vetor(texto_formatado, texto_auxiliar);
    aux_parenteses_1 = strtok(texto_auxiliar, parenteses_1);

    cont = 1;
    while (aux_parenteses_1 != NULL)
    {
        strcat(texto_formatado, aux_parenteses_1);
        strcat(texto_formatado, separador);
        if (cont < 5)
            strcat(texto_formatado, parenteses_1);
        strcat(texto_formatado, separador);

        cont++;
        aux_parenteses_1 = strtok(NULL, parenteses_1);
    }

    // Parenteses )
    organiza_vetor(texto_formatado, texto_auxiliar);
    aux_parenteses_2 = strtok(texto_auxiliar, parenteses_2);

    cont = 1;
    while (aux_parenteses_2 != NULL)
    {
        strcat(texto_formatado, aux_parenteses_2);
        strcat(texto_formatado, separador);
        if (cont < 5)
            strcat(texto_formatado, parenteses_2);
        strcat(texto_formatado, separador);

        cont++;
        aux_parenteses_2 = strtok(NULL, parenteses_2);
    }

    // Barra
    organiza_vetor(texto_formatado, texto_auxiliar);
    aux_barra = strtok(texto_auxiliar, barra);

    cont = 1;
    while (aux_barra != NULL)
    {
        strcat(texto_formatado, aux_barra);
        strcat(texto_formatado, separador);
        if (cont == 1)
        {
            strcat(texto_formatado, barra);
            strcat(texto_formatado, barra);
        }
        else if (cont < 4)
            strcat(texto_formatado, barra);

        strcat(texto_formatado, separador);

        cont++;
        aux_barra = strtok(NULL, barra);
    }

    // Dois pontos
    organiza_vetor(texto_formatado, texto_auxiliar);
    aux_dois_pontos = strtok(texto_auxiliar, dois_pontos);

    cont = 1;
    while (aux_dois_pontos != NULL)
    {
        strcat(texto_formatado, aux_dois_pontos);
        strcat(texto_formatado, separador);
        if (cont < 3)
            strcat(texto_formatado, dois_pontos);

        cont++;
        aux_dois_pontos = strtok(NULL, dois_pontos);
    }

    // Underline
    organiza_vetor(texto_formatado, texto_auxiliar);
    aux_underline = strtok(texto_auxiliar, underline);

    cont = 1;
    while (aux_underline != NULL)
    {
        strcat(texto_formatado, aux_underline);
        strcat(texto_formatado, separador);
        if (cont == 1)
        {
            strcat(texto_formatado, underline);
            strcat(texto_formatado, separador);
        }

        cont++;
        aux_underline = strtok(NULL, underline);
    }

    // Ponto
    organiza_vetor(texto_formatado, texto_auxiliar);
    aux_ponto = strtok(texto_auxiliar, ponto);
    cont = 1;
    while (aux_ponto != NULL)
    {
        strcat(texto_formatado, aux_ponto);
        strcat(texto_formatado, separador);
        if (cont < 22)
            strcat(texto_formatado, ponto);
        strcat(texto_formatado, separador);

        cont++;
        aux_ponto = strtok(NULL, ponto);
    }

    // Traço 
    organiza_vetor(texto_formatado, texto_auxiliar);
    aux_traco = strtok(texto_auxiliar, traco);
    cont = 1;
    while (aux_traco != NULL)
    {
        strcat(texto_formatado, aux_traco);
        strcat(texto_formatado, separador);
        if (cont < 10)
            strcat(texto_formatado, traco);
        strcat(texto_formatado, separador);

        cont++;
        aux_traco = strtok(NULL, traco);
    }

    // Ajusta o texto
    organiza_vetor(texto_formatado, texto_auxiliar);
    token_espaco = strtok(texto_auxiliar, separador_espaco);

    while (token_espaco != NULL)
    {
        strcat(texto_formatado, token_espaco);
        strcat(texto_formatado, espaco);
        strcat(texto_formatado, separador_espaco);
        strcat(texto_formatado, espaco);

        token_espaco = strtok(NULL, separador_espaco);
    }

    organiza_vetor(texto_formatado, texto_auxiliar);
    token_separador = strtok(texto_auxiliar, separador);

    while (token_separador != NULL)
    {
        strcat(texto_formatado, token_separador);
        strcat(texto_formatado, espaco);
        strcat(texto_formatado, separador);
        strcat(texto_formatado, espaco);

        token_separador = strtok(NULL, separador);
    }

  organiza_vetor(texto_formatado, texto_atual);
}

// objetivo: Arrumar a pontuação do texto organizando os espaços
// parametros: char texto[] e char texto_atual[]
// retorno: char texto_atual[]
void arruma_pontuacao(char texto[], char texto_atual[])
{
    const char espaco[2] = " ";
    const char separador_espaco[2] = "*";
    const char separador[2] = "&";
    char texto_auxiliar[9999], texto_formatado[9999];
    char *token_espaco, *token_separador_espaco, *token_separador;

    texto_formatado[0] = '\0';

    strcpy(texto_auxiliar, texto);

    token_espaco = strtok(texto_auxiliar, espaco);

    while (token_espaco != NULL)
    {
        strcat(texto_formatado, token_espaco);
        token_espaco = strtok(NULL, espaco);
    }

    organiza_vetor(texto_formatado, texto_auxiliar);

    token_separador_espaco = strtok(texto_auxiliar, separador_espaco);

    while (token_separador_espaco != NULL)
    {
        strcat(texto_formatado, token_separador_espaco);
        strcat(texto_formatado, espaco);
        token_separador_espaco = strtok(NULL, separador_espaco);
    }

    organiza_vetor(texto_formatado, texto_auxiliar);

    token_separador = strtok(texto_auxiliar, separador);

    while (token_separador != NULL)
    {
        strcat(texto_formatado, token_separador);
        token_separador = strtok(NULL, separador);
    }

  organiza_vetor(texto_formatado, texto_atual);
}

// objetivo: Encontrar ocorrencias de uma palavra fornecida pelo usuário no texto
// parametros: char texto[9999]
// retorno: Nenhum
void quantidade_palavra(char texto[9999])
{
    char palavra[100];
    char texto_formatado[200][100];
    int quantidade_palavra[200], quantidade_palavra_total = 0, i, j;

    do
    {
        system("cls");
        printf("\nQUAL PALAVRA DESEJA PESQUISAR?: ");
        fflush(stdin);
        gets(palavra);

        if (strlen(palavra) == 1)
        {
            printf("\nPOR FAVOR, INFORME UMA PALAVRA!\n\n");
            system("pause");
        }
        else
        {
            for (i = 0; i < strlen(palavra); i++)
            {
                if (isspace(palavra[i]) != 0)
                {
                    printf("\n DIGITE APENAS UMA PALAVRA!\n\n");
                    system("pause");
                    break;
                }
            }
        }

    } while (isspace(palavra[i]) != 0 || strlen(palavra) == 1);

    char token_minuscula[100], palavra_minuscula[100], palavra_auxiliar[100];
    char texto_auxiliar[9999], linha_texto[9999], auxiliar[9999];
    const char espaco[] = " ";
    char *token;

    strcpy(texto_auxiliar, texto);
    inicia_matriz(texto_formatado);
   	minuscula_palavras(palavra, palavra_minuscula);
    formata_texto(texto_auxiliar, texto_formatado);

    for (i = 0; i < 200; i++)
        quantidade_palavra[i] = 0;

    j = 0;
    do
    {
        if (texto_formatado[j][0] != '/')
        {
            strcpy(auxiliar, texto_formatado[j]);

            separa_pontuacao(auxiliar, linha_texto);

            token = strtok(linha_texto, espaco);

            while (token != NULL)
            {
                token_minuscula[0] = '\0';
                palavra_auxiliar[0] = '\0';

                strcpy(palavra_auxiliar, token);

                minuscula_palavras(palavra_auxiliar, token_minuscula);

                if (token != NULL)
                {
                    if (strstr(token_minuscula, palavra_minuscula) != NULL)
                    {
                        if (strlen(token_minuscula) == strlen(palavra_minuscula))
                        {
                            quantidade_palavra[j]++;
                            quantidade_palavra_total++;
                        }
                    }
                }

                token = strtok(NULL, espaco);
            }

            if (quantidade_palavra[j] != 0)
                printf("\nA PALAVRA '%s' APARECE %d VEZ(ES) NA LINHA %d.", palavra, quantidade_palavra[j], j + 1);

            j++;
        }

    } while (texto_formatado[j][0] != '/');

    if (quantidade_palavra_total > 0)
        printf("\n\nOCORRENCIA TOTAL DA PALAVRA '%s' NO TEXTO: %d VEZ(ES)\n", palavra, quantidade_palavra_total);
    else
        printf("\n\nA PALAVRA '%s' NAO ESTA PRESENTE NO TEXTO!\n", palavra);
}

// objetivo: Altera a primeira ocorrencia de uma palavra por outra informada pelo ususário
// parametros: char texto[] e char texto_atual[9999]
// retorno: char texto_atual[9999]
void altera_primeira_ocorrencia(char texto[], char texto_atual[9999])
{
    char palavra_atual[100], palavra_nova[100];
    int i = 0;

    do
    {
        system("cls");
        printf("\nINFORME UMA PALAVRA DO TEXTO QUE DESEJA TROCAR: ");
        fflush(stdin);
        gets(palavra_atual);

        if (strlen(palavra_atual) == 1)
        {
            printf("\nPOR FAVOR, INFORME UMA PALAVRA!\n\n");
            system("pause");
        }
        else
        {
            for (i = 0; i < strlen(palavra_atual); i++)
            {
                if (isspace(palavra_atual[i]) != 0)
                {
                    printf("\nPOR FAVOR, INFORME APENAS UMA PALAVRA!\n\n");
                    system("pause");
                    break;
                }
            }
        }

    } while (isspace(palavra_atual[i]) != 0 || strlen(palavra_atual) == 1);

    do
    {
        system("cls");
        printf("\nINFORME UMA PALAVRA PARA SUBSTITUIR A PALAVRA '%s' NO TEXTO: ", palavra_atual);
        fflush(stdin);
        gets(palavra_nova);

        if (strlen(palavra_nova) == 1)
        {
            printf("\nPOR FAVOR, INFORME UMA PALAVRA!\n\n");
            system("pause");
        }
        else
        {
            for (i = 0; i < strlen(palavra_nova); i++)
            {
                if (isspace(palavra_nova[i]) != 0)
                {
                    printf("\nPOR FAVOR, INFORME APENAS UMA PALAVRA!\n\n");
                    system("pause");
                    break;
                }
            }
        }

    } while (isspace(palavra_nova[i]) != 0 || strlen(palavra_nova) == 1);
    printf("\n");

    char texto_auxiliar[9999], texto_ajustado[9999];
    char token_minuscula[100], palavra_minuscula[100], palavra_auxiliar[100];
    const char espaco[] = " ";
    char *token;
    int verificacao = 0;

    palavra_minuscula[0] = '\0';

    strcpy(texto_auxiliar, texto);

    minuscula_palavras(palavra_atual, palavra_minuscula);

    separa_pontuacao(texto_auxiliar, texto_ajustado);
    organiza_vetor(texto_ajustado, texto_auxiliar);

    token = strtok(texto_auxiliar, espaco);

    while (token != NULL)
    {
        token_minuscula[0] = '\0';
        palavra_auxiliar[0] = '\0';

        strcpy(palavra_auxiliar, token);

        minuscula_palavras(palavra_auxiliar, token_minuscula);

        if (strlen(token_minuscula) == strlen(palavra_minuscula))
        {
            if (strstr(token_minuscula, palavra_minuscula) != NULL && verificacao == 0)
            {
                strcat(texto_ajustado, palavra_nova);
                verificacao = 1;
            }
            else
                strcat(texto_ajustado, token);
        }
        else
            strcat(texto_ajustado, token);

        token = strtok(NULL, espaco);
    }
    if (verificacao == 0)
        printf("\t\tA PALAVRA '%s' NAO FOI ENCONTRADA NO TEXTO!\n\t\tTENTE NOVAMENTE MAIS TARDE...\n\n", palavra_atual);

  arruma_pontuacao(texto_ajustado, texto_atual);
}

// objetivo: Altera todas as ocorrencias de uma palavra por outra informada pelo ususário
// parametros: char texto[] e char texto_atual[9999]
// retorno: char texto_atual[9999]
void substituir_palavra(char texto[], char texto_atual[9999])
{
    char atual[100], nova[100];
    int i = 0;

    do
    {
        system("cls");
        printf("\n QUAL PALAVRA VOCE DESEJA TROCAR?: ");
        fflush(stdin);
        gets(atual);

        if (strlen(atual) == 1)
        {
            printf("\n INFORME UMA PALAVRA!\n\n");
            system("pause");
        }
        else
        {
            for (i = 0; i < strlen(atual); i++)
            {
                if (isspace(atual[i]) != 0)
                {
                    printf("\n APENAS UMA PALAVRA!\n\n");
                    system("pause");
                    break;
                }
            }
        }

    } while (isspace(atual[i]) != 0 || strlen(atual) == 1);

    do
    {
        system("cls");
        printf("\nDIGITE UMA PALAVRA PARA ALTERAR TODAS POR OUTRA '%s' NO TEXTO: ", atual);
        fflush(stdin);
        gets(nova);

        if (strlen(nova) == 1)
        {
            printf("\n INFORME UMA PALAVRA!\n\n");
            system("pause");
        }
        else
        {
            for (i = 0; i < strlen(nova); i++)
            {
                if (isspace(nova[i]) != 0)
                {
                    printf("\n DIGITE APENAS UMA PALAVRA!\n\n");
                    system("pause");
                    break;
                }
            }
        }

    } while (isspace(nova[i]) != 0 || strlen(nova) == 1);
    printf("\n");

    char texto_auxiliar[9999], texto_ajustado[9999];
    char token_minuscula[100], palavra_minuscula[100], palavra_auxiliar[100];
    const char espaco[] = " ";
    char *token;
    int verificacao = 0;

    strcpy(texto_auxiliar, texto);

    minuscula_palavras(atual, palavra_minuscula);

    separa_pontuacao(texto_auxiliar, texto_ajustado);
    organiza_vetor(texto_ajustado, texto_auxiliar);

    token = strtok(texto_auxiliar, espaco);

    while (token != NULL)
    {
        token_minuscula[0] = '\0';
        palavra_auxiliar[0] = '\0';

        strcpy(palavra_auxiliar, token);

       	minuscula_palavras(palavra_auxiliar, token_minuscula);

        if (strlen(token_minuscula) == strlen(palavra_minuscula))
        {
            if (strstr(token_minuscula, palavra_minuscula) != NULL)
            {
                strcat(texto_ajustado, nova);
                verificacao = 1;
            }
            else
                strcat(texto_ajustado, token);
        }
        else
            strcat(texto_ajustado, token);

        token = strtok(NULL, espaco);
    }
    if (verificacao == 0)
        printf("\t\tA PALAVRA '%s' NAO FOI ENCONTRADA NO TEXTO!\n\t\n\n", atual);

    arruma_pontuacao(texto_ajustado, texto_atual);
}

// objetivo: Colocar em maiuscula o primeiro caracter de cada inicio de frase
// parametros: char texto[] e char texto_atual[9999]
// retorno: char texto_atual[9999]
void primero_caracter(char texto[], char texto_atual[9999])
{
    char texto_auxiliar[9999], texto_ajustado[9999];
    char palavra[100];
    const char espaco[] = " ";
    const char ponto[] = ".";
    char *token;
    int verificacao = 0, cont = 0, cancela = 0;

    strcpy(texto_auxiliar, texto);

    texto_ajustado[0] = '\0';

    token = strtok(texto_auxiliar, espaco);

    while (token != NULL)
    {
        cancela = 0;
        if (verificacao == 1 || cont == 0)
        {
            strcpy(palavra, token);
            palavra[0] = toupper(palavra[0]);

            strcat(texto_ajustado, palavra);
            verificacao = 0;
            cont = 1;
            cancela = 1;
        }
        else if (strstr(token, ponto) != NULL)
        {
            strcat(texto_ajustado, token);
            verificacao = 1;
        }
        else if (cancela == 0)
            strcat(texto_ajustado, token);

        strcat(texto_ajustado, espaco);

        token = strtok(NULL, espaco);
    }

  strcpy(texto_atual, texto_ajustado);
}

// objetivo: Alinhar o texto à direita
// parametros: char texto[]
// retorno: Nenhum
void alinhar_direita(char texto[])
{
    char auxiliar[9999];
    char texto_formatado[200][100];
    int tamanho_espaco[200], i, ii, j = 0;

    auxiliar[0] = '\0';
    inicia_matriz(texto_formatado);

    formata_texto(texto, texto_formatado);

    for (i = 0; i < 200; i++)
    {
        tamanho_espaco[i] = 0;
        if (texto_formatado[i][0] != '/')
        {
            texto_formatado[i][strlen(texto_formatado[i]) - 1] = '\0';
            tamanho_espaco[i] = 80 - strlen(texto_formatado[i]);
        }
    }

    for (i = 0; i < 200; ++i)
    {
        if (strlen(texto_formatado[i]) != 80)
        {
            if (texto_formatado[i][0] != '/')
            {
                for (ii = 0; ii < tamanho_espaco[j]; ii++)
                {
                    if (ii == 0)
                        strcpy(auxiliar, " ");
                    else
                        strcat(auxiliar, " ");
                }

                j++;

                strcat(auxiliar, texto_formatado[i]);
                strcpy(texto_formatado[i], auxiliar);
                auxiliar[0] = '\0';
            }
        }
    }
    separa_linhas(texto_formatado);
}

// objetivo: Contar os espaços no texto
// parametros: char texto[200][100] e int quantidade_espacos[]
// retorno: int quantidade_espacos[]
void contador_espaco(char texto[200][100], int quantidade_espacos[])
{
    int cont = 0, i, j;

    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < strlen(texto[i]); j++)
        {
            if (texto[i][0] != '/')
            {
                if (isspace(texto[i][j]))
                    cont++;
            }
        }
        quantidade_espacos[i] = cont;
        cont = 0;
    }
}

// objetivo: Justificar o texto
// parametros: char texto[]
// retorno: Nenhum
void justificar(char texto[])
{
    int t_espaco[1000], q_espacos[1000], i, j = 0, cont = 0;
    char auxiliar[100], linha_texto[100], texto_formatado[200][100];
    char *token;

    linha_texto[0] = '\0';
    inicia_matriz(texto_formatado);
    formata_texto(texto, texto_formatado);

    for (i = 0; i < 200; i++)
    {
        t_espaco[i] = 0;
        if (texto_formatado[i][0] != '/')
        {
            texto_formatado[i][strlen(texto_formatado[i]) - 1] = '\0';
            t_espaco[i] = 80 - strlen(texto_formatado[i]);
        }
    }

    contador_espaco(texto_formatado, q_espacos);

    i = 0;
    do
    {
        do
        {
            auxiliar[0] = '\0';
            strcpy(linha_texto, texto_formatado[i]);
            token = strtok(linha_texto, " ");

            while (token != NULL)
            {
                if (q_espacos[i] >= t_espaco[i])
                {
                    if (token != NULL && j != q_espacos[i])
                    {
                        strcat(auxiliar, token);
                        strcat(auxiliar, "  ");
                        j++;
                    }
                    else
                    {
                        strcat(auxiliar, token);
                        strcat(auxiliar, " ");
                    }
                }
                else if (q_espacos[i] < t_espaco[i])
                {
                    if (token != NULL)
                    {
                        if (j != q_espacos[i])
                        {
                            strcat(auxiliar, token);
                            strcat(auxiliar, "    ");
                            j++;
                        }
                        else
                        {
                            strcat(auxiliar, token);
                            strcat(auxiliar, "  ");
                        }
                    }
                }
                token = strtok(NULL, " ");
            }

            auxiliar[strlen(auxiliar) - 1] = '\0';

            if (strlen(auxiliar) > 80)
            {
                cont++;
                j = cont;
            }
        } while (strlen(auxiliar) > 80);

        strcpy(texto_formatado[i], auxiliar);
        i++;
        cont = 0;
        j = 0;

    } while (texto_formatado[i][0] != '/');

    separa_linhas(texto_formatado);
}

// objetivo: Centralizar o texto
// parametros: char texto[]
// retorno: Nenhum
void centralizar(char texto[])
{
    char auxiliar[9999], t_formatado[200][100], espaco[200][2][100];
    int tamanho_espaco[200], i, cont = 0;

    inicia_matriz(t_formatado);
    formata_texto(texto, t_formatado);

    for (i = 0; i < 200; i++)
    {
        espaco[i][0][0] = '\0';
        espaco[i][1][0] = '\0';
    }
    auxiliar[0] = '\0';

    for (i = 0; i < 200; i++)
    {
        tamanho_espaco[i] = 0;
        if (t_formatado[i][0] != '/')
        {
            t_formatado[i][strlen(t_formatado[i]) - 1] = '\0';
            tamanho_espaco[i] = 80 - strlen(t_formatado[i]);
        }
    }

    i = 0;
    do
    {
        auxiliar[0] = '\0';
        while (cont != tamanho_espaco[i])
        {
            if (tamanho_espaco[i] != 0)
            {
                if (cont < tamanho_espaco[i] / 2)
                    strcat(espaco[i][0], " ");
                else
                    strcat(espaco[i][1], " ");
                cont++;
            }
        }
        if (strlen(espaco[i][0]) < strlen(espaco[i][1]))
        {
            strcat(espaco[i][0], " ");
            espaco[i][1][strlen(espaco[i][1]) - 1] = '\0';
        }
        if (t_formatado[i][0] != '/')
        {
            strcat(auxiliar, espaco[i][0]);
            strcat(auxiliar, t_formatado[i]);
            strcat(auxiliar, espaco[i][1]);
            strcpy(t_formatado[i], auxiliar);
        }
        i++;
        cont = 0;
    } while (tamanho_espaco[i] != 0);

    separa_linhas(t_formatado);
}

void menu(char texto_original[])
{
    int opc;
    char auxiliar_vetor[9999], texto_vetor[9999];
    char auxiliar_matriz[200][100], texto_matriz[200][100];
    char texto_original_matriz[200][100];

    strcpy(texto_vetor, texto_original);

    inicia_matriz(auxiliar_matriz);
    inicia_matriz(texto_matriz);
    inicia_matriz(texto_original_matriz);

    formata_texto(texto_original, texto_original_matriz);
    formata_texto(texto_vetor, texto_matriz);
    do
    {
        system("cls");
        printf("\n1 - Formatar Texto\n2 - Informar quantas vezes a palavra aparece");
        printf("\n3 - Alterar palavra\n4 - Alterar todas as palavras existentes");
        printf("\n5 - Texto em caixa-alta\n6 - Texto em caixa-baixa\n7 - Primeiro caracter de frase em caixa-alta");
        printf("\n8 - Alinhar a esquerda\n9 - Alinhar a direita\n10 - Justificar\n11 - Centralizar");
        printf("\n0 - Encerrar\n\nDigite sua opcao: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            system("cls");
            separa_linhas(texto_matriz);
            printf("\n\n");
            system("pause");
            break;
        case 2:
            system("cls");
            quantidade_palavra(texto_vetor);
            printf("\n\n");
            system("pause");
            break;
        case 3:
            system("cls");
            altera_primeira_ocorrencia(texto_vetor, auxiliar_vetor);
            organiza_vetor(auxiliar_vetor, texto_vetor);
            formata_texto(texto_vetor, auxiliar_matriz);
            organiza_matriz(auxiliar_matriz, texto_matriz);
            separa_linhas(texto_matriz);
            printf("\n\n");
            system("pause");
            break;
        case 4:
            system("cls");
            substituir_palavra(texto_vetor, auxiliar_vetor);
            organiza_vetor(auxiliar_vetor, texto_vetor);
            formata_texto(texto_vetor, auxiliar_matriz);
            organiza_matriz(auxiliar_matriz, texto_matriz);
            separa_linhas(texto_matriz);
            printf("\n\n");
            system("pause");
            break;
        case 5:
            system("cls");
            maiuscula(texto_vetor, auxiliar_vetor);
            organiza_vetor(auxiliar_vetor, texto_vetor);
            formata_texto(texto_vetor, auxiliar_matriz);
            organiza_matriz(auxiliar_matriz, texto_matriz);
            separa_linhas(texto_matriz);
            printf("\n\n");
            system("pause");
            break;
        case 6:
            system("cls");
            minuscula(texto_vetor, auxiliar_vetor);
            organiza_vetor(auxiliar_vetor, texto_vetor);
            formata_texto(texto_vetor, auxiliar_matriz);
            organiza_matriz(auxiliar_matriz, texto_matriz);
            separa_linhas(texto_matriz);
            printf("\n\n");
            system("pause");
            break;
        case 7:
            system("cls");
            // Primeiro diminui tudo pois o usuario pode ter jogado tudo em maiuscula
            minuscula(texto_vetor, auxiliar_vetor);
            organiza_vetor(auxiliar_vetor, texto_vetor);
            // Depois joga somente a primeira letra para maiuscula
            primero_caracter(texto_vetor, auxiliar_vetor);
            organiza_vetor(auxiliar_vetor, texto_vetor);
            formata_texto(texto_vetor, auxiliar_matriz);
            organiza_matriz(auxiliar_matriz, texto_matriz);
            separa_linhas(texto_matriz);
            printf("\n\n");
            system("pause");
            break;
        case 8:
            system("cls");
            separa_linhas(texto_matriz);
            printf("\n\n");
            system("pause");
            break;
        case 9:
            system("cls");
            alinhar_direita(texto_vetor);
            printf("\n\n");
            system("pause");
            break;
        case 10:
            system("cls");
            justificar(texto_vetor);
            printf("\n\n");
            system("pause");
            break;
        case 11:
            system("cls");
            centralizar(texto_vetor);
            printf("\n\n");
            system("pause");
            break;
        case 0:
            printf("\nOperacao Finalizada!\n\n");
            system("pause");
            break;

        default:
            printf("\nEscolha um numero valido!");
            system("pause");
            break;
        }
    } while (opc != 0);
}

int main()
{
    char text[] = "William Henry Gates III KBE GCIH (Seattle, 28 de outubro de 1955) mais conhecido como Bill Gates,\
 e um magnata, empresario, diretor executivo, investidor, filantropo e autor americano, que ficou conhecido por \
 fundar junto com Paul Allen a Microsoft a maior e mais conhecida empresa de software do mundo em termos de valor \
 de mercado. Gates ocupa atualmente o cargo de presidente nao-executivo da Microsoft alem de ser classificado \
 regularmente como a pessoa mais rica do mundo, posicao ocupada por ele de 1995 a 2007, 2009, e de 2014 a 2017. E \
 um dos pioneiros na revolucao do computador pessoal. Gates nasceu em uma familia de classe media de Seattle. Seu \
 pai, William H. Gates, era advogado de grandes empresas, e sua mae, Mary Maxwell Gates, foi professora da \
 Universidade de Washington e diretora de bancos. Bill Gates e as suas duas irmas, Kristanne e Libby, \
 frequentaram as melhores escolas particulares de sua cidade natal, e Bill tambem participou do \
 Movimento Escoteiro ainda quando jovem. Bill Gates, foi admitido na prestigiosa Universidade \
 Harvard, (conseguindo 1590 SATs dos 1600 possiveis) mas abandonou os cursos de Matematica e \
 Direito no terceiro ano para dedicar-se a Microsoft. Trabalhou na Taito com o desenvolvimento de \
 software basico para maquinas de jogos eletronicos (fliperamas) ate seus 16 anos. Tambem \
 trabalhou como pesquisador visitante na University of Massachusetts at Amherst, UMASS, Estados Unidos, quando \
 com 17 anos, desenvolveu junto com Paul Allen um software para leitura de fitas magneticas, com informacoes \
 de trafego de veiculos, em um chip Intel 8008. Com esse produto, Gates e Allen criaram uma empresa, \
 a Traf-o-Data, porem os clientes desistiram do negocio quando descobriram a idade dos donos. Enquanto \
 estudavam em Harvard, os jovens desenvolveram um interpretador da linguagem BASIC para um dos primeiros \
 computadores pessoais a serem lancado nos Estados Unidos - o Altair 8800. Apos um modesto sucesso na \
 comercializacao deste produto, Gates e Allen fundaram a Microsoft, uma das primeiras empresas no mundo \
 focadas exclusivamente no mercado de programas para computadores pessoais ou PCs. Gates adquiriu ao \
 longo dos anos uma fama de visionario (apostou no mercado de software na epoca em que o hardware era \
 considerado muito mais valioso) e de negociador agressivo, chegando muitas vezes a ser acusado por \
 concorrentes da Microsoft de utilizar praticas comerciais desleais. Nos anos 1980, a IBM, lider \
 no mercado de grandes computadores, resolveu entrar no mercado da microinformatica com o PC, \
 porem faltava o Sistema Operacional. Para isso, fechou contrato com a recem-criada Microsoft. Todavia, \
 a Microsoft nao possuia o software ainda. O jovem Bill Gates foi a uma pequena empresa que havia \
 desenvolvido o sistema para o processador da Intel e decidiu compra-lo, pagou cerca de US$ 50 mil, personalizou \
 o programa e vendeu-o por US$ 8 milhoes, mantendo a licenca do produto. Este viria a ser o MS-DOS. \
 Fonte: https://pt.wikipedia.org/wiki/Bill_Gates";

    // printf("\n\n%s", text);

    menu(text);

    return 0;
}