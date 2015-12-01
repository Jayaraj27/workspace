/*
 * This program finds if a given integer is divisible by 3 or not
 * This makes use of a small routine which finds the absolute of a number which
 * is implemented by the below logic, courtesy stack overflow
 *
 * Let's assume a twos-complement number (as it's the usual case and you don't
 * say otherwise) and let's assume 32-bit:

 * First, we perform an arithmetic right-shift by 31 bits. This shifts in all 1s
 * for a negative number or all 0s for a positive one (but note that the actual
 * >>-operator's behaviour in C or C++ is implementation defined for negative 
 * numbers, but will usually also perform an arithmetic shift, but let's just
 * assume pseudocode or actual hardware instructions, since it sounds like homework anyway):
 * 
 * mask = x >> 31;
 * So what we get is 111...111 (-1) for negative numbers and 000...000 (0) for positives
 * 
 * Now we XOR this with x, getting the behaviour of a NOT for mask=111...111 (negative)
 * and a no-op for mask=000...000 (positive):
 * 
 * x = x XOR mask;
 * And finally subtract our mask, which means +1 for negatives and +0/no-op for positives:
 * 
 * x = x - mask;
 * So for positives we perform an XOR with 0 and a subtraction of 0 and thus get the same
 * number. And for negatives, we got (NOT x) + 1, which is exactly -x when using
 * twos-complement representation.
 */

#include <stdio.h>
#include <stdbool.h>

static int
abs(int x)
{
    int mask;

    mask = x >> ((sizeof(int) * 8) - 1);
    x ^= mask;
    x -= mask;

    return x;
}

static bool
is_divisible_by_3(int x)
{
    int even_bits = 0;
    int odd_bits = 0;

    if (!x) {
        return 1;
    } else if (x == 1) {
        return 0;
    }

    return is_divisible_by_3(abs(odd_bits - even_bits));
}



int
main(int  argc,
     char **argv)
{
    int x;

    printf("Enter number: ");
    scanf("%d", &x);

    if (is_divisible_by_3(abs(x))) {
        printf("%d is divisible by 3\n", x);
    } else {
        printf("%d is not divisible by 3\n", x);
    }

    return 0;
}
