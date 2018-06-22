// output.hpp
//
// Copyright (c) 2018 Ben Lindsay <benjlindsay@gmail.com>

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <fstream>   // std::ofstream
#include <iomanip>   // std::setw, std::setprecision
#include <iostream>  // std::cout, std::endl
#include "sim.hpp"
#include "utils.hpp"

class Sim;

class Output {
 public:
  Output(Sim *sim) : sim(sim){};
  virtual ~Output(){};
  virtual bool is_time_to_write(void) = 0;
  virtual void write(void) = 0;
  virtual void write_iter_0(void) = 0;
  static const int default_column_width = 10;
  static const int default_print_freq = 50;

  Sim *sim;
};

#include "output_types/summary_output.hpp"

#endif  // OUTPUT_HPP