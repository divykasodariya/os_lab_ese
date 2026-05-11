#include <stdio.h>

int main() {
    int n = 5;
    
    // Initial Inputs: Process IDs, Burst Times, Priorities
    int p[]  = {1, 2, 3, 4, 5};
    int bt[] = {4, 3, 5, 1, 2};
    int pr[] = {2, 1, 3, 1, 4}; // Lower number = higher priority
    
    int wt[5], tat[5];
    float total_wt = 0, total_tat = 0;
    
    // 1. Sort processes by priority (Simple sorting logic)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // If the next process has a higher priority (smaller number)
            if (pr[j] < pr[i]) {
                // Swap Priorities
                int temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                // Swap Burst Times
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                // Swap Process IDs
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    // 2. Calculate Waiting Time and Turnaround Time
    wt[0] = 0; // First process doesn't wait (since all arrive at t=0)
    tat[0] = bt[0]; 
    total_tat += tat[0];

    for (int i = 1; i < n; i++) {
        // Waiting time is previous waiting time + previous burst time
        wt[i] = wt[i - 1] + bt[i - 1];
        
        // Turnaround time is waiting time + burst time
        tat[i] = wt[i] + bt[i];
        
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // 3. Print Results
    printf("Job\tPriority\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t%d\t%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}