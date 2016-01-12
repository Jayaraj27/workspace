/*
 * This program finds the weighted sum of a given string
 * For example
 * 1. Given the list {{1,1},2,{1,1}} weighted sum is 10, i.e. there are 4 1's
 *    at depth 2 and 1 2 at depth 1. So we have 2*4 + 1*2 = 10
 * 2. Given the list {1,{4,{6}}} the function should return 27
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

static unsigned int
weighted_depth(char *str)
{
    uint8_t      depth = 0;
    unsigned int sum = 0;

    while (*str != '\0') {
        if (*str == '{') {
            depth++;
        } else if (*str == '}') {
            assert(depth);
            depth--;
        } else if (*str == ',') {
        } else {
            assert(depth);
            sum += depth * (*str - '0');
        }
        str++;
    }
    return sum;
}

int main(int  argc,
         char **argv)
{
    char str[100];
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';
    printf("Weighted depth is %u\n", weighted_depth(str));
    return 0;
}
