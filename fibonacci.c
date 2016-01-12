/*
 * This program finds the fibnocci of a given number.
 * fib(0) = 0
 * fib(1) = 1
 * fib(2) = 1
 * fib(3) = 2
 * fib(4) = 3
 * fib(5) = 5 and so on...
 *
 * This program makes use of dynamic programming wherein the results of 
 * previous computations are stored and made use of thereby decreasing
 * the number of iterations.
 */
#include <stdio.h>

#define MAX 100

unsigned int fib_data[MAX];

static unsigned int
fib(unsigned int num)
{

    if (num == 0) {
        return 0;
    }

    if (num == 1) {
        return 1;
    }

    if (fib_data[num]) {
        return fib_data[num];
    }

    fib_data[num] = fib(num - 1) + fib(num - 2);

    return fib_data[num];
}

int
main(int  argc,
     char **argv)
{
    unsigned int num;
    printf("Enter number: ");
    scanf("%u", &num);

    printf("fib of %u is %u\n", num, fib(num));

    return 0;
}
