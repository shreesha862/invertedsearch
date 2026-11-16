#include "main.h"

void create_hashtable(Hash_t *arr)
{
    for(int i = 0; i < SIZE; i++)
    {
        arr[i].index = i;
        arr[i].main_link = NULL;
    }
}