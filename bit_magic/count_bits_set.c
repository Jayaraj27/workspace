/*
 * This program counts the number of bits set in an unsigned 4 byte integer
 */
#include <stdio.h>
#include <stdint.h>

static uint8_t
count_bits_set(uint32_t x)
{
    uint8_t count = 0;

    while (x) {
        x &= (x - 1);
        count++;
    }
    return count;
}

int
main(int  argc,
     char **argv)
{
    uint32_t x;

    printf("Enter number in hex: ");
    scanf("%x", &x);
    printf("Number of bits set in %#X = %d\n", x, count_bits_set(x));
    return 0;
}
