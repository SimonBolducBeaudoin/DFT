#pragma once

#include "dft.h"

#include <pybind11/complex.h>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace pybind11::literals;
typedef py::array_t<double, py::array::c_style> np_double;
typedef py::array_t<int16_t, py::array::c_style> np_int16;

#include <complex>
typedef std::complex<double> complex_d;

complex_d singleDFTterm_py(np_double &signal, unsigned int P, unsigned int Q);
void init_dft(py::module &m);
complex_d singleDFTterm_py(np_int16 &signal, unsigned int P, unsigned int Q);
void init_dft(py::module &m);
