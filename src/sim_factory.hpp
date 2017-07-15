// sim_factory.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef SIM_FACTORY_HPP
#define SIM_FACTORY_HPP

#include "sim.hpp"
#include "sim_types/canonical_sim.hpp"
#include "yaml-cpp/yaml.h"
#include "utils.hpp"

class Sim_Factory {
 public:
  static Sim *New_Sim(YAML::Node input);
};


#endif // SIM_FACTORY_HPP
