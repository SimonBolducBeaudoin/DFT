#include "dft_py.h"

complex_d singleDFTterm( double* signal, double F, double dt, uint64_t N) {
    complex_d tmp(0.0, 0.0); // Initialize as a complex number (0.0 + 0.0j)
    complex_d FT(0.0, 2 * M_PI * F * dt); // 1j * 2 * pi * F * dt
    #pragma omp parallel for simd
    for (uint64_t i = 0; i < N; ++i) {
        tmp += signal[i] * std::exp(FT * static_cast<double>(i));
    }
    return tmp;
}

    