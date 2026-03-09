typedef struct 
{
    char** keys;
    int keys_quantity;
    char** values;
    int values_quantity;
} Map;


char* get();
void update();
void clear();
char* get_keys();
char* get_values();

char* pop();
int size();
Map* fromkeys();
