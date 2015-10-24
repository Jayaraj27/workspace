#include "local_header.h"

static bool
insert(node_t **head,
       int    num)
{
    node_t *temp = *head;

    if (!temp) {
        temp = (node_t*) malloc(sizeof(node_t));
        if (!temp) {
            printf("ERROR: %s\n", strerror(errno));
            return FAILURE;
        }
        temp->prev = NULL;
        temp->next = NULL;
        temp->num  = num;
        *head = temp;
        return SUCCESS;
    }

    while (temp->next) {
        temp = temp->next;
    }

    temp->next = (node_t*) malloc(sizeof(node_t));
    if (!temp->next) {
        printf("ERROR: %s\n", strerror(errno));
        return FAILURE;
    }
    temp->next->prev = temp;
    temp = temp->next;
    temp->next = NULL;
    temp->num  = num;

    return SUCCESS;
}

static void
display(node_t *head)
{
    if (!head) {
        printf("List is empty!!!\n");
    }

    while (head) {
        printf("%d ", head->num);
        head = head->next;
    }
    printf("\n");
}

static bool
delete(node_t **head,
       int    num)
{
    bool   rc = FAILURE;
    node_t *temp = *head;
    node_t *free_node = NULL;

    if (!temp) {
        return FAILURE;
    }

    temp = temp->next;
    while (temp) {
        if (temp->num == num) {
            free_node = temp;
            temp->prev->next = temp->next;
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            temp = temp->next;
            free(free_node);
            rc = SUCCESS;
            continue;
        }
        temp = temp->next;
    }

    temp = *head;
    if (temp->num == num) {
            free_node = temp;
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            *head = temp->next;
            free(free_node);
            rc = SUCCESS;
    }

    return rc;
}

static void
reverse_list(node_t **head)
{
    node_t *iter = *head;
    node_t *temp;
    node_t *temp1;

    if (!iter->next && !iter->prev) {
        return;
    }

    temp = iter;
    iter = iter->next;

    while (temp && iter) {
        temp1 = temp->next;
        temp->next = temp->prev;
        temp->prev = temp1;
        temp = iter;
        iter = iter->next;
    }
    temp1 = temp->next;
    temp->next = temp->prev;
    temp->prev = temp1;
    *head = temp;
}

int
main(int  argc,
     char **argv)
{
    int    choice;
    int    num;
    node_t *head = NULL;

    while (1) {
        printf("Insert       : 1\n");
        printf("Display      : 2\n");
        printf("Delete       : 3\n");
        printf("Reverse list : 4\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
              printf("Enter number : ");
              scanf("%d", &num);
              if (insert(&head, num)) {
                  printf("Element inserted successfully\n");
              } else {
                  printf("Element count not be inserted\n");
              }
              break;
            case 2:
              display(head);
              break;
            case 3:
              printf("Enter number to be deleted: ");
              scanf("%d", &num);
              if (delete(&head, num)) {
                  printf("Element %d deleted successfully\n", num);
              } else {
                  printf("Element not found or list empty!!!\n");
              }
              break;
            case 4:
              reverse_list(&head);
              break;
            default:
              printf("Invalid choice\n");
        }
    }

    return 0;
}
