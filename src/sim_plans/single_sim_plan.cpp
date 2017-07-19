// single_sim_plan.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "single_sim_plan.hpp"

Single_Sim_Plan::Single_Sim_Plan(YAML::Node input) : Sim_Plan(input) {
  std::cout << "Initializing Single_Sim_Plan" << std::endl;
}

void Single_Sim_Plan::run() {
  std::cout << "Running Single_Sim_Pan" << std::endl;
  sim->run();
}
