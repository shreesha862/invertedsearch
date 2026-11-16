#include "main.h"

int validate_file(char *filename)
{
    char *ptr;

    ptr = strstr(filename,".txt");

    if(ptr == NULL)
    {
        return FAILURE;
    }

    if(strcmp(ptr,".txt") != 0)
    {
        return FAILURE;
    }

    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        return FAILURE;
    }

    fseek(fp,0,SEEK_END);

    if(ftell(fp) == 0)
    {
        fclose(fp);
        return FAILURE;
    }

    fclose(fp);

    return SUCCESS;
}