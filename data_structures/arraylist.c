#include "arraylist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// TODO Perguntar ao posner como transformar isso em algo utilizavel com tipos genericos

// TODO: Passos para fazer sem ter que quintuplicar a quantidade de codigo:
// 1- Descobrir como tornar data em um pointer generico sem *expression must be a pointer to a complete object type*
// 2- Criar macros para  Criar macros para arraylist_add arraylist_indexOf arraylist_set arraylist_count

//  Pelo que vi em https://www.youtube.com/watch?v=1zTvbXVEP88, da pra tentar usar esta generic keyword, mas ia aumentar muito o codigo e a repetição

ArrayList *arraylist_init(size_t element_size)
{
    ArrayList *ptr = (ArrayList*) malloc(sizeof(ArrayList)); 

    ptr->capacity = 1;
    ptr->length = 0;
    ptr->element_size = element_size;
    ptr->data = malloc(ptr->capacity * element_size);

    return ptr; 
}



ArrayList* arraylist_init_from(int* arr, size_t length, size_t capacity, size_t element_size)
{

    if (length>capacity || arr==NULL)
    {
        return NULL;
    }
    ArrayList *ptr = (ArrayList *)malloc(sizeof(ArrayList));

    ptr->length = length;
    ptr->capacity = capacity;
    ptr->element_size = element_size;
    ptr->data = (int *)malloc(ptr->capacity * element_size);

    for (int i = 0; i < length; i++)
    {
        ptr->data[i] = arr[i];
    }
    return ptr;
}

void rezise_list(ArrayList *arrayList)
{
    arrayList->capacity *= 3 / 2 + 1;
    int *temp = realloc(arrayList->data, arrayList->capacity * arrayList->element_size);
    if (temp == NULL)
    {
        exit(1);
    }
    arrayList->data = temp;
}

void arraylist_add(ArrayList* arrayList, int element)
{
    arrayList->length += 1;                         // aumentar o atributo comprimento da array
    if(arrayList->length>= arrayList->capacity)     // checa se isso passa da capacidade dela e aumenta em 1.5x, evitando alocar altas quantidades
    {    
        rezise_list(arrayList);
    }

    arrayList->data[arrayList->length-1] = element; //adiciona o elemento na array

}


void arraylist_print(ArrayList *arrayList)
{
    for(int i = 0;i<arrayList->length;i++)
    {
        printf("index %i : %d\n", i, arrayList->data[i]);
    }
}




int arraylist_pop(ArrayList *arrayList, int index)
{

    if(index>=arrayList->length || index<0) //se ele tentar tirar um elemento numa posição nao preenchida
    {
        return -1;
    }

    int element = arrayList->data[index];
    arrayList->length-=1;

    memmove(&arrayList->data[index], &arrayList->data[index+1], (arrayList->length-index)*arrayList->element_size);
    // colocando o destino como a partir do endereço de memoria do elemento retirado, 
    // pegando os elementos apos ele (index+1), e o numero de bytes a serem movidos
    // Assim um pop(5) numa array deve tacar os elementos começando no indice 5 1 posição para tras  


    return element;
}

int arraylist_indexOf(ArrayList *arrayList, int element)
{

    // Por enquanto na implementação deste metodo deixarei com Linear Search,
    // futuramente pode ser otimizado checar o tamanho recebido
    // e no metodo decidir se usa linear ou binary search

    for (int index = 0; index < arrayList->length; index++)
    {
        if (arrayList->data[index] == element)
            return index;
    }
    return -1;
}

void arraylist_set(ArrayList *arrayList, int index, int element)
{
    if (index < 0 || index >= arrayList->length)
    {
        return;
    }
    arrayList->data[index] = element;
}




int arraylist_count(ArrayList *arrayList, int element)
{
    int counter = 0;
    for (int index = 0; index < arrayList->length; index++)
        if (arrayList->data[index] == element)
            counter++;

    return counter;
}

int arraylist_get(ArrayList *arrayList, int index)
{
    if(index<0 || index>=arrayList->length)
    {
        return -1;
    }
    return arrayList->data[index];
}


void arraylist_clear(ArrayList *arrayList)
{
    arrayList->length=0;
    arrayList->capacity = 1;
    free(arrayList->data);
    arrayList->data = malloc(arrayList->capacity * arrayList->element_size);
}


void arraylist_free(ArrayList *arrayList)
{
    free(arrayList->data);
    free(arrayList);
}