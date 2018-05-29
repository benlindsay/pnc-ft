// box.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "box.hpp"

Box::Box(YAML::Node input, Sim *_sim) : sim(_sim) {
  // Initialize Lx, Nx, and dx
  Lx = new double[sim->dim];
  Nx = new int[sim->dim];
  dx = new double[sim->dim];

  // 2 of the 3 must be input, and we can calculate the 3rd from the other 2.
  // To figure out which 2 were input, we'll start with the set of those 3 and
  // delete the corresponding string from the set until we're left with just 1
  std::set<std::string> keys = {"lx", "nx", "dx"};
  for (YAML::const_iterator it = input.begin(); it != input.end(); ++it) {
    if (it->first.as<std::string>() == "lx") {
      if (input["lx"].size() != size_t(sim->dim)) {
        utils::die("Length of lx must equal sim->dim (" +
                   std::to_string(sim->dim) + ")");
      }
      for (std::size_t i = 0; i < size_t(sim->dim); i++) {
        Lx[i] = input["lx"][i].as<double>();
      }
      keys.erase("lx");
    } else if (it->first.as<std::string>() == "nx") {
      if (input["nx"].size() != size_t(sim->dim)) {
        utils::die("Length of nx must equal sim->dim (" +
                   std::to_string(sim->dim) + ")");
      }
      for (std::size_t i = 0; i < size_t(sim->dim); i++) {
        Nx[i] = input["nx"][i].as<int>();
      }
      keys.erase("nx");
    } else if (it->first.as<std::string>() == "dx") {
      if (input["dx"].size() != size_t(sim->dim)) {
        utils::die("Length of dx must equal sim->dim (" +
                   std::to_string(sim->dim) + ")");
      }
      for (std::size_t i = 0; i < size_t(sim->dim); i++) {
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
    for (int i = 0; i < sim->dim; i++) {
      Lx[i] = Nx[i] * dx[i];
    }
  } else if (remaining_var == "nx") {
    for (int i = 0; i < sim->dim; i++) {
      Nx[i] = int(std::floor(Lx[i] / dx[i]));
      if (Nx[i] % 2 == 0) {
        Nx[i] += 1;
      }
      dx[i] = Lx[i] / Nx[i];
    }
  } else if (remaining_var == "dx") {
    for (int i = 0; i < sim->dim; i++) {
      dx[i] = Lx[i] / Nx[i];
    }
  }

  // Assign V and M
  V = 1.0;
  M = 1;
  for (int i = 0; i < sim->dim; i++) {
    V *= Lx[i];
    M *= Nx[i];
  }
}

Box::~Box() {
  // delete fftw_utils
  // for (int i = 0; i < components.size(); i++) {
  //   delete components[i];
  // }
  delete Lx;
  delete Nx;
  delete dx;
}
