/*
 * Radix tree implementation of IPV4 nexthop table
 * Copyright (C) 2016 Jayaraj Kubakaddi
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node_s
{
    struct node_s *zero;
    struct node_s *one;
    uint8_t       next_hop;
    bool          valid;
} node_t;

static void
insert_node(node_t   *root,
            uint32_t ipv4_addr,
            uint8_t  prefix_len,
            uint8_t  index,
            uint32_t next_hop)
{
    node_t *temp = root;

    if (index > prefix_len) {
        temp->next_hop = next_hop;
        temp->valid = 1;
        return;
    }

    if (ipv4_addr & (1 << (32 - index))) {
        if (!temp->one) {
            temp->one = (node_t*) calloc(1, sizeof(node_t));
        }
        temp = temp->one;
    } else {
        if (!temp->zero) {
            temp->zero = (node_t*) calloc(1, sizeof(node_t));
        }
        temp = temp->zero;
    }

    insert_node(temp, ipv4_addr, prefix_len, (index + 1), next_hop);
}

static void
insert(node_t   *root,
       uint32_t ipv4_addr,
       uint8_t  prefix_len,
       uint32_t next_hop)
{
    insert_node(root, ipv4_addr, prefix_len, 1, next_hop);
}


static bool
search_nexthop(node_t   *root,
               uint32_t ipv4_addr,
               uint32_t *next_hop)
{
    node_t  *temp = root;
    uint8_t i = 1;

    while (temp && (i <= 32)) {
        if (ipv4_addr & (1 << (32 - i))) {
            if (temp->one) {
                temp = temp->one;
            } else {
                return 1;
            }
        } else {
            if (temp->zero) {
                temp = temp->zero;
            } else {
                return 1;
            }
        }
        if (temp->valid) {
            *next_hop = temp->next_hop;
        }
        i++;
    }

    return 0;
}

static uint32_t
ipv4_string_to_int(char *ip_str)
{
    char     *p;
    char     *end;
    uint32_t ip = 0;
    uint32_t i;
    uint32_t j = 3;

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

    return ip;
}

int
main(int  argc,
     char **argv)
{
    node_t   *root = NULL;
    char     ipv4_addr[16];
    uint32_t next_hop;
    uint32_t choice;
    uint32_t prefix_len;

    root = (node_t*) calloc(1, sizeof(node_t));

    while(1) {
        printf("Insert prefix and nexthop   : 1\n");
        printf("Search nexthop for given IP : 2\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
              printf("Enter IP address: ");
              scanf("%s", ipv4_addr);
              printf("Enter prefix length for %s: ", ipv4_addr);
              scanf("%d", &prefix_len);
              printf("Enter nexthop for %s: ", ipv4_addr);
              scanf("%u", &next_hop);
              insert(root, ipv4_string_to_int(ipv4_addr), (uint8_t)prefix_len, next_hop);
              printf("Inserted: %s\n", ipv4_addr);
              break;
            case 2:
              printf("Enter IP address: ");
              scanf("%s", ipv4_addr);
              if (search_nexthop(root, ipv4_string_to_int(ipv4_addr), &next_hop)) {
                  printf("Nexthop for IP address %s is %u\n", ipv4_addr, next_hop);
              } else {
                  printf("Could not find nexthop\n");
              }
              break;
            default:
              printf("Invalid choice!!!\n");
        }
    }

    return 0;
}

