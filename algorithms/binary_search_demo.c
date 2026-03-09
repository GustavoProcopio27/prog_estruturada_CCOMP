#include <stdio.h>
#include <stdlib.h>

// importante: Para este algoritmo a array deve estar ordenada
// Tempo O(log n)
int binary_search(int* array,int length, int num)
{

    int left = 0, mid, right = length-1;
    // left é o indice do inicio da array, right o fim
    while(left<=right)
    {
        mid = (left + right)/ 2; // pega o meio da array
        if(array[mid] == num) 
            return mid; // se o elemento no meio for o numero retorna o indice
    
        if(num < array[mid]) 
            right = mid-1; // não sendo, pega o indice anterior ao meio, se o numero for menor
        else//?(num > array[mid]) 
            left = mid+1; // nao sendo, pega o indice apos ao do meio se o numero for maior
    }
    return -1;
}

int* create_array(int length)
{
    int *vector = (int *) malloc(length * sizeof(int)); // aloca uma array de length elementos inteiros, 
    // o retorno para vector se torna o endereço de memoria do primeiro elemento
    // vector[i] == *(vector [primeira posicao] + i) com o * fazendo desreferenciamento e logo acessando o valor

    if(vector == NULL) exit(1);

    for(int i=0;i<length;i++)
    {
        vector[i]=i+1;
    }

    /*

        O acontecimento do 2[vector] é por causa da aritmetica de ponteiros, de modo que
        vector[2] é traduzido internamente para *(vector+2) acessando assim o valor,e 
        2[vector] é traduzido internamente para *(2+vector)


    */
    if(vector[2]==*(vector+2)) printf("Olha sa porra\n");
    if(2[vector]==*(vector+2)) printf("Pior, olha sa porra\n");

    return vector; 
}

int main()
{
    int array_lenght = 100, searched_num;

    int *array = create_array(100);



    printf("Entre com um numero: ");
    scanf("%d", &searched_num);

    printf("A posicao do numero na array eh: %d", binary_search(array, array_lenght, searched_num));

    free(array);

    return 0;
}