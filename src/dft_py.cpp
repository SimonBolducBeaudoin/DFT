#include "dft_py.h"

complex_d singleDFTterm_py( np_double& signal, double F, double dt){
    py::buffer_info buf_in = signal.request() ;
    return singleDFTterm((double*)buf_in.ptr,F,dt,buf_in.size) ;
}

void init_dft(py::module &m)
{
	m.def("singleDFTterm", &singleDFTterm_py , "signal"_a.noconvert() , "F"_a , "dt"_a ) ;
}
    