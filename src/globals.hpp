// globals.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <complex>
#include <iostream>

#ifndef MAIN_HPP
extern
#endif
    int RANK,
    NPROCS;

#ifdef MAIN_HPP
std::complex<double> I(0.0, 1.0);
#else
extern std::complex<double> I;
#endif

#define PI 3.14159265358979323846263383

#endif  // GLOBALS_HPP
