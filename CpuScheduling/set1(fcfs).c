#include <stdio.h>

int main() {
    int n = 5;
    int at[] = {0, 1, 2, 3, 4};
    int bt[] = {6, 4, 2, 3, 1};
    int ct[5], tat[5], wt[5];
    float total_wt = 0;

    // Calculate Completion, Turnaround, and Waiting times
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        // If CPU was idle, take max of arrival time or previous completion
        int start_time = (at[i] > ct[i-1]) ? at[i] : ct[i-1];
        ct[i] = start_time + bt[i];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
    }

    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Avg Waiting Time: %.2f\n", total_wt / n);

    // Simple Gantt Chart
    printf("\nGantt Chart:\n|");
    for(int i=0; i<n; i++) {
        for(int j=0; j<bt[i]; j++) printf("-");
        printf("P%d|", i+1);
    }
    printf("\n");

    return 0;
}