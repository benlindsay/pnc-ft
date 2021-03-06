// output_factory.cpp
//
// Copyright (c) 2018 Ben Lindsay <benjlindsay@gmail.com>

#include "output_factory.hpp"
#include "output_types/summary_output.hpp"

Output* Output_Factory::New_Output(Sim* sim, YAML::Node input,
                                   std::string output_type,
                                   YAML::Node output_type_params) {
  if (output_type == "summary") {
    std::vector<std::string> var_list = sim->default_summary_var_list;
    int print_freq = Output::default_print_freq;
    std::string file_name = Summary_Output::default_file_name;
    int column_width = Output::default_column_width;
    bool write_header = true;
    for (YAML::const_iterator it = output_type_params.begin();
         it != output_type_params.end(); ++it) {
      std::string key = it->first.as<std::string>();
      YAML::Node value = it->second;
      if (key == "var_list") {
        var_list = value.as<std::vector<std::string> >();
      } else if (key == "print_freq") {
        print_freq = value.as<int>();
      } else if (key == "file_name") {
        file_name = value.as<std::string>();
      } else if (key == "column_width") {
        column_width = value.as<int>();
      } else if (key == "write_header") {
        write_header = value.as<bool>();
      } else {
        utils::die("Can't recognize summary output parameter '" +
                   value.as<std::string>() + "'");
      }
    }
    fs::path output_dir(input["output_dir"].as<std::string>());
    fs::path file_path = output_dir / fs::path(file_name);
    return new Summary_Output(sim, var_list, print_freq, file_path,
                              column_width, write_header);
  } else {
    utils::die("Can't recognize output type '" + output_type + "'!");
    return NULL;
  }
}
