#include <stdio.h>
#include "math_lib.h"

int main() {
    Complex c = {3.0, 4.0}; // A classic 3-4-5 triangle for easy magnitude verification
    
    double mag = abs_complex(c);
    Complex sq = square_complex(c);
    
    printf("Magnitude: %.2f\n", mag);
    printf("Square: %.2f + %.2fi\n", sq.real, sq.imag);
    return 0;
}