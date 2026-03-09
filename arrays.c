#include <stdio.h>

int main()
{
    int arrayInt[]={1,2,3,4,5};
    char string[]="pointers";

    int len = (int) sizeof(arrayInt)/sizeof(arrayInt[0]); 

    printf("O tamanho da primeira array é %d", len);

    return 0;
}