/*
 * This program implements a simple stack date structure
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node_s
{
    struct node_s *next;
    int           num;
} node_t;

static void
push(node_t **top,
     int    num)
{
    node_t *temp = *top;

    temp = (node_t*) malloc(sizeof(node_t));
    temp->num = num;
    temp->next = *top;
    *top = temp;
}

static void
pop(node_t **top)
{
    node_t *temp = *top;

    *top = (*top)->next;
    printf("%d popped\n", temp->num);
    free(temp);
}

int
main(int  argc,
     char **argv)
{
    node_t *top = NULL;
    int    option;
    int    num;

    while (1) {
        printf("\n");
        printf("Push         : 1\n");
        printf("Pop          : 2\n");
        printf("Enter option : ");
        scanf("%d", &option);
        switch (option) {
            case 1:
              printf("Enter value to be pushed: ");
              scanf("%d", &num);
              push(&top, num);
              break;
            case 2:
              if (top) {
                  pop(&top);
              } else {
                  printf("Stack empty!!!\n");
              }
              break;
            default:
              printf("Invalid choice!!!\n");
              break;
        }
    }

    return 0;
}
