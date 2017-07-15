// canonical_sim.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef CANONICAL_SIM_HPP
#define CANONICAL_SIM_HPP

#include <iostream>
#include "yaml-cpp/yaml.h"
#include "../sim.hpp"

class Canonical_Sim : public Sim {
 public:
  Canonical_Sim(YAML::Node input) { init(input); };
  ~Canonical_Sim() {};
  void init(YAML::Node input);
  void run(void);
  void write_grid_data(void);
  void write_log_data(void);
};

#endif // CANONICAL_SIM_HPP
