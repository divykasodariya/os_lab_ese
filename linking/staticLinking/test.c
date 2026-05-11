#include <stdio.h>
#include "complex.h"

int main() {
    Complex c1 = {2.0, 3.0}, c2 = {1.0, 4.0};
    Complex sum = add_complex(c1, c2);
    Complex prod = mul_complex(c1, c2);
    
    printf("Sum: %.1f + %.1fi\n", sum.real, sum.imag);
    printf("Prod: %.1f + %.1fi\n", prod.real, prod.imag);
    return 0;
}