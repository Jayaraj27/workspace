#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define FALSE   0
#define TRUE    1
#define NO      0
#define YES     1
#define FAILURE 0
#define SUCCESS 1

typedef struct node_s
{
    int           num;
    struct node_s *parent;
    union {
        struct node_s *next;
        struct node_s *right;
    };
    union {
        struct node_s *prev;
        struct node_s *left;
    };
} node_t;


