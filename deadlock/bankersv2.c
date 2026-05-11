#include <stdio.h>

int main() {
    int n = 4, m = 3; 
    // Initial State
    int alloc[4][3] = {{1,0,1}, {2,1,0}, {0,1,1}, {1,1,1}};
    int max[4][3]   = {{2,1,2}, {3,2,2}, {1,2,2}, {2,2,2}};
    int avail[3]    = {2,1,1};
    int need[4][3];
    
    // VM2 (Index 1) requests (1,0,2)
    int req_process = 1;
    int request[3] = {1, 0, 2};

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) need[i][j] = max[i][j] - alloc[i][j];

    // Step 1: Check Request <= Need and Request <= Avail
    for (int j=0; j<m; j++) {
        if (request[j] > need[req_process][j] || request[j] > avail[j]) {
            printf("Request denied (Exceeds need or availability)\n");
            return 0;
        }
    }

    // Step 2: Pretend to allocate
    for (int j=0; j<m; j++) {
        avail[j] -= request[j];
        alloc[req_process][j] += request[j];
        need[req_process][j] -= request[j];
    }

    // Step 3: Run Safety Check (Same loop as Set A)
    int finish[4] = {0}, count = 0;
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            if (!finish[i]) {
                int can_run = 1;
                for (int j=0; j<m; j++) 
                    if (need[i][j] > avail[j]) can_run = 0;
                
                if (can_run) {
                    for (int y=0; y<m; y++) avail[y] += alloc[i][y];
                    finish[i] = 1;
                    count++;
                }
            }
        }
    }

    if (count == n) printf("Request granted (Safe state)\n");
    else printf("Request denied (Leads to deadlock)\n");

    return 0;
}