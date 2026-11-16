#include "main.h"

void display_database(Hash_t *arr)
{
    for(int i = 0; i < SIZE; i++)
    {
        if(arr[i].main_link != NULL)
        {
            Mlist *temp = arr[i].main_link;

            while(temp)
            {
                printf("\n[%d] ", i);
                printf("%s ", temp->word);
                printf("%d ", temp->file_count);

                Slist *sub = temp->sub_link;

                while(sub)
                {
                    printf("%s %d ",
                           sub->file_name,
                           sub->word_count);

                    sub = sub->sub_link;
                }

                printf("\n");

                temp = temp->main_link;
            }
        }
    }
}