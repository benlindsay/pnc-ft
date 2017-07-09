// brent_plan.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef BRENT_PLAN_HPP
#define BRENT_PLAN_HPP

#include "../globals.hpp"
#include "../sim_plan.hpp"
// #include "../sim.hpp"
#include "yaml-cpp/yaml.h"

class Brent_Plan : public Sim_Plan {
 public:
  Brent_Plan(YAML::Node input) { init(input); };
  void init(YAML::Node input);
  void run(void);
  virtual ~Brent_Plan() {};
};

#endif // BRENT_PLAN_HPP
