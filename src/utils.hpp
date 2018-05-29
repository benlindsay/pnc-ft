// utils.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef UTILS_HPP
#define UTILS_HPP

#include <algorithm>
#include <string>
#include "globals.hpp"
#include "yaml-cpp/yaml.h"

namespace utils {

void die(void);
void die(std::string);
std::string to_lower(std::string);
void to_lower(YAML::Node);
}

#endif  // UTILS_HPP
