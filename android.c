#include <stdio.h>
#include <stdbool.h>

#define FALSE 0
#define TRUE  1

char screen_pattern[3][3] = {{'A', 'B', 'C'},
                             {'D', 'E', 'F'},
                             {'G', 'H', 'I'}};

char A_neighbor[3] = {'B', 'E', 'D'};
char C_neighbor[3] = {'B', 'E', 'F'};
char G_neighbor[3] = {'D', 'E', 'H'};
char I_neighbor[3] = {'H', 'E', 'F'};

char B_neighbor[5] = {'A', 'D', 'E', 'F', 'C'};
char D_neighbor[5] = {'A', 'B', 'E', 'H', 'G'};
char H_neighbor[5] = {'G', 'D', 'E', 'F', 'I'};
char F_neighbor[5] = {'C', 'B', 'E', 'H', 'I'};

char E_neighbor[8] = {'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I'};

char traversed_path[9];

static bool
validate_char_to_push(const char char_to_push,
                      const int  cumulative_length)
{
    int i;

    for (i = 0; i < cumulative_length; i++) {
        if (traversed_path[i] == char_to_push) {
            return FALSE;
        }
    }

    return TRUE;
}

static int
find_next(const char pushed_char,
          const int  cumulative_length,
          const int  length)
{
    int count = 0;
    int i;

    if (cumulative_length == length) {
        for (i = 0; i < cumulative_length + 1; i++) {
            //printf("%c", traversed_path[i]);
        }
        //printf("\n");
        return 1;
    }

    switch (pushed_char) {
        case 'A':
          for (i = 0; i < sizeof(A_neighbor); i++) {
              if (!validate_char_to_push(A_neighbor[i], cumulative_length)) {
                  continue;
              }
              traversed_path[cumulative_length + 1] = A_neighbor[i];
              count += find_next(A_neighbor[i], cumulative_length + 1, length);
          }
          break;
        case 'B':
          for (i = 0; i < sizeof(B_neighbor); i++) {
              if (!validate_char_to_push(B_neighbor[i], cumulative_length)) {
                  continue;
              }
              traversed_path[cumulative_length + 1] = B_neighbor[i];
              count += find_next(B_neighbor[i], cumulative_length + 1, length);
          }
          break;
        case 'C':
          for (i = 0; i < sizeof(C_neighbor); i++) {
              if (!validate_char_to_push(C_neighbor[i], cumulative_length)) {
                  continue;
              }
              traversed_path[cumulative_length + 1] = C_neighbor[i];
              count += find_next(C_neighbor[i], cumulative_length + 1, length);
          }
          break;
        case 'D':
          for (i = 0; i < sizeof(D_neighbor); i++) {
              if (!validate_char_to_push(D_neighbor[i], cumulative_length)) {
                  continue;
              }
              traversed_path[cumulative_length + 1] = D_neighbor[i];
              count += find_next(D_neighbor[i], cumulative_length + 1, length);
          }
          break;
        case 'E':
          for (i = 0; i < sizeof(E_neighbor); i++) {
              if (!validate_char_to_push(E_neighbor[i], cumulative_length)) {
                  continue;
              }
              traversed_path[cumulative_length + 1] = E_neighbor[i];
              count += find_next(E_neighbor[i], cumulative_length + 1, length);
          }
          break;
        case 'F':
          for (i = 0; i < sizeof(F_neighbor); i++) {
              if (!validate_char_to_push(F_neighbor[i], cumulative_length)) {
                  continue;
              }
              traversed_path[cumulative_length + 1] = F_neighbor[i];
              count += find_next(F_neighbor[i], cumulative_length + 1, length);
          }
          break;
        case 'G':
          for (i = 0; i < sizeof(G_neighbor); i++) {
              if (!validate_char_to_push(G_neighbor[i], cumulative_length)) {
                  continue;
              }
              traversed_path[cumulative_length + 1] = G_neighbor[i];
              count += find_next(G_neighbor[i], cumulative_length + 1, length);
          }
          break;
        case 'H':
          for (i = 0; i < sizeof(H_neighbor); i++) {
              if (!validate_char_to_push(H_neighbor[i], cumulative_length)) {
                  continue;
              }
              traversed_path[cumulative_length + 1] = H_neighbor[i];
              count += find_next(H_neighbor[i], cumulative_length + 1, length);
          }
          break;
        case 'I':
          for (i = 0; i < sizeof(I_neighbor); i++) {
              if (!validate_char_to_push(I_neighbor[i], cumulative_length)) {
                  continue;
              }
              traversed_path[cumulative_length + 1] = I_neighbor[i];
              count += find_next(I_neighbor[i], cumulative_length + 1, length);
          }
          break;
    }
    return count;
}

static int
getTotalCombinationsOfLength(const int length)
{
    int count = 0;
    int cumulative_length = 0;
    int i, j;

    if (length <= 0) {
        printf("Invalid length\n");
        return count;
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            traversed_path[0] = screen_pattern[i][j];
            count += find_next(screen_pattern[i][j], cumulative_length, length);
        }
        //printf("\n");
    }
    return count;
}

int
main(int  argc,
     char **argv)
{
    int length;

    printf("Enter length: ");
    scanf("%d", &length);
    printf("Total combinations are: %d\n",
           getTotalCombinationsOfLength(length));
    return 0;
}
