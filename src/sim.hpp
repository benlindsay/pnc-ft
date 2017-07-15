// sim.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef SIM_HPP
#define SIM_HPP

#include <iostream>
#include "yaml-cpp/yaml.h"

// class FFTW_Utils;

class Sim {
 public:
  virtual ~Sim() {
    delete Lx;
    delete Nx;
    delete dx;
  };
  virtual void init(YAML::Node input);
  virtual void run(void) = 0;
  virtual void write_grid_data(void) = 0;
  virtual void write_log_data(void) = 0;

  // FFTW_Utils *fftw_utils;

  // Box stuff
  double *Lx;
  int *Nx;
  double V;
  double *dx;
  int M;
  int iter;
  int max_iter;
  int grid_freq;
  int log_freq;
};

#endif // SIM_HPP
