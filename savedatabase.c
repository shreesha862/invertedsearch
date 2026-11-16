#include "main.h"

int save_database(Hash_t *arr, char *filename)
{
    FILE *fp = fopen(filename, "w");

    if(fp == NULL)
        return FAILURE;

    for(int i = 0; i < SIZE; i++)
    {
        if(arr[i].main_link != NULL)
        {
            Mlist *temp = arr[i].main_link;

            while(temp)
            {
                fprintf(fp,
                        "#%d;%s;%d;",
                        i,
                        temp->word,
                        temp->file_count);

                Slist *sub = temp->sub_link;

                while(sub)
                {
                    fprintf(fp,
                            "%s;%d;",
                            sub->file_name,
                            sub->word_count);

                    sub = sub->sub_link;
                }

                fprintf(fp, "#\n");

                temp = temp->main_link;
            }
        }
    }

    fclose(fp);

    return SUCCESS;
}
