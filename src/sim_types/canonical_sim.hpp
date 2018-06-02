// canonical_sim.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef CANONICAL_SIM_HPP
#define CANONICAL_SIM_HPP

#include <iostream>
#include <vector>
#include "../sim.hpp"
#include "yaml-cpp/yaml.h"

class Canonical_Sim : public Sim {
 public:
  Canonical_Sim(YAML::Node input);
  virtual ~Canonical_Sim(){};
  virtual void run(void);
  virtual void write_grid_data(void);
  virtual void write_log_data(void);
};

#endif  // CANONICAL_SIM_HPP
