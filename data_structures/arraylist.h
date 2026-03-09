#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stddef.h>

// O struct ArrayList define a struct de forma opaca escondendo a implementação, e o ArrayList vira o nome do typedef
// Assim seria possivel encapsular, so que eu nao quero mexer a fundo em fucking encapsulamento em C
// typedef struct ArrayList ArrayList;

/*
 Se trata de uma estrutura dinamica para armazenamento de dados
    int *data;
    size_t length           -> comprimento da array, número de itens inseridos
    size_t capacity         -> capacidade da array, número de elementos que podem ser inseridos antes da realocação dinamica para aumentar o espaço
    size_t element_size     -> tamanho em bytes de cada elemento
*/
typedef struct 
{
    int* data;
    size_t length;
    size_t capacity;
    size_t element_size;
} ArrayList;

/*
    Arguments:
        - size_t element_size -> tamanho do dado comportado que por enquanto é forçado a ser inteiro kkkkkkkkkkkk
    Return: 
        - ArrayList* -> Ponteiro para a ArrayList instanciada
*/
ArrayList *arraylist_init(size_t element_size);

ArrayList *arraylist_init_from(int *arr, size_t length, size_t capacity, size_t element_size);

void arraylist_add(ArrayList *arrayList, int element);
int arraylist_pop(ArrayList *arrayList, int index);

int arraylist_get(ArrayList *arrayList, int index);
void arraylist_set(ArrayList *arrayList, int index, int element);

void arraylist_clear(ArrayList *arrayList);
void arraylist_print(ArrayList*);
int arraylist_indexOf(ArrayList *arrayList, int element);
int arraylist_count(ArrayList *arrayList, int element);

void arraylist_free(ArrayList *arrayList);

#endif

