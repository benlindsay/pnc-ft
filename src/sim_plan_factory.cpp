// sim_plan_factory.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "sim_plan_factory.hpp"

Sim_Plan* Sim_Plan_Factory::New_Sim_Plan(YAML::Node input) {
  if (!input["sim_plan"]) {
    utils::print_one_line(
        "sim_plan not included in input. Assuming single_sim.");
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

Sim_Plan* Sim_Plan_Factory::New_Sim_Plan(fs::path input_file_path) {
  input_file_path = fs::canonical(fs::absolute(input_file_path));
  fs::path input_file_dir = input_file_path.parent_path();
  // Read input file and check validity of inputs.
  // Information from input file is stored in input_reader object
  YAML::Node input = YAML::LoadFile(input_file_path.string());
  utils::to_lower(input);

  if (input["output_dir"]) {
    fs::path absolute_output_dir = 
        fs::canonical(fs::absolute(input["output_dir"].as<std::string>()));
    input["output_dir"] = absolute_output_dir.string();
  } else {
    input["output_dir"] = input_file_dir.string();
  }

  return New_Sim_Plan(input);
}
