#include "dft.h"

complex_d singleDFTterm( double* signal, unsigned int P, unsigned int Q , uint64_t N) {
    // i is in increment of the rationnal number P/Q
    complex_d res(0.0, 0.0);
    
    double T( 2 * M_PI * P / ((double)Q) ); 
    
    double* cos = new double[Q];
    double* sin = new double[Q];
    for (uint64_t i = 0; i < Q; ++i) {
        cos[i] = std::cos( T*(double)i );
        sin[i] = std::sin( T*(double)i );
    }
    
    uint64_t chunks = N/2 ;
    double real(0.0);
    double imag(0.0); 
    double real1(0.0);
    double imag1(0.0); 
    #pragma omp parallel 
    {
        manage_thread_affinity();        
        #pragma omp for simd safelen(2) reduction(+:real, imag, real1, imag1)
        for (uint64_t i = 0; i < chunks; i+=2) {
            real += signal[i] * cos[i%Q] ;
            imag += signal[i] * sin[i%Q] ;
            real1 += signal[i+1] * cos[(i+1)%Q] ;
            imag1 += signal[i+1] * sin[(i+1)%Q] ;
        }
    }
    
    delete[] cos ;
    delete[] sin ;
    
    real+=real1;
    imag+=imag1;
    
    res.real(real);
    res.imag(imag);
    
    return res;
}