// canonical_sim.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "canonical_sim.hpp"

Canonical_Sim::Canonical_Sim(YAML::Node input) : Sim(input) {
  utils::print_one_line("Initializing Canonical_Sim");
  init_default_summary_var_list();
  init_output_list(input);
  write_iter_0_outputs();
}

Canonical_Sim::~Canonical_Sim() {
  for (size_t i = 0; i < output_list.size(); i++) {
    delete output_list[i];
  }
}

std::string Canonical_Sim::get_var_as_string(std::string var_name,
                                             int str_len) {
  std::string var_name_lower = utils::to_lower(var_name);
  std::ostringstream os;
  if (var_name_lower == "iter") {
    os << std::setw(str_len - 1) << iter;
    return " " + os.str();
  } else if (var_name_lower == "h") {
    return " H=1234567";
  } else if (var_name_lower == "err") {
    return " err=1e-03";
  } else {
    utils::die("Can't find match for " + var_name);
  }
  return "";
}

void Canonical_Sim::init_default_summary_var_list() {
  default_summary_var_list.push_back("iter");
  default_summary_var_list.push_back("H");
  default_summary_var_list.push_back("err");
}

void Canonical_Sim::init_output_list(YAML::Node input) {
  if (!input["outputs"]) {
    // If no outputs are specified in the input file, just do default outputs
    Output *output = new Summary_Output(this, default_summary_var_list);
    output_list.push_back(output);
  } else {
    // Otherwise, add an Output object for each output type specified in the
    // YAML file
    YAML::Node outputs_node = input["outputs"];
    for (YAML::const_iterator it = outputs_node.begin();
         it != outputs_node.end(); ++it) {
      std::string output_type = it->first.as<std::string>();
      YAML::Node output_type_params = it->second;  // outputs_node[output_type];
      Output *output =
          Output_Factory::New_Output(this, output_type, output_type_params);
      output_list.push_back(output);
    }
  }
}

void Canonical_Sim::run() {
  utils::print_one_line("Running Canonical_Sim");
  for (iter = 1; iter <= max_iter; iter++) {
    write_outputs();
  }
}