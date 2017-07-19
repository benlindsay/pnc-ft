// sim.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "sim.hpp"

Sim::Sim(YAML::Node input) {
  std::cout << "Initializing Sim" << std::endl;
  // Initialize dim
  if (!input["dim"]) {
    utils::die("dim keyword not found in input file");
  }
  else {
    dim = input["dim"].as<int>();
  }
}

Sim::~Sim() {
  for (size_t i = 0; i < boxes.size(); i++) {
    delete boxes[i];
  }
}
