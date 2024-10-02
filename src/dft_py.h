#pragma once

#include "dft.h"

#include <pybind11/pybind11.h>
#include <pybind11/complex.h>
#include <pybind11/numpy.h>

namespace py = pybind11 ;
using namespace pybind11::literals ;
typedef py::array_t<double,py::array::c_style> np_double ; 

#include <complex> 
typedef std::complex<double> complex_d;

complex_d singleDFTterm_py( np_double& signal, unsigned int P, unsigned int Q);
void init_dft(py::module &m);

