#include "main.h"

int search_database(Hash_t *arr, char *word)
{
    int index = get_index(word);

    Mlist *temp = arr[index].main_link;

    while(temp)
    {
        if(strcmp(temp->word, word) == 0)
        {
            printf("\nWord Found\n");
            printf("Word : %s\n", temp->word);
            printf("File Count : %d\n", temp->file_count);

            Slist *sub = temp->sub_link;

            while(sub)
            {
                printf("%s -> %d\n",
                        sub->file_name,
                        sub->word_count);

                sub = sub->sub_link;
            }

            return SUCCESS;
        }

        temp = temp->main_link;
    }

    printf("Word Not Found\n");

    return FAILURE;
}