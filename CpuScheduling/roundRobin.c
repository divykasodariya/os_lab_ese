#include <stdio.h>

int main() {
    int n = 4;
    // J1=10, J2=4, J3=6, J4=3
    int bt[] = {10, 4, 6, 3};      
    int rem_bt[] = {10, 4, 6, 3};  // Remaining burst times
    int ct[4] = {0};               // Completion times
    
    int quantum = 3;
    int current_time = 0;
    int completed_jobs = 0;
    int first_finished = -1;

    // Simulate Round Robin until all jobs are done
    while (completed_jobs < n) {
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                // If job needs more time than the quantum
                if (rem_bt[i] > quantum) {
                    current_time += quantum;
                    rem_bt[i] -= quantum;
                } 
                // If job can finish in this quantum
                else {
                    current_time += rem_bt[i];
                    ct[i] = current_time;
                    rem_bt[i] = 0;
                    completed_jobs++;

                    // Track which job finishes first
                    if (first_finished == -1) {
                        first_finished = i + 1; // Using 1-based index (e.g., J4)
                    }
                }
            }
        }
    }

    // Output Results
    float total_tat = 0;
    
    printf("Job\tBT\tCT\tTAT\n");
    for (int i = 0; i < n; i++) {
        // Since AT = 0, Turnaround Time equals Completion Time
        int tat = ct[i]; 
        total_tat += tat;
        printf("J%d\t%d\t%d\t%d\n", i + 1, bt[i], ct[i], tat);
    }

    printf("\nJob J%d finished first at time %d.\n", first_finished, ct[first_finished - 1]);
    printf("Average Turnaround Time: %.2f ms\n", total_tat / n);

    return 0;
}