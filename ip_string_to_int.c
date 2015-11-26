/*
 * This program converts a IP address in string format into
 * an unsigned integer
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int
main(int  argc,
     char **argv)
{
    char     ip_str[16];
    char     *p;
    char     *end;
    uint32_t ip = 0;
    uint32_t i;
    uint32_t j = 3;

    printf("Enter IP address in string format: ");
    scanf("%s", ip_str);

    p = strtok(ip_str, ".");

    while (p) {
        end = p + strlen(p) - 1;
        i = 1;
        while (p <= end) {
            *((char*)&ip + j) += (*end - '0') * i;
            i *= 10;
            end--;
        }
        j--;
        p = strtok(NULL, ".");
    }

    printf("%#X\n", ip);

    return 0;
}
