#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TODO Perguntar ao posner como transformar isso em algo utilizavel com tipos genericos

typedef struct {
    int *data;
    size_t length;
    size_t capacity; 

} ArrayList;


ArrayList* arraylist_init()
{
    ArrayList *ptr = (ArrayList*) malloc(sizeof(ArrayList)); 


    ptr->capacity = 1;
    ptr->length = 0;
    ptr->data = (int *) malloc(ptr->capacity * sizeof(int));

    return ptr; 
}

ArrayList* arraylist_init(int* arr, size_t length, size_t capacity)
{
    ArrayList *ptr = (ArrayList*) malloc(sizeof(ArrayList)); 


    if (length>capacity || arr==NULL)
    {
        ptr->length = length;
        ptr->capacity = capacity;
        ptr->data = (int*) malloc(ptr->capacity * sizeof(int));

        for(int i=0;i<length;i++)
        {
            ptr->data[i] = arr[i];
        }
        return ptr;
    }
    return NULL;
}


void arraylist_add(ArrayList* arrayList, int element)
{
    arrayList->length += 1;                         // aumentar o =atributo com o comprimento da array
    if(arrayList->length>= arrayList->capacity)     // checa se isso passa da capacidade dela e aumenta em 1.5x, evitando alocar altas quantidades
    {    
        arrayList->capacity*= 3/2 + 1;
        int *temp = realloc(arrayList->data, arrayList->capacity * sizeof(int));
        if(temp==NULL) { exit(1); }
        arrayList->data = temp;
    }

    arrayList->data[arrayList->length-1] = element; //adiciona o elemento na array

}

int arraylist_pop(ArrayList *arrayList, int index)
{

    if(index>=arrayList->length || index<0) //se ele tentar tirar um elemento numa posição nao preenchida
    {
        return -1;
    }

    int element = arrayList->data[index];
    arrayList->length-=1;

    memmove(&arrayList->data[index], &arrayList->data[index+1], (arrayList->length-index)*sizeof(int));
    // colocando o destino como a partir do endereço de memoria do elemento retirado, 
    // pegando os elementos apos ele (index+1), e o numero de bytes a serem movidos
    // Assim um pop(5) numa array deve tacar os elementos começando no indice 5 1 posição para tras  


    return element;
}


int arraylist_get(ArrayList *arrayList, int index)
{
    if(index<0 || index>=arrayList->length)
    {
        return -1;
    }
    return arrayList->data[index];
}


void arraylist_set(ArrayList *arrayList, int index, int element)
{
    if(index<0 || index>=arrayList->length)
    {
        return;
    }
    arrayList->data[index] = element;
}


void arraylist_clear(ArrayList *arrayList)
{
    arrayList->length=0;
    arrayList->capacity = 1;
    free(arrayList->data);
    arrayList->data = malloc(arrayList->capacity * sizeof(int));
}


int arraylist_indexOf(ArrayList* arrayList, int element)
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


int arraylist_count(ArrayList *arrayList, int element)
{
    int counter=0;
    for(int index=0;index<arrayList->length;index++)
        if(arrayList->data[index]==element)
            counter++;

    return counter;
}