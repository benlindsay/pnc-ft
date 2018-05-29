// sim_plan.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef SIM_PLAN_HPP
#define SIM_PLAN_HPP

#include "globals.hpp"
#include "sim.hpp"
#include "sim_factory.hpp"
#include "utils.hpp"
#include "yaml-cpp/yaml.h"

class Sim_Plan {
 public:
  Sim_Plan(YAML::Node input);
  virtual ~Sim_Plan() { delete sim; };
  virtual void run(void) = 0;
  Sim *sim;
};

#endif  // SIM_PLAN_HPP
