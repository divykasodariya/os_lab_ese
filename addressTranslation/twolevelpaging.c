#include <stdio.h>

int main() {
    unsigned int v_addr = 0x00403004;
    
    // 1. Extracting bits using shifts and masks
    // 0x3FF is hex for 1023 (10 binary 1s). 0xFFF is hex for 4095 (12 binary 1s).
    unsigned int l1_index = (v_addr >> 22) & 0x3FF; // Extract bits [31:22]
    unsigned int l2_index = (v_addr >> 12) & 0x3FF; // Extract bits [21:12]
    unsigned int offset   = v_addr & 0xFFF;         // Extract bits [11:0]
    
    // 2. Using the data given directly by the problem statement
    // "L1[1] points to L2 table base; L2[3] points to frame 7"
    unsigned int frame = 7; 
    unsigned int page_size = 4096; // 4KB

    // 3. Compute Physical Address = (Frame * Page Size) + Offset
    unsigned int p_addr = (frame * page_size) + offset;

    // Print the step-by-step extraction and final result
    printf("Virtual Address: 0x%08X\n", v_addr);
    printf("Extracted -> L1 Index: %d, L2 Index: %d, Offset: %d\n", l1_index, l2_index, offset);
    printf("Computed Physical Address: %d (Hex: 0x%X)\n", p_addr, p_addr);

    return 0;
}