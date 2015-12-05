/*
 * This program compares 2 IP addresses.
 * Input of IP addresses is in string format
 */
#include <stdio.h>
#include <string.h>

int
convert_string_to_num(char *s)
{
    char *end = s + strlen(s) - 1;
    int num = 0;
    int i = 1;

    while (s <= end) {
        num = num + (*end - '0') * i;
        i *= 10;
        end--;
    }
    return num;
}

int
compare_ip(char *s1,
           char *s2)
{
    char *p1 = s1;
    char *p2 = s2;
    int  num1;
    int  num2;
    int i = 0;

    do {
        p1 = strtok(p1, ".");
        num1 = convert_string_to_num(p1);
        p2 = strtok(p2, ".");
        num2 = convert_string_to_num(p2);
        if (num1 < num2) {
            return -1;
        } else if (num1 > num2) {
            return 1;
        }
        i++;
        if (i == 4) {
            break;
        }
        p1 += strlen(p1) + 1;
        p2 += strlen(p2) + 1;
    } while(1);

    return 0;
}

int
main(int  argc,
     char **argv)
{
    char s1[16];
    char s2[16];
    int  ret_value;

    printf("Enter IP addr 1: ");
    scanf("%s", s1);
    printf("Enter IP addr 2: ");
    scanf("%s", s2);

    ret_value = compare_ip(s1, s2);

    if (ret_value == -1) {
        printf("IP2 is > IP1\n");
    } else if (ret_value == 1) {
        printf("IP1 is > IP2\n");
    } else {
        printf("Both IP's are identical\n");
    }
    return 0;
}
