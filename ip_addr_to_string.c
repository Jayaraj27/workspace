/*
 * This program converts an IP address to string
 */
#include <stdio.h>
#include <stdint.h>

int
main(int  argc,
     char **argv)
{
    uint32_t ip_addr = 0x0A0A0A03;
    char     ip_string[16];

    printf("Enter IP address as a unsigned integer in hex(ex: 0xA0A0A0A): ");
    scanf("%x",&ip_addr);
    snprintf(ip_string, 16, "%d.%d.%d.%d", *((char*)&ip_addr + 3), *((char*)&ip_addr + 2), *((char*)&ip_addr + 1), *(char*)&ip_addr);

    printf("IP address is %s\n", ip_string);

    return 0;
}
