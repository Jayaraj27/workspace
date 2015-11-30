/*
 * This program finds if a given string is a palindrome or not
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static bool
is_palindrome(char *str)
{
    char *front = str;
    char *rear = str + strlen(str) - 1;

    if (*rear == '\n') {
        //fgets could have added \n, if added then it needs to be removed
        *rear = '\0';
        rear--;
    }

    while (front < rear) {
        if (*front != *rear) {
            return 0;
        }
        front++;
        rear--;
    }
    return 1;
}

int
main(int  argc,
     char **argv)
{
    char str[1000];
    printf("Enter string: ");
    fgets(str, 1000, stdin);

    if (is_palindrome(str)) {
        printf("String is palindrome!!!\n");
    } else {
        printf("String is not palindrome!!!\n");
    }

    return 0;
}
