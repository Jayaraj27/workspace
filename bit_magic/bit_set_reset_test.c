/*
 * This program has 3 macros 
 * 1. BIT_SET - sets a particular bit in a variable
 * 2. BIT_RESET - resets a particular bit in a variable
 * 3. BIT_TEST - checks if a particular bit is set or not
 */
#include <stdio.h>

#define BIT_SET(x, y) ( x |= (1 << y))
#define BIT_RESET(x, y) (x &= ~(1 << y))
#define BIT_TEST(x, y) (x & (1 << y))


int
main(int  argc,
     char **argv)
{
    int a = 0xBA;

    BIT_SET(a, 2);
    printf("a = %#X\n", a);
    BIT_RESET(a, 3);
    printf("a = %#X\n", a);

    if (BIT_TEST(a, 0)) {
        printf("Bit is set\n");
    } else {
        printf("Bit is not set\n");
    }

    return 0;
}
