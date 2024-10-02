#pragma once

#include <omp_extra.h>
//#include <omp.h>
#include <cstdint> // unint_t
#include <complex> 
typedef std::complex<double> complex_d;
#include <cmath> // pi, exp

complex_d singleDFTterm( double* signal, unsigned int P, unsigned int Q, uint64_t N);

