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
  if (iter > last_hamiltonian_iter) {
    update_hamiltonian();
  }
  std::string var_name_lower = utils::to_lower(var_name);
  std::ostringstream os;
  // Assuming we want 1 space between fields, 2 characters go to "#.", and 4
  // characters go to exponent, i.e. "e+00", string length - 7 gives the number
  // of digits we can put after the decimal
  int scientific_precision = str_len - 7;
  // Set number of digits after decimal point in scientific notation
  os.precision(scientific_precision);
  // Set minimum width of output string (left-padded with spaces)
  os << std::setw(str_len - 1);
  // Add scientific notation flag to force specified number of digits after
  // decimal point
  os << std::scientific;
  if (var_name_lower == "iter") {
    os << iter;
  } else if (var_name_lower == "h_real") {
    os << hamiltonian.real();
  } else if (var_name_lower == "h_imag") {
    os << hamiltonian.imag();
  } else if (var_name_lower == "h_err") {
    os << hamiltonian_err;
  } else {
    utils::die("Can't find match for " + var_name);
  }
  return " " + os.str();
}

void Canonical_Sim::init_default_summary_var_list() {
  default_summary_var_list.push_back("iter");
  default_summary_var_list.push_back("h_real");
  default_summary_var_list.push_back("h_imag");
  default_summary_var_list.push_back("h_err");
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

// Private Functions

std::complex<double> Canonical_Sim::calc_hamiltonian() { return 0.0; }

void Canonical_Sim::update_hamiltonian() {
  hamiltonian_prev = hamiltonian;
  hamiltonian = calc_hamiltonian();
  int n_elapsed_iters = iter - last_hamiltonian_iter;
  hamiltonian_err =
      (hamiltonian - hamiltonian_prev).real() / double(n_elapsed_iters);
  last_hamiltonian_iter = iter;
}
