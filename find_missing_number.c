/*
 * This program finds the missing number in an array of 
 * integers sorted out in ascending order and each number
 * differs from the previous by 1.
 */
#include <stdio.h>

static int
find_missing_num(int a[],
                 int len)
{
    int x1 = 0;
    int x2 = 0;
    int i;

    for (i = 1; i <= (len + 1); i++) {
        x2 ^= i;
        if (i != (len + 1)) {
            x1 ^= a[i - 1];
        }
    }
    return (x1^x2);
}

int
main(int  argc,
     char **argv)
{
    int a[] = {1, 2, 3, 4, 5, 6, 8, 9};

    printf("Missing number is %d\n",
           find_missing_num(a, sizeof(a)/sizeof(int)));

    return 0;
}
