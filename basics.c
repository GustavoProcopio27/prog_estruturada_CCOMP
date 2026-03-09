#include <stdio.h>

int get_factorial_of(int num)
{
    if(num<=0) return 1;
    return num * get_factorial_of(num-1);
}


int main()
{
    int num; 
    char A_ascii = 65;  // variaveis do tipo caracter são valores ASCII, declarando elas com o valor de um número
                        // ira assumir o valor do digito ascii com codigo referente ao numero
    double decimal1 = 0.2, decimal2 = 0.1;

    printf("O caracter tem output: %c \n",A_ascii);
    printf("A soma dos números floats declarados da: %lf\n", decimal1+decimal2);

    printf("Entre com o número desejado: ");
    scanf("%d", &num);

    printf("\nA saída é: %d \n\n", get_factorial_of(num));

    return 0; 
}