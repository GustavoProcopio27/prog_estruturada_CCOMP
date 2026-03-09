#include <stdio.h>
#include <string.h>

int main()
{
    char name[] = "Kiara";
    char surname[] = " Watson";
    char fullname[20];

    //concatena o valor de arg2 para arg1
    strcat(name, surname);

    printf("nome completo: %s\n\n", name);


    strcpy(fullname,name); //copia o valor de arg2, para arg1
    printf("fullname:%s\n\n",fullname);

    printf("Os nomes estão iguais?\n");
    printf(strcmp(name,fullname)==0 ? "sim\n" : "não\n");

    printf("\nO nome tem %d caracteres\n\n", strlen(fullname) );

    return 0;
}