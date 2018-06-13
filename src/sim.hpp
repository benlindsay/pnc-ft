// sim.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef SIM_HPP
#define SIM_HPP

#include <string>  // std::string
#include <vector>  // std::vector
#include "Eigen/Dense"
#include "yaml-cpp/yaml.h"

#include "output.hpp"
#include "output_factory.hpp"
#include "utils.hpp"

class Output;

using Eigen::ArrayXd;  // Dynamically sized double Array
using Eigen::ArrayXi;  // Dynamically sized int Array

// class FFTW_Utils;

class Sim {
 public:
  Sim(YAML::Node input);
  virtual ~Sim();
  virtual void run(void) = 0;
  virtual std::string get_var_as_string(std::string var_name, int str_len) = 0;
  virtual void init_output_list(YAML::Node input) = 0;
  virtual void init_default_summary_var_list() = 0;
  void write_iter_0_outputs(void);
  void write_outputs(void);

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

  std::vector<Output*> output_list;
  std::vector<std::string> default_summary_var_list;

 private:
  void init_box_vars(YAML::Node input);
};

#endif  // SIM_HPP
