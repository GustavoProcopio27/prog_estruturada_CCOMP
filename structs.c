#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Computer{
    int ram_quantity;
    float storage_quantity;
    char cpu_name[20];
    char motherboard[30];
    int power_capacity; 
};

// Typedef permite voce declarar um tipo personalizado, aumentando clareza e evitando de ter que ficar escrevendo
// struct, int toda hora

typedef int Idade;
typedef char Nome;

typedef struct {
    Idade age;
    Nome name[30];
} Person;

typedef struct {
    bool hasLaptop;
    Person owner;
} Backpack;

int main()
{
    // Para facilitar a vida, pense em structs como classes bostinhas
    struct Computer c1 = {16,512,"ryzen 5 4600g","asrock 520m",650};
    printf("Partes do PC: ram %dgb, sdd %.0fgb, cpu %s, placa-mãe %s, fonte %dw\n", 
    c1.ram_quantity,c1.storage_quantity,c1.cpu_name,c1.motherboard,c1.power_capacity);

    //modificando valores
    c1.storage_quantity = 1020.23;
    strcpy(c1.cpu_name,"ryzen 7 5700x");

    printf("Partes do PC: ram %dgb, sdd %.0fgb, cpu %s, placa-mãe %s, fonte %dw\n\n", 
    c1.ram_quantity,c1.storage_quantity,c1.cpu_name,c1.motherboard,c1.power_capacity);




    // Utilizando ponteiros com structs
    Person p1 = {23, "Kiara Watson"}; 
    Backpack b1 = {true, p1};   

    Backpack *backpack1Ptr = &b1;

    backpack1Ptr->owner.age = 24;

    printf("Kiara tem um laptop na mochila?\n");
    printf( backpack1Ptr->hasLaptop ? "sim\n": "não\n");

    printf("\n%s tem %d anos\n\n", backpack1Ptr->owner.name, backpack1Ptr->owner.age);


    return 0;
}