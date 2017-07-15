// single_sim_plan.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "single_sim_plan.hpp"

void Single_Sim_Plan::init(YAML::Node input) {
  std::cout << "Initializing Single_Sim_Plan" << std::endl;
  Sim_Plan::init(input);
}

void Single_Sim_Plan::run() {
  std::cout << "Running Single_Sim_Pan" << std::endl;
  sim->run();
}
