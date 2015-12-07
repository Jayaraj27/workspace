/*
 * This program finds if 2 strings are anagrams
 */

#include <stdio.h>
#include <stdbool.h>

static bool
is_anagram(char *s1,
           char *s2)
{
    unsigned int count1[256] = {0};
    unsigned int count2[256] = {0};
    unsigned int i;

    while (!(*s1 == '\0') && !(*s2 == '\0')) {
        count1[*s1]++;
        count2[*s2]++;
        s1++;
        s2++;
    }

    if (*s1 != *s2) {
        return 0;
    }

    for (i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) {
            return 0;
        }
    }
    return 1;
}

int
main(int  argc,
     char **argv)
{
    char s1[100];
    char s2[100];

    printf("Enter string 1: ");
    fgets(s1, 100, stdin);
    printf("Enter string 2: ");
    fgets(s2, 100, stdin);

    if (is_anagram(s1, s2)) {
        printf("s1 and s2 are anagrams\n");
    } else {
        printf("s1 and s2 are not anagrams\n");
    }
    return 0;
}
