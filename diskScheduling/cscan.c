#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[] = {55, 58, 39, 18, 90, 160, 150, 38, 184};
    int n = 9, head = 100, max_track = 199, total_mov = 0;
    
    // Sorted array including 0, head, and 199
    int tracks[12] = {0, 18, 38, 39, 55, 58, 90, 100, 150, 160, 184, 199};
    int head_idx = 7; // Index of 100

    printf("C-SCAN Order: ");
    
    // 1. Move towards lower tracks (per prompt: "moving toward lower tracks")
    for (int i = head_idx; i >= 0; i--) {
        printf("%d ", tracks[i]);
        if (i < head_idx) total_mov += abs(tracks[i+1] - tracks[i]);
    }

    printf("(Jump) ");
    total_mov += abs(0 - 199); // Jump to opposite end

    // 2. Continue towards lower tracks from the top
    for (int i = 11; i > head_idx; i--) {
        printf("%d ", tracks[i]);
        if (i < 11) total_mov += abs(tracks[i+1] - tracks[i]);
    }

    printf("\nTotal Head Movement: %d\n", total_mov);
    return 0;
}