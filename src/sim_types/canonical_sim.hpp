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
  virtual ~Canonical_Sim() {};
  virtual void init(YAML::Node input);
  virtual void run(void);
  virtual void write_grid_data(void);
  virtual void write_log_data(void);
};

#endif // CANONICAL_SIM_HPP
