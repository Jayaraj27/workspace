/*
 * This program finds out the absolute of a given integer
 */
#include <stdio.h>

int
main(int  argc,
     char **argv)
{
    int          num;
    unsigned int result;

    printf("Enter number: ");
    scanf("%d", &num);
    int mask = num >> ((sizeof(int) * 8) - 1);
    result = (num + mask) ^ mask;

    printf("Abs is %u\n", result);
    return 0;
}
