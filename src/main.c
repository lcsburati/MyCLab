#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"


int main(int argc, char **argv)
{
    if (argc != 1)
    {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }

    int choice;

    do 
    {
        printf("Which function do you want to use?\n");
        printf("1. my_strlen\n");
        printf("2. my_tolower\n");
        printf("3. my_toupper\n");
        printf("4. my_strcmp\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        char str[100];

    switch (choice)
    {
        case 1: 
            printf("Enter a string: ");
            scanf("%s", str);
            int length = my_strlen(str);
            printf("Length of the string: %d\n", length);
            break;

        case 2:
            printf("Enter a string: ");
            scanf("%s", str);
            char *tolower_str = my_tolower(str);
            printf("Lowercase string: %s\n", tolower_str);
            free(tolower_str);
            break;

        case 3:
            printf("Enter a string: ");
            scanf("%s", str);
            char *toupper_str = my_toupper(str);
            printf("Uppercase string: %s\n", toupper_str);
            free(toupper_str);
            break;

        case 4:
            printf("Enter first string to compare: ");
            scanf("%s", str);
            printf("Enter second string to compare: ");
            char str2[100];
            scanf("%s", str2);
            int result = my_strcmp(str, str2);

            if (result == 0)
            {
                printf("The strings are equal\n");
            }
            else
            {
                printf("The strings are not equal\n");
                double difference_percentage = my_strcmp_percent(str, str2);
                // Alterado difference para equality
                printf("Equality percentage: %f\n", difference_percentage);
            }
            break;

        case 5:
            printf("Program Finished\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
    }   

    } while (choice != 5);

    
    return 0;
}
    
    