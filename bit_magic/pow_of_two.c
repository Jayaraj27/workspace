#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int
main (int  argc,
      char **argv)
{
    uint32_t num;

    printf("Enter number: ");
    scanf("%u", &num);
    if (!(num & (num - 1))) {
        printf("%u is power of 2\n", num);
    } else {
        printf("%u is not power of 2\n", num);
    }

    return 0;
}
