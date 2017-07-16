// brent_plan.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef BRENT_PLAN_HPP
#define BRENT_PLAN_HPP

#include <iostream>
#include "yaml-cpp/yaml.h"
#include "../globals.hpp"
#include "../sim.hpp"
#include "../sim_plan.hpp"

class Brent_Plan : public Sim_Plan {
 public:
  Brent_Plan(YAML::Node input) { init(input); };
  virtual ~Brent_Plan() {};
  virtual void init(YAML::Node input);
  virtual void run(void);
};

#endif // BRENT_PLAN_HPP
