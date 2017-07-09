// sim_plan.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef SIM_PLAN_HPP
#define SIM_PLAN_HPP

#include "globals.hpp"
// #include "sim.hpp"
#include "yaml-cpp/yaml.h"

class Sim_Plan {
 public:
  virtual void init(YAML::Node input) = 0;
  virtual void run(void) = 0;
  virtual ~Sim_Plan() {};
  // Sim *sim;
};

#endif // SIM_PLAN_HPP
