#include "algorithms.h"

// O(log n)
int binary_search(int *array, int length, int num)
{

    int left = 0, mid, right = length - 1;
    // left é o indice do inicio da array, right o fim
    while (left <= right)
    {
        mid = (left + right) / 2; // pega o meio da array
        if (array[mid] == num)
            return mid; // se o elemento no meio for o numero retorna o indice

        if (num < array[mid])
            right = mid - 1; // não sendo, pega o indice anterior ao meio, se o numero for menor
        else                 //?(num > array[mid])
            left = mid + 1;  // nao sendo, pega o indice apos ao do meio se o numero for maior
    }
    return -1;
}

//O(n)
int linear_search(int *array, int length, int num)
{
    for(int i=0;i<length;i++)
    {
        if(array[i]==num)
            return i;
    }
}