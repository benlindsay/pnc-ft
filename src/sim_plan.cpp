// sim_plan.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "sim_plan.hpp"

Sim_Plan::Sim_Plan(YAML::Node input) { sim = Sim_Factory::New_Sim(input); }
