// sim_plan.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef SIM_PLAN_HPP
#define SIM_PLAN_HPP

#include "globals.hpp"
#include "yaml-cpp/yaml.h"
#include "utils.hpp"
#include "sim.hpp"
#include "sim_factory.hpp"

class Sim_Plan {
 public:
  virtual ~Sim_Plan() { delete sim; };
  virtual void init(YAML::Node input);
  virtual void run(void) = 0;
  Sim *sim;
};

#endif // SIM_PLAN_HPP
