#include <stdio.h>

int main() {
    int n = 4, m = 2; // 4 processes, 2 resources
    int alloc[4][2] = {{1, 0}, {2, 0}, {3, 0}, {2, 1}};
    int max[4][2]   = {{3, 2}, {4, 1}, {5, 2}, {3, 2}};
    int avail[2]    = {2, 2};
    
    int need[4][2], finish[4] = {0}, safe_seq[4];
    int count = 0;

    // Calculate Need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Find Safe Sequence
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int can_allocate = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        can_allocate = 0;
                        break;
                    }
                }
                if (can_allocate) {
                    for (int y = 0; y < m; y++) avail[y] += alloc[i][y];
                    safe_seq[count++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

    if (count == n) {
        printf("Safe sequence: ");
        for (int i = 0; i < n; i++) printf("P%d ", safe_seq[i]);
        printf("\n");
    } else {
        printf("System is in deadlock\n");
    }
    return 0;
}