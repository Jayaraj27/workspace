/*
 * This program compares 2 version numbers
 * The version numbers are input as strings
 * The version numbers are denoted in dotted format
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

static bool
is_digit(char ch)
{
    return (((ch - '0') >= 0) && (ch - '0') <= 9);
}


static int8_t
compare_versions(char *v1,
                 char *v2)
{
    uint32_t ver1 = 0;
    uint32_t ver2 = 0;
    uint32_t i = 1;

    while (*v1 != '\0' || *v2 != '\0') {
        while(*v1 != '\0' && is_digit(*v1)) {
            ver1 = (ver1 * i) + (*v1 - '0');
            v1++;
            i *= 10;
        }
        i = 1;
        while(*v2 != '\0' && is_digit(*v2)) {
            ver2 = (ver2 * i) + (*v2 - '0');
            v2++;
            i *= 10;
        }
        i = 1;

        if (ver1 < ver2) {
            return -1;
        } else if (ver1 > ver2) {
            return 1;
        }

        if ((*v1 != '\0') && !is_digit(*v1)) {
            v1++;
        }

        if ((*v2 != '\0') && !is_digit(*v2)) {
            v2++;
        }
        ver1 = 0;
        ver2 = 0;
    }
    return 0;
}

int
main(int  argc,
     char **argv)
{
    char    v1[100];
    char    v2[100];
    int8_t  ret_value;

    printf("Enter version 1: ");
    fgets(v1, 100, stdin);
    printf("Enter version 2: ");
    fgets(v2, 100, stdin);

    v1[strlen(v1)] = '\0';
    v2[strlen(v2)] = '\0';

    ret_value = compare_versions(v1, v2);

    if (ret_value == -1) {
        printf("v1 < v2\n");
    } else if (ret_value == 1) {
        printf("v1 > v2\n");
    } else {
        printf("v1 = v2\n");
    }
    
    return 0;
}
