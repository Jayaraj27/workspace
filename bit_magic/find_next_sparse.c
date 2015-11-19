/*
 * This program finds the next sparse number.
 * A number is Sparse if there are no two adjacent 1s in its binary representation.
 */
#include <stdio.h>

static unsigned int
find_next_sparse(unsigned int num)
{
    while (num & (num >> 1)) {
        num++;
    }

    return num;
}

int
main(int  argc,
     char **argv)
{
    unsigned int num;
    printf("Enter number: ");
    scanf("%u", &num);
    printf("Next sparse number is %#x\n", find_next_sparse(num));
    return 0;
}
