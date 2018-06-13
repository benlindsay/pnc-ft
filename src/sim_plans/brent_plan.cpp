// brent_plan.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "brent_plan.hpp"

Brent_Plan::Brent_Plan(YAML::Node input) : Sim_Plan(input) {
  utils::print_one_line("Initializing Brent_Plan");
}

void Brent_Plan::run() {
  utils::print_one_line("Running Brent_Plan");
  sim->run();
}
