// output_factory.hpp
//
// Copyright (c) 2018 Ben Lindsay <benjlindsay@gmail.com>

#ifndef OUTPUT_FACTORY_HPP
#define OUTPUT_FACTORY_HPP

#include "output.hpp"
#include "yaml-cpp/yaml.h"

class Output;
class Sim;

class Output_Factory {
 public:
  static Output *New_Output(Sim *sim, std::string output_type,
                            YAML::Node output_type_params);
};

#endif  // OUTPUT_FACTORY_HPP