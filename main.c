#include "main.h"

int main(int argc, char *argv[])
{
    Hash_t arr[SIZE];

    create_hashtable(arr);

    int choice;
    char word[50];
    int db_created = 0;
    int db_saved = 0;

    while (1)
    {
        printf("\n============================\n");
        printf("  INVERTED SEARCH PROJECT\n");
        printf("============================\n");

        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Search Database\n");
        printf("4. Save Database\n");
        printf("5. Update Database\n");
        printf("6. Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            if (db_created)
            {
                printf("Database already created\n");
                break;
            }

            for (int i = 1; i < argc; i++)
            {
                if (validate_file(argv[i]) == SUCCESS)
                {
                    printf("%s -> Valid File\n", argv[i]);

                    create_database(arr, argv[i]);
                }
                else
                {
                    printf("%s -> Invalid File\n", argv[i]);
                }
            }

            db_created = 1;

            printf("Database Created Successfully\n");

            break;
        case 2:

            if (!db_created)
            {
                printf("Database Empty\n");
                break;
            }

            display_database(arr);

            break;

        case 3:

            if (!db_created)
            {
                printf("Database Empty\n");
                break;
            }

            printf("Enter word to search : ");
            scanf("%s", word);

            search_database(arr, word);

            break;
        case 4:

            if (!db_created)
            {
                printf("Create/Update Database First\n");
                break;
            }

            if (save_database(arr, "backup.txt") == SUCCESS)
            {
                db_saved = 1;
                printf("Database Saved Successfully\n");
            }
            else
            {
                printf("Database Save Failed\n");
            }

            break;
        case 5:

            if (db_created)
            {
                printf("Database Already Exists\n");
                printf("Restart Program To Update From Backup\n");
                break;
            }

            create_hashtable(arr);

            if (update_database(arr, "backup.txt") == SUCCESS)
            {
                db_created = 1;

                printf("Database Updated Successfully\n");
            }
            else
            {
                printf("Database Update Failed\n");
            }

            break;

        case 6:

            printf("Exiting Program...\n");
            exit(0);

        default:

            printf("Invalid Choice\n");
        }
    }

    return 0;
}