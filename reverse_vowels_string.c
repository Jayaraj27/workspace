/*
 * This program reverses the vowels in a string
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static bool
vowel_test(char ch)
{
    char         *vowel_list = "aeiou";
    unsigned int i;
    unsigned int len = strlen(vowel_list);

    for (i = 0; i < len; i++) {
        if (ch == vowel_list[i]) {
            return 1;
        }
    }
    return 0;
}

static void
reverse_vowels(char *string)
{
    unsigned int i, front = 0, back;
    unsigned int len = strlen(string);

    back = len - 1;

    while (1) {
        while (front < len/2) {
            if (vowel_test(string[front])) {
                break;
            }
            front++;
        }
        if (front >= (len/2)) {
            return;
        }
        while (back > len/2) {
            if (vowel_test(string[back - i])) {
                break;
            }
            back--;
        }
        if (back <= (len/2)) {
            return;
        }
        string[front] ^= string[back - i];
        string[back - i] ^= string[front];
        string[front] ^= string[back - i];
        front++;
        back--;
    }
}

int
main(int  argc,
     char **argv)
{
    char string[100];

    printf("Enter string: ");
    gets(string);
    printf("Reversed vowels = %s\n", string);
    reverse_vowels(string);
    printf("Reversed vowels = %s\n", string);

    return 0;
}

