#include "math_lib.h"
#include <math.h>

// Magnitude = sqrt(a^2 + b^2)
double abs_complex(Complex c) {
    return sqrt((c.real * c.real) + (c.imag * c.imag));
}

// Square = (a^2 - b^2) + i(2ab)
Complex square_complex(Complex c) {
    Complex res;
    res.real = (c.real * c.real) - (c.imag * c.imag);
    res.imag = 2 * c.real * c.imag;
    return res;
}