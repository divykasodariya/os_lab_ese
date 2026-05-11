#include <stdio.h>
#include "geometry.h"

int main() {
    Complex c = {1.0, 1.0};
    
    printf("Magnitude: %.2f\n", magnitude(c));
    printf("Phase (Radians): %.2f\n", phase(c));
    return 0;
}