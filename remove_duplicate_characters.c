/*
 * This program removes duplicates from a given string, the program makes use
 * of hash table.
 */

#include <stdio.h>
#include <stdbool.h>

int
main(int  argc,
     char **argv)
{
    char str[1000];
    char *current = str;
    char *next = current + 1;;
    bool hash[256] = {0};

    printf("Enter string: ");
    fgets(str, 1000, stdin);
    printf("String is %s\n", str);

    while (*next != '\0') {
        if (!hash[*current]) {
            hash[*current] = 1;
            current++;
            next++;
        } else {
            if (!hash[*next]) {
                hash[*next] = 1;
                *current = *next;
                next++;
                current++;
            } else {
                next++;
            }
        }
    }

    if (hash[*current]) {
        *current = *next;
    } else {
        *(current + 1) = *next;
    }

    printf("After string is %s\n", str);
    return 0;
}
