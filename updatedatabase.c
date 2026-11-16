#include "main.h"

int update_database(Hash_t *arr, char *filename)
{
    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
        return FAILURE;

    char line[500];

    while(fgets(line, sizeof(line), fp))
    {
        int index;
        int file_count;

        char *token;

        /* Remove newline */
        line[strcspn(line, "\n")] = '\0';

        /* First token : #7 */
        token = strtok(line, ";");

        if(token == NULL || token[0] != '#')
            continue;

        index = atoi(token + 1);

        /* Word */
        token = strtok(NULL, ";");

        if(token == NULL)
            continue;

        char word[50];
        strcpy(word, token);

        /* File Count */
        token = strtok(NULL, ";");

        if(token == NULL)
            continue;

        file_count = atoi(token);

        /* Create Main Node */
        Mlist *mnew = malloc(sizeof(Mlist));

        strcpy(mnew->word, word);
        mnew->file_count = file_count;

        mnew->sub_link = NULL;
        mnew->main_link = NULL;

        Slist *last_sub = NULL;

        /* Read file_count subnodes */
        for(int i = 0; i < file_count; i++)
        {
            char fname[50];
            int count;

            token = strtok(NULL, ";");
            if(token == NULL)
                break;

            strcpy(fname, token);

            token = strtok(NULL, ";");
            if(token == NULL)
                break;

            count = atoi(token);

            Slist *snew = malloc(sizeof(Slist));

            strcpy(snew->file_name, fname);
            snew->word_count = count;
            snew->sub_link = NULL;

            if(mnew->sub_link == NULL)
            {
                mnew->sub_link = snew;
                last_sub = snew;
            }
            else
            {
                last_sub->sub_link = snew;
                last_sub = snew;
            }
        }

        /* Insert Main Node into Hash Table */
        if(arr[index].main_link == NULL)
        {
            arr[index].main_link = mnew;
        }
        else
        {
            Mlist *temp = arr[index].main_link;

            while(temp->main_link)
            {
                temp = temp->main_link;
            }

            temp->main_link = mnew;
        }
    }

    fclose(fp);

    return SUCCESS;
}