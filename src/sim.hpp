// sim.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef SIM_HPP
#define SIM_HPP

#include <iostream>
#include "box.hpp"
#include "yaml-cpp/yaml.h"

class Box;
// class FFTW_Utils;

class Sim {
 public:
  Sim(YAML::Node input);
  virtual ~Sim();
  virtual void run(void) = 0;
  virtual void write_grid_data(void) = 0;
  virtual void write_log_data(void) = 0;

  // FFTW_Utils *fftw_utils;
  std::vector<Box*> boxes;

  int dim;
  int iter;
  int max_iter;
  int grid_freq;
  int log_freq;
};

#endif  // SIM_HPP
