/*
 * This program finds if 2 srtings have a edit distance of 1 or not
 *
 * An edit between two strings is one of the following changes.
 *
 * 1. Add a character
 * 2. Delete a character
 * 3. Change a character
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static bool
find_edit_distance(char         *s1,
                   char         *s2,
                   unsigned int len_s1,
                   unsigned int len_s2)
{
    bool         flag = 0;
    unsigned int i = 0;
    unsigned int j = 0;

    if (((len_s1 ^ len_s2) > 1) || !strcmp(s1, s2)) {
        return 0;
    }

    do {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        } else {
            if (s1[i+1] == s2[j+1]) {
                if (flag) {
                    return 0;
                }
                flag = 1;
                i++;
                j++;
            } else if (s1[i] == s2[j + 1]) {
                if (flag) {
                    return 0;
                }
                flag = 1;
                j++;
            }  else if (s1[i + 1] == s2[j]) {
                if (flag) {
                    return 0;
                }
                flag = 1;
                i++;
            }
        }
    } while ((i < len_s1) && (j < len_s2));

    return 1;


}

int
main(int  argc,
     char **argv)
{
    char s1[100], s2[100];
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
    if (find_edit_distance(s1, s2, strlen(s1), strlen(s2))) {
        printf("Edit distance is 1\n");
    } else {
        printf("Edit distance is not 1\n");
    }
    return 0;
}
