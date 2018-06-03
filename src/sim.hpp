// sim.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef SIM_HPP
#define SIM_HPP

#include <cmath>
#include <iostream>
#include <valarray>
#include "Eigen/Dense"
#include "utils.hpp"
#include "yaml-cpp/yaml.h"

using Eigen::ArrayXd;  // Dynamically sized double Array
using Eigen::ArrayXi;  // Dynamically sized int Array

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

  int dim;
  int iter;
  int max_iter;

  // Grid/box variables
  ArrayXd Lx;
  ArrayXi Nx;
  ArrayXd dx;
  double V;
  int M;
  int ML;

 private:
  void init_box_vars(YAML::Node input);
};

#endif  // SIM_HPP
