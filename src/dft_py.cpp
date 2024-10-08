#include "dft_py.h"

complex_d singleDFTterm_py(np_double &signal, unsigned int P, unsigned int Q) {
  py::buffer_info buf_in = signal.request();
  return singleDFTterm((double *)buf_in.ptr, P, Q, buf_in.size);
}
complex_d singleDFTterm_py(np_int16 &signal, unsigned int P, unsigned int Q) {
  py::buffer_info buf_in = signal.request();
  return singleDFTterm((int16_t *)buf_in.ptr, P, Q, buf_in.size);
}

void init_dft(py::module &m) {
  m.def("singleDFTterm",
        py::overload_cast<np_double &, unsigned int, unsigned int>(&singleDFTterm_py),
        "signal"_a.noconvert(), "P"_a.noconvert(), "Q"_a.noconvert());
  m.def("singleDFTterm",
        py::overload_cast<np_int16 &, unsigned int, unsigned int>(&singleDFTterm_py),
        "signal"_a.noconvert(), "P"_a.noconvert(), "Q"_a.noconvert());
}
