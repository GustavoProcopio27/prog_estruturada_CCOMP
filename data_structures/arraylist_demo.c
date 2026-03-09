#include <stdio.h>
#include "arraylist.h"
// gcc arraylist_demo.c arraylist.c -o demo; ./demo
int main()
{
    ArrayList *list = arraylist_init(sizeof(int));
    // Testando Add
    for(int i=1;i<11;i++){
        arraylist_add(list, i);
    }
    // Testando Get
    for (int i = 0; i < 10; i++)
    {
        printf("%d - listing with get:%d\n",i, arraylist_get(list, i));
    }
    // Testando Pop
    int popped = arraylist_pop(list, 5);
    printf("popped num:%d\n", popped);
    // Testando Get apos Pop
    for (int i = 0; i < 10; i++)
    {
        printf("%d - listing with get post pop: %d\n",i+1, arraylist_get(list, i));
    }
    // Testando indexOf
    int index = arraylist_indexOf(list, 1);
    printf("index of num 1:%d\n", index);
    // Testando count
    int count = arraylist_count(list, 2);
    printf("count of num 2:%d\n", count);

    arraylist_free(list);

    int arr[3] = {10,11,12};
    ArrayList *list2 = arraylist_init_from(arr, 3,5,sizeof(int));
    arraylist_print(list2);
    arraylist_free(list2);

    return 0;
}