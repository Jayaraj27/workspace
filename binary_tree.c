/*
 * This program implements a simple BST and provides some common operations
 * that are done on a BST.
 */

#include "local_header.h"

static bool is_root = TRUE;
static int  prev;

static bool
insert(node_t **root,
       node_t *parent,
       int    num)
{
    node_t *temp = *root;

    if (!temp) {
        temp = (node_t*) malloc(sizeof(node_t));
        if (!temp) {
            printf("ERROR: %s\n", strerror(errno));
            return FAILURE;
        }
        temp->left = NULL;
        temp->right = NULL;
        temp->num  = num;
        temp->parent = parent;
        *root = temp;
        return SUCCESS;
    }

    if (num > temp->num) {
        return insert(&(temp->right), temp, num);
    } else {
        return insert(&(temp->left), temp, num);
    }
}

static void
display_in_order(node_t *root)
{
    if (root) {
        display_in_order(root->left);
        printf("%d ", root->num);
        display_in_order(root->right);
    }
}

static void
display_pre_order(node_t *root)
{
    if (root) {
        printf("%d ", root->num);
        display_pre_order(root->left);
        display_pre_order(root->right);
    }
}

static void
display_post_order(node_t *root)
{
    if (root) {
        display_post_order(root->left);
        display_post_order(root->right);
        printf("%d ", root->num);
    }
}

static void
display_level_order(node_t       *root,
                    unsigned int level)
{
    if (root) {
        if (level == 1) {
            printf("%d ", root->num);
        } else {
            display_level_order(root->left, level - 1);
            display_level_order(root->right, level - 1);
        }
    }
}



static unsigned int
find_height(node_t *root)
{
    unsigned int left_height = 1;
    unsigned int right_height = 1;

    if (root) {
        left_height += find_height(root->left);
        right_height += find_height(root->right);
    } else {
        return 0;
    }

    if (left_height > right_height) {
        return left_height;
    } else {
        return right_height;
    }

}

static node_t*
find_element(node_t *root,
             int    num)
{
    node_t *node_p;

    if (!root) {
        return NULL;
    }

    if (root->num == num) {
        return root;
    } else {
        if (root->left) {
            if ((node_p = find_element(root->left, num))) {
                return node_p;
            }
        }
        if (root->right) {
            if ((node_p = find_element(root->right, num))) {
                return node_p;
            }
        }
        return NULL;
    }
}

static node_t*
find_left_most(node_t *root)
{
    while (root->left) {
        root = root->left;
    }
    return root;
}

static node_t*
find_right_most(node_t *root)
{
    while (root->right) {
        root = root->right;
    }
    return root;
}

static node_t*
find_inorder_successor(node_t *node_p)
{
    node_t *p = NULL;

    if (node_p->right) {
        return find_left_most(node_p->right);
    } else {
        p = node_p->parent;
        while (p && (p->left != node_p)) {
            node_p = p;
            p = p->parent;
        }
        return p;
    }
}

static node_t*
find_inorder_predeccessor(node_t *node_p)
{
    node_t *p = NULL;

    if (node_p->left) {
        return find_right_most(node_p->left);
    } else {
        p = node_p->parent;
        while (p && (p->right != node_p)) {
            node_p = p;
            p = p->parent;
        }
        return p;
    }
}

static void
update_parent(node_t *node_p)
{
    if (node_p->parent) {
        if (node_p == node_p->parent->left) {
            node_p->parent->left = NULL;
        } else {
            node_p->parent->right = NULL;
        }
    } else {
        //This is the root node
    }
}

static bool
delete(node_t **root,
       int    num)
{
    node_t *temp = *root;
    node_t *node_p = NULL;

    if (temp) {
        if ((node_p = find_element(temp, num))) {
            if (!node_p->left && !node_p->right) {
                update_parent(node_p);
                if (node_p == *root) {
                    *root = NULL;
                }
                free(node_p);
            } else {
                if (node_p->left && !node_p->right) {
                    temp = node_p->left;
                    node_p->left = temp->left;
                    node_p->right = temp->right;
                    node_p->num = temp->num;
                    if (temp->left) {
                        temp->left->parent = node_p;
                    }
                    if (temp->right) {
                        temp->right->parent = node_p;
                    }
                    free(temp);
                } else if (!node_p->left && node_p->right) {
                    temp = node_p->right;
                    node_p->left = temp->left;
                    node_p->right = temp->right;
                    node_p->num = temp->num;
                    if (temp->left) {
                        temp->left->parent = node_p;
                    }
                    if (temp->right) {
                        temp->right->parent = node_p;
                    }
                    free(temp);
                } else {
                    temp = find_inorder_successor(node_p);
                    node_p->num = temp->num;
                    update_parent(temp);
                    free(temp);
                }
            }
            return SUCCESS;
        } else {
            return FAILURE;
        }
    } else {
        return FAILURE;
    }
}

static bool
is_bst(node_t *root)
{
    if (root) {
        if (!is_bst(root->left)) {
            return FALSE;
        }

        if (root->num < prev && !is_root) {
            return FALSE;
        }

        is_root = FALSE;
        prev = root->num;

        if (!is_bst(root->right)) {
            return FALSE;
        }
    }

    return TRUE;
}

int
main(int  argc,
     char **argv)
{
    int          choice;
    int          num;
    int          arr[] = {128, 64, 32, 16, 8, 4, 2, 6, 12, 24, 20, 48, 40, 256, 192};
    node_t       *root = NULL;
    unsigned int height;
    unsigned int i;
    node_t       *node_p = NULL;

    while (1) {
        printf("\n");
        printf("Insert                   : 1\n");
        printf("Display inorder          : 2\n");
        printf("Display preorder         : 3\n");
        printf("Display postorder        : 4\n");
        printf("Display level order      : 5\n");
        printf("Find height              : 6\n");
        printf("Populate tree            : 7\n");
        printf("Search element           : 8\n");
        printf("Find inorder successor   : 9\n");
        printf("Find inorder predecessor : 10\n");
        printf("Find if is tree is BST   : 11\n");
        printf("Delete a element         : 99\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
              printf("Enter number : ");
              scanf("%d", &num);
              if (insert(&root, NULL, num)) {
                  printf("Element inserted successfully\n");
              } else {
                  printf("Element count not be inserted\n");
              }
              break;
            case 2:
              if (root) {
                  display_in_order(root);
              } else {
                  printf("List is empty!!!\n");
              }
              printf("\n");
              break;
            case 3:
              if (root) {
                  display_pre_order(root);
              } else {
                  printf("List is empty!!!\n");
              }
              printf("\n");
              break;
            case 4:
              if (root) {
                  display_post_order(root);
              } else {
                  printf("List is empty!!!\n");
              }
              printf("\n");
              break;
            case 5:
              if (root) {
                  height = find_height(root);
                  for (i = 1; i <= height; i++) {
                      display_level_order(root, i);
                      printf("\n");
                  }
              } else {
                  printf("List is empty!!!\n");
              }
              break;
            case 6:
              printf("Height is %u\n", find_height(root));
              break;
            case 7:
              for (i = 0; i < (sizeof(arr)/sizeof(int)); i++) {
                  insert(&root, NULL, arr[i]);
              }
              break;
            case 8:
              printf("Enter number : ");
              scanf("%d", &num);
              if ((node_p = find_element(root, num))) {
                  printf("Found element %d\n", node_p->num);
              } else {
                  printf("Could not find element %d\n", num);
              }
              break;
            case 9:
              printf("Enter number : ");
              scanf("%d", &num);
              if ((node_p = find_element(root, num))) {
                  node_p = find_inorder_successor(node_p);
                  if (node_p) {
                      printf("Inorder successor = %d\n", node_p->num);
                  } else {
                      printf("Last node, no inorder sucessor!!!\n");
                  }
              } else {
                  printf("Could not find element %d\n", num);
              }
              break;
            case 10:
              printf("Enter number : ");
              scanf("%d", &num);
              if ((node_p = find_element(root, num))) {
                  node_p = find_inorder_predeccessor(node_p);
                  if (node_p) {
                      printf("Inorder predecessor = %d\n", node_p->num);
                  } else {
                      printf("First node, no inorder predecessor!!!\n");
                  }
              } else {
                  printf("Could not find element %d\n", num);
              }
              break;

            case 11:
              if (is_bst(root)) {
                  printf("Tree is BST!!!\n");
              } else {
                  printf("Tree is not BST!!!\n");
              }
              is_root = TRUE;
              break;
            case 99:
              printf("Enter number to be deleted: ");
              scanf("%d", &num);
              if (delete(&root, num)) {
                  printf("Element %d deleted successfully\n", num);
              } else {
                  printf("Element not found or list empty!!!\n");
              }
              break;
            default:
              printf("Invalid choice\n");
        }
    }

    return 0;
}
