/*
 * This program implements the strtok glib function
 *
 * Description: from man page
 * The strtok() function is used to isolate sequential tokens in a
 * null-terminated string, str.  These tokens are separated in the
 * string by at least one of the characters in sep. The first time that
 * strtok() is called, str should be specified; subsequent calls, wishing
 * to obtain further tokens from the same string, should pass a null pointer
 * instead. The separator string, sep, must be supplied each time, and may
 * change between calls.
 */

#include <stdio.h>
#include <string.h>

static char*
my_strtok(char *p,
          char *delm)
{
    static char         arr[100];
    static unsigned int i = 0;
    unsigned int        j = 0;
    unsigned int        k = 0;
    static char         word[100];

    if (p) {
        strncpy(arr, p, 100);
        i = 0;
    }

    if (!delm) {
        return NULL;
    }

    while (arr[i] != '\0') {
        while (delm[j] != '\0') {
            if (arr[i] == delm[j]) {
                i++;
                word[k] = '\0';
                return word;
            }
            j++;
        }
        word[k] = arr[i];
        k++;
        i++;
        j = 0;
    }

    if (arr[i] == '\0') {
        return NULL;
    }

    word[k] = '\0';
    return word;
}

int
main(int  argc,
     char **argv)
{
    char a[] = " - This is how I split, how can you do? Tell me!!!";
    char *p;

    p = my_strtok(a, "-,?! ");

    while(p) {
        printf("%s\n", p);
        p = my_strtok(NULL, "-,?! ");
    }
    
    return 0;
}
