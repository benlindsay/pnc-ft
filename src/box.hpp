// box.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef BOX_HPP
#define BOX_HPP

#include <set>
#include <cmath>
#include "yaml-cpp/yaml.h"
#include "globals.hpp"
#include "utils.hpp"
#include "sim.hpp"
// #include "fftw_utils.hpp"
// #include "component.hpp"

class Sim;
// class FFTW_Utils;
// class Component;

class Box {
 public:
  Box(YAML::Node input, Sim *_sim);
  ~Box();

  Sim *sim;
  // FFTW_Utils *fftw_utils;
  // std::vector<Component*> components;

  double *Lx;
  int *Nx;
  double *dx;
  double V;
  int M;
};

#endif // BOX_HPP
