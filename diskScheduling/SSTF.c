#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = 8, head = 53, total_movement = 0;
    int visited[8] = {0};

    printf("Service Order: ");
    for (int i = 0; i < n; i++) {
        int min_dist = 9999, closest_idx = -1;

        // Find the closest unvisited track
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int dist = abs(head - req[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    closest_idx = j;
                }
            }
        }

        visited[closest_idx] = 1;
        total_movement += min_dist;
        head = req[closest_idx]; // Move head
        printf("%d ", head);
    }
    
    printf("\nTotal Head Movement: %d\n", total_movement);
    return 0;
}