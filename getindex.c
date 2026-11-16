#include "main.h"

int get_index(char *word)
{
    char ch = word[0];

    /* lower case letter */
    if(ch >= 'a' && ch <= 'z')
    {
        return (ch - 'a');
    }

    /* upper case letter */
    if(ch >= 'A' && ch <= 'Z')
    {
        return (ch - 'A');
    }

    /* special characters and digits */
    return 26;
}