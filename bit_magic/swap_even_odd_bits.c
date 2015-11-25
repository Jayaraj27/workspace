/*
 * This program swaps the even and odd bits of a unsigned integer
 */

#include <stdio.h>

#define SWAP(x) (x = (((x & 0x5555) << 1) | ((x & 0xAAAA) >> 1)))

int
main(int  argc,
     char **argv)
{
    unsigned int x;
    printf("Enter number: ");
    scanf("%X",&x);

    printf("%#X\n", SWAP(x));
    return 0;
}
