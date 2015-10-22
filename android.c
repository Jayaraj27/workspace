#include <stdio.h>
#include <stdbool.h>

#define FALSE 0
#define TRUE  1

char a[3][3] = {{'A', 'B', 'C'},
                {'D', 'E', 'F'},
                {'G', 'H', 'I'}};

char A_path[3] = {'B', 'E', 'D'};
char C_path[3] = {'B', 'E', 'F'};
char G_path[3] = {'D', 'E', 'H'};
char I_path[3] = {'H', 'E', 'F'};

char B_path[5] = {'A', 'D', 'E', 'F', 'C'};
char D_path[5] = {'A', 'B', 'E', 'H', 'G'};
char H_path[5] = {'G', 'D', 'E', 'F', 'I'};
char F_path[5] = {'C', 'B', 'E', 'H', 'I'};

char E_path[8] = {'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I'};
char path[9] = {0};

bool
validate_char_to_push(char char_to_push,
                      int  cumulative_length)
{
    int i;

    for (i = 0; i < cumulative_length; i++) {
        if (path[i] == char_to_push) {
            return FALSE;
        }
    }

    return TRUE;
}

int
find_next(char pushed_char,
          int  cumulative_length,
          int  length)
{
    int count = 0;
    int i;

    if (cumulative_length == length) {
        for (i = 0; i < cumulative_length + 1; i++) {
            printf("%c", path[i]);
        }
        printf("\n");
        return 1;
    }

    switch (pushed_char) {
        case 'A':
          for (i = 0; i < sizeof(A_path); i++) {
              if (!validate_char_to_push(A_path[i], cumulative_length)) {
                  continue;
              }
              path[cumulative_length + 1] = A_path[i];
              count += find_next(A_path[i], cumulative_length + 1, length);
          }
          break;
        case 'B':
          for (i = 0; i < sizeof(B_path); i++) {
              if (!validate_char_to_push(B_path[i], cumulative_length)) {
                  continue;
              }
              path[cumulative_length + 1] = B_path[i];
              count += find_next(B_path[i], cumulative_length + 1, length);
          }
          break;
        case 'C':
          for (i = 0; i < sizeof(C_path); i++) {
              if (!validate_char_to_push(C_path[i], cumulative_length)) {
                  continue;
              }
              path[cumulative_length + 1] = C_path[i];
              count += find_next(C_path[i], cumulative_length + 1, length);
          }
          break;
        case 'D':
          for (i = 0; i < sizeof(D_path); i++) {
              if (!validate_char_to_push(D_path[i], cumulative_length)) {
                  continue;
              }
              path[cumulative_length + 1] = D_path[i];
              count += find_next(D_path[i], cumulative_length + 1, length);
          }
          break;
        case 'E':
          for (i = 0; i < sizeof(E_path); i++) {
              if (!validate_char_to_push(E_path[i], cumulative_length)) {
                  continue;
              }
              path[cumulative_length + 1] = E_path[i];
              count += find_next(E_path[i], cumulative_length + 1, length);
          }
          break;
        case 'F':
          for (i = 0; i < sizeof(F_path); i++) {
              if (!validate_char_to_push(F_path[i], cumulative_length)) {
                  continue;
              }
              path[cumulative_length + 1] = F_path[i];
              count += find_next(F_path[i], cumulative_length + 1, length);
          }
          break;
        case 'G':
          for (i = 0; i < sizeof(G_path); i++) {
              if (!validate_char_to_push(G_path[i], cumulative_length)) {
                  continue;
              }
              path[cumulative_length + 1] = G_path[i];
              count += find_next(G_path[i], cumulative_length + 1, length);
          }
          break;
        case 'H':
          for (i = 0; i < sizeof(H_path); i++) {
              if (!validate_char_to_push(H_path[i], cumulative_length)) {
                  continue;
              }
              path[cumulative_length + 1] = H_path[i];
              count += find_next(H_path[i], cumulative_length + 1, length);
          }
          break;
        case 'I':
          for (i = 0; i < sizeof(I_path); i++) {
              if (!validate_char_to_push(I_path[i], cumulative_length)) {
                  continue;
              }
              path[cumulative_length + 1] = I_path[i];
              count += find_next(I_path[i], cumulative_length + 1, length);
          }
          break;
    }
    return count;
}

int
getTotalCombinationsOfLength(int length)
{
    int count = 0;
    int cumulative_length = 0;
    int i, j;

    if (length <= 0) {
        printf("Invalid length\n");
        return count;
    }

    printf("\n\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            //printf("%c   ", a[i][j]);
            path[0] = a[i][j];
            count += find_next(a[i][j], cumulative_length, length);
        }
        printf("\n\n");
    }
    return count;
}

int
main (int  argc,
      char **argv)
{
    int length;

    printf("Enter length:");
    scanf("%d", &length);
    printf("Total combinations are: %d\n",
           getTotalCombinationsOfLength(length));
    return 0;
}
