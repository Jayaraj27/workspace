/*
 * This program finds a missing number in an array of sorted numbers
 * Time complexity log(n)
 */
#include <stdio.h>

static int
find_missing_number(int arr[],
                    int size)
{
    int good = 0;
    int bad = size - 1;
    int current;

    if (arr[0] != 1) {
        return 1;
    }

    if (arr[bad] != (bad + 2)) {
        return (bad + 2);
    }

    do {
        iter++;
        current = good + (bad - good) / 2;
        if (arr[current] == (current + 1)) {
            good = current;
        } else {
            bad = current;
        }
        if ((arr[good] == (good + 1)) && (arr[good + 1] == (good + 3))) {
            break;
        }
    } while (1);

    return (good + 2);

}

int
main(int  argc,
     char **argv)
{
    int arr[31] = {1, 2,  3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};

    printf("Missing # is %d\n", find_missing_number(arr, (sizeof(arr)/sizeof(int))));
     
    return 0;
}
