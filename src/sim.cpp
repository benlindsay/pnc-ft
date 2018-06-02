// sim.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "sim.hpp"

Sim::Sim(YAML::Node input) {
  std::cout << "Initializing Sim" << std::endl;
  // Initialize dim
  if (!input["dim"]) {
    utils::die("dim keyword not found in input file");
  } else {
    dim = input["dim"].as<int>();
  }

  // Initialize
  init_box_vars(input);
}

Sim::~Sim() {
  delete Lx;
  delete Nx;
  delete dx;
}

void Sim::init_box_vars(YAML::Node input) {
  // Initialize Lx, Nx, and dx
  Lx = new double[dim];
  Nx = new int[dim];
  dx = new double[dim];

  // 2 of the 3 must be input, and we can calculate the 3rd from the other 2.
  // To figure out which 2 were input, we'll start with the set of those 3 and
  // delete the corresponding string from the set until we're left with just 1
  std::set<std::string> keys = {"lx", "nx", "dx"};
  for (YAML::const_iterator it = input.begin(); it != input.end(); ++it) {
    if (it->first.as<std::string>() == "lx") {
      if (input["lx"].size() != size_t(dim)) {
        utils::die("Length of lx must equal dim (" + std::to_string(dim) + ")");
      }
      for (std::size_t i = 0; i < size_t(dim); i++) {
        Lx[i] = input["lx"][i].as<double>();
      }
      keys.erase("lx");
    } else if (it->first.as<std::string>() == "nx") {
      if (input["nx"].size() != size_t(dim)) {
        utils::die("Length of nx must equal dim (" + std::to_string(dim) + ")");
      }
      for (std::size_t i = 0; i < size_t(dim); i++) {
        Nx[i] = input["nx"][i].as<int>();
      }
      keys.erase("nx");
    } else if (it->first.as<std::string>() == "dx") {
      if (input["dx"].size() != size_t(dim)) {
        utils::die("Length of dx must equal dim (" + std::to_string(dim) + ")");
      }
      for (std::size_t i = 0; i < size_t(dim); i++) {
        dx[i] = input["dx"][i].as<double>();
      }
      keys.erase("dx");
    }
  }
  if (keys.size() != 1) {
    utils::die("You must define exactly two of the following: Lx, Nx, dx");
  }

  // Calculate the 3rd variable (Lx, Nx, or dx)
  std::string remaining_var = *(keys.begin());
  if (remaining_var == "lx") {
    for (int i = 0; i < dim; i++) {
      Lx[i] = Nx[i] * dx[i];
    }
  } else if (remaining_var == "nx") {
    for (int i = 0; i < dim; i++) {
      Nx[i] = int(std::floor(Lx[i] / dx[i]));
      if (Nx[i] % 2 == 0) {
        Nx[i] += 1;
      }
      dx[i] = Lx[i] / Nx[i];
    }
  } else if (remaining_var == "dx") {
    for (int i = 0; i < dim; i++) {
      dx[i] = Lx[i] / Nx[i];
    }
  }

  // Assign V and M
  V = 1.0;
  M = 1;
  for (int i = 0; i < dim; i++) {
    V *= Lx[i];
    M *= Nx[i];
  }
}
