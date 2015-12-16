/*
 * This program finds the common characters and difference characters between
 * 2 given strings and populate 2 strings with the common elements and
 * difference elements
 * For example: Given 2 strings
 * s1 = Hello
 * s2 = How
 * Common elements string s3 = Ho
 * Difference elements string s4 = ellw
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct count_s {
    uint8_t str1_count[256];
    uint8_t str2_count[256];
} count_t;

static void
diff_common(char *s1,
            char *s2,
            char *s3,
            char *s4)
{
    char    *st_s1 = s1;
    char    *st_s2 = s2;
    count_t count;
    uint8_t i;
    uint8_t j = 0;
    uint8_t k = 0;

    memset(&count, 0, sizeof(count_t));

    while (*st_s1 != '\0' || *st_s2 != '\0') {
        if (*st_s1 != '\0') {
            count.str1_count[*st_s1]++;
            st_s1++;
        }
        if (*st_s2 != '\0') {
            count.str2_count[*st_s2]++;
            st_s2++;
        }
    }

    while (1) {
        while (count.str1_count[i] || count.str2_count[i]) {
            if (count.str1_count[i] && count.str2_count[i]) {
                *(s3 + j) = i;
                j++;
                count.str1_count[i]--;
                count.str2_count[i]--;
            }
            while (count.str1_count[i]) {
                *(s4 + k) = i;
                k++;
                count.str1_count[i]--;
            }
            while (count.str2_count[i]) {
                *(s4 + k) = i;
                k++;
                count.str2_count[i]--;
            }
        }
        if (i == 255) {
            break;
        }
        i++;
    }

    *(s3 + j) = '\0';
    *(s4 + k) = '\0';
}

int
main(int  argc,
     char **argv)
{
    char s1[100];
    char s2[100];
    char s3[100];
    char s4[100];

    printf("Enter string 1: ");
    fgets(s1, 100, stdin);
    printf("Enter string 2: ");
    fgets(s2, 100, stdin);

    s1[strlen(s1) - 1] = '\0';
    s2[strlen(s2) - 1] = '\0';

    diff_common(s1, s2, s3, s4);

    printf("Common is %s\n", s3);
    printf("Difference is %s\n", s4);

    return 0;
}
