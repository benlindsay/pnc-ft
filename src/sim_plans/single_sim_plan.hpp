// single_sim_plan.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef SINGLE_SIM_PLAN_HPP
#define SINGLE_SIM_PLAN_HPP

class Sim_Plan;

#include <iostream>
#include "yaml-cpp/yaml.h"
#include "../sim.hpp"
#include "../sim_plan.hpp"

class Single_Sim_Plan : public Sim_Plan {
 public:
  Single_Sim_Plan(YAML::Node input);
  virtual ~Single_Sim_Plan() {};
  virtual void run(void);
};

#endif // SINGLE_SIM_PLAN_HPP
