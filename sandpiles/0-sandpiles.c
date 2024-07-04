#include <stdio.h>
#include <stdbool.h>

void print_grid(int grid[3][3]);
bool is_stable(int grid[3][3]);
void stabilize(int grid[3][3]);

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    int i, j;
    /* Step 1: Add the two sandpiles */
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }

    /* Step 2 & 3: Check stability, print and stabilize if needed */
    while (!is_stable(grid1)) {
        print_grid(grid1);
        stabilize(grid1);
    }
}

bool is_stable(int grid[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                return false;
            }
        }
    }
    return true;
}


void print_grid(int grid[3][3]) {
    int i, j;
    printf("=\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (j) printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

void stabilize(int grid[3][3]) {
    int i, j; 
    int temp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                temp[i][j] -= 4;
                /* Top */
                if (i > 0) temp[i-1][j] += 1;
                /* Bottom */
                if (i < 2) temp[i+1][j] += 1;
                /* Left */
                if (j > 0) temp[i][j-1] += 1;
                /* Right */
                if (j < 2) temp[i][j+1] += 1;
            }
        }
    }
    /* Apply the toppling to the original grid */
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] += temp[i][j];
        }
    }
}