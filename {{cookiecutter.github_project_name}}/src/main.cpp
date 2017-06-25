#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}

int subtract(int i, int j) {
    return i - j;
}

namespace py = pybind11;

PYBIND11_PLUGIN({{ cookiecutter.cpp_module_name }}) {
    py::module m("{{ cookiecutter.cpp_module_name }}", R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: '{{ cookiecutter.cpp_module_name }}'

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc");

    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", &subtract, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = py::str(VERSION_INFO);
#else
    m.attr("__version__") = py::str("dev");
#endif

    return m.ptr();
}
