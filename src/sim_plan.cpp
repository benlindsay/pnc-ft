// sim_plan.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "sim_plan.hpp"

void Sim_Plan::init(YAML::Node input) {
  sim = Sim_Factory::New_Sim(input);
}
