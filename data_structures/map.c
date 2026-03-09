typedef struct 
{
    char* key;
    int keys_quantity;
    char* value;
    int values_quantity;
} Map;

char* get();
void update();
void clear();
char* get_keys();
char* get_values();