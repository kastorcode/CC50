// dictionary.h CC50 Pset6 Declara a funcionalidade de um dicionário.

#ifndef DICTIONARY_H
#define DICTIONARY_H
#define SIZE 160000 // Tamanho da hashtable
#define LENGTH 45 // Comprimento máximo de uma palavra (pneumonoultramicroscopicsilicovolcanoconiosis)
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura lista

typedef struct no
{
    char palavra[LENGTH+1];
    struct no *prox;
}no;

// Protótipos de funções.

bool load(const char *dict);
bool check(const char *word);
unsigned int size(void);
bool unload(void);
unsigned int hash(const char *palavra);

#endif // DICTIONARY_H
