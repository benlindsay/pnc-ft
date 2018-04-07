// canonical_sim.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "canonical_sim.hpp"

Canonical_Sim::Canonical_Sim(YAML::Node input) : Sim(input) {
  std::cout << "Initializing Canonical_Sim" << std::endl;
  boxes.push_back(new Box(input, this));
}

void Canonical_Sim::run() {
  std::cout << "Running Canonical_Sim" << std::endl;
}

void Canonical_Sim::write_grid_data() {
  std::cout << "Writing grid data" << std::endl;
}

void Canonical_Sim::write_log_data() {
  std::cout << "Writing log data" << std::endl;
}
