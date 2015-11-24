/*
 * This program reverses a given string
 */

#include <stdio.h>
#include <string.h>

#define SWAP(x, y) do \
{                     \
    x ^= y;           \
    y ^= x;           \
    x ^= y;           \
} while (0)

static void
reverse_string(char *str)
{
    if (str) {
        char *end = str + strlen(str) - 1;

        while (str < end) {
            SWAP(*str, *end);
            str++;
            end--;
        }
    }
}

int
main(int  argc,
     char **argv)
{
    char str[100];

    printf("Enter string: ");
    fgets(str, 99, stdin);
    reverse_string(str);
    printf("Reversed string is %s\n", str);
    return 0;
}

