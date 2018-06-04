// sim_plan_factory.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "sim_plan_factory.hpp"

Sim_Plan* Sim_Plan_Factory::New_Sim_Plan(YAML::Node input) {
  if (!input["sim_plan"]) {
    std::cout << "sim_plan not included in input. "
              << "Assuming single_sim." << std::endl;
    return new Single_Sim_Plan(input);
  }
  std::string sim_plan_type = input["sim_plan"].as<std::string>();
  if (sim_plan_type == "single_sim") {
    return new Single_Sim_Plan(input);
  } else if (sim_plan_type == "brent") {
    return new Brent_Plan(input);
  } else {
    utils::die("sim_plan " + sim_plan_type + " not recognized");
    return NULL;
  }
}
