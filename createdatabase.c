#include "main.h"

/* Create Main Node */
Mlist *create_mainnode(char *word)
{
    Mlist *new = malloc(sizeof(Mlist));

    if(new == NULL)
        return NULL;

    strcpy(new->word, word);

    new->file_count = 1;
    new->sub_link = NULL;
    new->main_link = NULL;

    return new;
}

/* Create Sub Node */
Slist *create_subnode(char *filename)
{
    Slist *new = malloc(sizeof(Slist));

    if(new == NULL)
        return NULL;

    strcpy(new->file_name, filename);

    new->word_count = 1;
    new->sub_link = NULL;

    return new;
}

/* Create Database */

int create_database(Hash_t *arr, char *filename)
{
    
    FILE *fp = fopen(filename, "r");
  

    if(fp == NULL)
        return FAILURE;

         

    char word[100];

    while(fscanf(fp, "%s", word) != EOF)
    {
     

         int index = get_index(word);

        

        /* ---------------- CASE 1 ---------------- */

        if(arr[index].main_link == NULL)
        {
            Mlist *mnew = create_mainnode(word);
            Slist *snew = create_subnode(filename);

            mnew->sub_link = snew;

            arr[index].main_link = mnew;

            continue;
        }

        /* ---------------- CASE 2,3,4 ---------------- */

        Mlist *temp = arr[index].main_link;
        Mlist *prev_main = NULL;

        while(temp != NULL)
        {
            if(strcmp(temp->word, word) == 0)
            {
                /* Word Found */

                Slist *subtemp = temp->sub_link;
                Slist *prev_sub = NULL;

                while(subtemp != NULL)
                {
                    /* CASE 2 */

                    if(strcmp(subtemp->file_name, filename) == 0)
                    {
                        subtemp->word_count++;

                        break;
                    }

                    prev_sub = subtemp;
                    subtemp = subtemp->sub_link;
                }

                /* CASE 3 */

                if(subtemp == NULL)
                {
                    Slist *snew = create_subnode(filename);

                    prev_sub->sub_link = snew;

                    temp->file_count++;
                }

                break;
            }

            prev_main = temp;
            temp = temp->main_link;
        }

        /* CASE 4 */

        if(temp == NULL)
        {
            Mlist *mnew = create_mainnode(word);

            Slist *snew = create_subnode(filename);

            mnew->sub_link = snew;

            prev_main->main_link = mnew;
        }
    }

    fclose(fp);

    return SUCCESS;
}