// dictionary.c CC50 Pset6 Implementa a funcionalidade de um dicionário.

#include "dictionary.h"

no *hashtable[SIZE] = {NULL};
unsigned int palavras = 0;

// Carrega dict na memória. Retorna true se bem sucedido senão false.

bool
load(const char *dict)
{
    FILE *fp = fopen(dict, "r");
    if (fp == NULL)
        return false;

    char palavra[LENGTH+1];
    unsigned int indice;

    while (fscanf(fp,"%s\n",palavra) != EOF)
    {
        palavras++;
        no *novo = (no*)malloc(sizeof(no));
        strcpy(novo->palavra, palavra);
        indice = hash(palavra);
        if (hashtable[indice] == NULL)
        {
            hashtable[indice] = novo;
            novo->prox = NULL;
        }
        else
        {
            novo->prox = hashtable[indice];
            hashtable[indice] = novo;
        }
    }
    return true;
}

// Retorna true se a palavra está no dicionário senão false.

bool
check(const char *word)
{
    int len = strlen(word);
    char palavra[LENGTH+1];
    for (int i = 0; i < len; i++)
        palavra[i] = tolower(word[i]);
    palavra[len] = '\0';

    unsigned int indice = hash(palavra);
    if (hashtable[indice] == NULL)
        return false;

    no *cursor = hashtable[indice];
    while (cursor != NULL)
    {
        if (strcmp(palavra, cursor->palavra) == 0)
            return true;
        cursor = cursor->prox;
    }
    return false;
}

// Retorna o número de palavras no dicionário carregado.

unsigned int
size(void)
{
    return palavras;
}

// Descarrega dicionário da memória. Retorna true se bem sucedido senão false.

bool
unload(void)
{
    unsigned int indice = 0;
    while (indice < SIZE)
    {
        if (hashtable[indice] == NULL)
            indice++;
        else
        {
            while (hashtable[indice] != NULL)
            {
                no *cursor = hashtable[indice];
                hashtable[indice] = cursor->prox;
                free(cursor);
            }
            indice++;
        }
    }
    return true;
}

// Função hash, transforma palavra em número.

unsigned int
hash(const char *palavra)
{
    unsigned int hash = 0, n;
    for (int i = 0; palavra[i] != '\0'; i++)
    {
        if (isalpha(palavra[i])) // Caso alfabeto
            n = palavra[i]-'a'+1;
        else // Caso vírgula
            n = 27;
        hash = ((hash << 3) + n) % SIZE;
    }
    return hash;
}
