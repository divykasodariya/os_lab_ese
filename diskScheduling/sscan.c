#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int n = 8, head = 50, max_track = 199, total_mov = 0;

    // 1. Add head and max_track to array, then sort
    int tracks[10] = {11, 34, 41, 50, 60, 79, 92, 114, 176, 199}; 
    int head_idx = 3; // Index of 50 in sorted array

    printf("SCAN Order: ");
    
    // 2. Move towards higher tracks
    for (int i = head_idx; i < 10; i++) {
        printf("%d ", tracks[i]);
        if (i > head_idx) total_mov += abs(tracks[i] - tracks[i-1]);
    }
    
    // 3. Reverse and move towards lower tracks
    total_mov += abs(tracks[9] - tracks[head_idx - 1]); // Jump from 199 to highest lower track
    for (int i = head_idx - 1; i >= 0; i--) {
        printf("%d ", tracks[i]);
        if (i < head_idx - 1) total_mov += abs(tracks[i+1] - tracks[i]);
    }

    printf("\nTotal Head Movement: %d\n", total_mov);
    return 0;
}