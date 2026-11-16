#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 27

#define SUCCESS 0
#define FAILURE -1

/* Sub Node */
typedef struct sub_node
{
    int word_count;
    char file_name[50];
    struct sub_node *sub_link;

} Slist;

/* Main Node */
typedef struct main_node
{
    int file_count;
    char word[50];

    Slist *sub_link;

    struct main_node *main_link;

} Mlist;

/* Hash Table */
typedef struct hash_table
{
    int index;
    Mlist *main_link;

} Hash_t;

/* Function Prototypes */

void create_hashtable(Hash_t *arr);

int validate_file(char *filename);

int create_database(Hash_t *arr, char *filename);

void display_database(Hash_t *arr);

int search_database(Hash_t *arr, char *word);

int save_database(Hash_t *arr, char *filename);

int update_database(Hash_t *arr, char *filename);
Mlist *create_mainnode(char *word);

Slist *create_subnode(char *filename);

/* Hash Function */
int get_index(char *word);

#endif