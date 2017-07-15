// brent_plan.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "brent_plan.hpp"

void Brent_Plan::init(YAML::Node input) {
  std::cout << "Initializing Brent_Plan" << std::endl;
  Sim_Plan::init(input);
}

void Brent_Plan::run() {
  std::cout << "Running Brent_Plan" << std::endl;
  sim->run();
}
