#include <stdio.h>

int main() {
    // Segment Tables
    // Index 0: Code, Index 1: Data, Index 2: Stack
    int base[]  = {1000, 2000, 3000};
    int limit[] = {400, 500, 300};

    // Requests stored as pairs: {Segment, Offset}
    int requests[3][2] = {
        {0, 200}, 
        {1, 600}, 
        {2, 150}
    };

    for (int i = 0; i < 3; i++) {
        int seg = requests[i][0];
        int offset = requests[i][1];

        printf("Request (Seg: %d, Offset: %d) -> ", seg, offset);

        // Crucial Check: Is the offset strictly less than the limit?
        if (offset < limit[seg]) {
            int p_addr = base[seg] + offset;
            printf("Physical Address: %d\n", p_addr);
        } else {
            printf("Segmentation Fault (Out of bounds!)\n");
        }
    }
    
    return 0;
}