#pragma once

#include <omp_extra.h>
//#include <omp.h>
#include <complex>
#include <cstdint> // unint_t
typedef std::complex<double> complex_d;
#include <cmath> // pi, exp

complex_d singleDFTterm(double *signal, unsigned int P, unsigned int Q,
                        uint64_t N);
