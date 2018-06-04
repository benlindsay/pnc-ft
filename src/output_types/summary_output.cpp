// summary_output.cpp
//
// Copyright (c) 2018 Ben Lindsay <benjlindsay@gmail.com>

#include "summary_output.hpp"

Summary_Output::Summary_Output(Sim *sim, std::vector<std::string> var_list,
                               int print_freq, std::string file_name,
                               int column_width)
    : Output(sim) {
  init(sim, var_list, print_freq, file_name, column_width);
}

Summary_Output::Summary_Output(Sim *sim, std::vector<std::string> var_list)
    : Output(sim) {
  init(sim, var_list);
}

void Summary_Output::init(Sim *_sim, std::vector<std::string> _var_list,
                          int _print_freq, std::string _file_name,
                          int _column_width) {
  sim = _sim;
  var_list = _var_list;
  print_freq = _print_freq;
  file_name = _file_name;
  column_width = _column_width;

  file.open(file_name);
}

void Summary_Output::init(Sim *sim, std::vector<std::string> var_list) {
  int print_freq = Output::default_column_width;
  std::string file_name = Summary_Output::default_file_name;
  int column_width = Output::default_column_width;

  init(sim, var_list, print_freq, file_name, column_width);
}

Summary_Output::~Summary_Output(void) { file.close(); }

const std::string Summary_Output::default_file_name = "summary.dat";

bool Summary_Output::is_time_to_write(void) {
  if (sim->iter % print_freq == 0) {
    return true;
  } else {
    return false;
  }
}

void Summary_Output::write(void) {
  std::string output_line;
  for (size_t i = 0; i < var_list.size(); i++) {
    file << sim->get_var_as_string(var_list[i], column_width);
  }
  file << "\n";
}