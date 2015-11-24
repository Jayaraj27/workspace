/*
 * This program reverses the vowels in a string
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SWAP(x, y) do \
{                     \
    x ^= y;           \
    y ^= x;           \
    x ^= y;           \
} while (0)

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
    if (string) {
        char *end = string + strlen(string) - 1;

        while (string < end) {
            while (string < end) {
                if (vowel_test(*string)) {
                    break;
                }
                string++;
            }
            while (string < end) {
                if (vowel_test(*end)) {
                    break;
                }
                end--;
            }

            if (string >= end) {
                return;
            }

            SWAP(*string, *end);

            string++;
            end--;
        }
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

