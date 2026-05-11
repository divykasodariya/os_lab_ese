#include <stdio.h>

int main() {
    int n = 3, m = 2; // 3 groups, 2 resources (projectors, USBs)
    int alloc[3][2]   = {{0,1}, {1,0}, {1,1}};
    int request[3][2] = {{1,0}, {0,1}, {0,0}};
    int avail[2]      = {0,0};
    
    int finish[3] = {0}, count = 0;

    // Detection Algorithm
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            if (finish[i] == 0) {
                int can_run = 1;
                for (int j=0; j<m; j++) {
                    if (request[i][j] > avail[j]) can_run = 0;
                }
                if (can_run) {
                    for (int y=0; y<m; y++) avail[y] += alloc[i][y];
                    finish[i] = 1;
                    count++;
                }
            }
        }
    }

    if (count == n) printf("No deadlock detected\n");
    else {
        printf("Processes in deadlock: ");
        for (int i=0; i<n; i++) 
            if (finish[i] == 0) printf("P%d ", i);
    }
    return 0;
}