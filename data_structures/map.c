#include <stdio.h>

typedef struct{
    char* key;
    void* value;
} map_entry;

typedef struct 
{
    map_entry* map_entry;
    size_t size;
    size_t capacity;
} Map;


void* get(Map* map, char* key)
{

};
void update(Map* map, char* key, void* value)
{


};
void clear(Map* map)
{
    free(map->map_entry);
    map->size=0;
    map->capacity=sizeof(map_entry);
};
char* get_keys();
char* get_values();

char* pop();
int size();
Map* fromkeys();
