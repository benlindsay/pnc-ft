// brent_plan.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "brent_plan.hpp"

Brent_Plan::Brent_Plan(YAML::Node input) : Sim_Plan(input) {
  std::cout << "Initializing Brent_Plan" << std::endl;
}

void Brent_Plan::run() {
  std::cout << "Running Brent_Plan" << std::endl;
  sim->run();
}
