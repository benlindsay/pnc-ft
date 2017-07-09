// single_sim_plan.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef SINGLE_SIM_PLAN_HPP
#define SINGLE_SIM_PLAN_HPP

class Sim_Plan;

#include "../sim_plan.hpp"
// #include "../sim.hpp"
#include "yaml-cpp/yaml.h"
#include <iostream>

class Single_Sim_Plan : public Sim_Plan {
 public:
  Single_Sim_Plan(YAML::Node input) { init(input); };
  void init(YAML::Node input);
  void run(void);
  virtual ~Single_Sim_Plan() {};
};

#endif // SINGLE_SIM_PLAN_HPP
