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

  iter = 0;

  // Initialize max_iter
  if (!input["max_iter"]) {
    max_iter = 100;
  } else {
    max_iter = input["max_iter"].as<int>();
  }

  // Initialize box/grid variables
  init_box_vars(input);
}

Sim::~Sim() {}

void Sim::init_box_vars(YAML::Node input) {
  // Initialize Lx, Nx, and dx
  Lx = ArrayXd(dim);
  Nx = ArrayXi(dim);
  dx = ArrayXd(dim);

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
    Lx = Nx.cast<double>() * dx;
  } else if (remaining_var == "nx") {
    // Calculate Nx rounded to nearest odd int (Odd values work better with
    // FFTW)
    // First, truncate Lx/dx
    Nx = (Lx / dx).cast<int>();
    // Next, add one to any even value in Nx.
    for (int i = 0; i < dim; i++) {
      if (Nx[i] % 2 == 0) {
        Nx[i] += 1;
      }
    }
    // Recalculate dx with the same Lx and the calculated Nx
    dx = Lx / Nx.cast<double>();
  } else if (remaining_var == "dx") {
    dx = Lx / Nx.cast<double>();
  }

  // Assign V and M
  V = Lx.prod();
  M = Nx.prod();
}

void Sim::write_iter_0_outputs(void) {
  for (size_t i = 0; i < output_list.size(); i++) {
    if (output_list[i]->is_time_to_write()) {
      output_list[i]->write_iter_0();
    }
  }
}

void Sim::write_outputs(void) {
  for (size_t i = 0; i < output_list.size(); i++) {
    if (output_list[i]->is_time_to_write()) {
      output_list[i]->write();
    }
  }
}