* int -> f2 ou 4 bytes. Formato: *(%d ou %i)*
* char -> 1 byte, sendo um valor ASCII. Formato: *(%c)*
* float -> 4 bytes, 6-7 digitos de precisão . Formato: *(%f)*
* double -> 8 bytes, 15 digitos de precisão .Formato: *(%lf)*
* string -> em C, não existe um tipo strings e estas são representadas por arrays de caracteres. formato: *(%s)*
* unsigned integer (size_t)->unsigned types so armazenam valores nao negativos 
* bool -> precisa incluir <stdbool.h> 


* **numeros cientificos** 
```c
float avogrado = 6.02214076e23
printf("%.1f",avogrado)
``` 

## Conversão: 
```C
#include <stdio.h>
int main()
{
    int n1=15,n2=2;
    float res;

    res = (float) n1 / n2
}
```