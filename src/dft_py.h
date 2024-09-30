#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/complex.h>
#include <pybind11/numpy.h>

namespace py = pybind11 ;
using namespace pybind11::literals ;

typedef py::array_t<double,py::array::c_style> np_double ; 

typedef std::complex<double> complex_d;
#include <cstdint> // unint_t
#include <complex> 
#include <cmath> // pi, exp

#include "dft.h"

complex_d singleDFTterm_py( np_double& signal, double F, double dt);
void init_dft(py::module &m);

