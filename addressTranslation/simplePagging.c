#include <stdio.h>

int main() {
    // Page table: index is the virtual page number, value is the physical frame
    // Page 0 -> Frame 3, Page 1 -> Frame 1, Page 2 -> Frame 4
    int page_table[] = {3, 1, 4}; 
    
    // Virtual addresses to translate
    unsigned int v_addrs[] = {0x1A3F, 0x2B10};

    for (int i = 0; i < 2; i++) {
        unsigned int v_addr = v_addrs[i];
        
        // Extract page number and offset using bitwise logic
        unsigned int page_num = v_addr >> 12;      // Shift right by 12 bits
        unsigned int offset   = v_addr & 0x0FFF;   // Mask to keep only the lower 12 bits

        // Look up the frame number in the page table
        unsigned int frame_num = page_table[page_num];
        
        // Physical Address = (Frame Number shifted left by 12) + offset
        unsigned int p_addr = (frame_num << 12) | offset;

        printf("Virtual: 0x%04X -> Page: %d, Offset: 0x%03X -> Physical: 0x%04X\n", 
               v_addr, page_num, offset, p_addr);
    }
    
    return 0;
}