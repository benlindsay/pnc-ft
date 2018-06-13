// utils.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef UTILS_HPP
#define UTILS_HPP

#include <algorithm>  // std::transform
#include <fstream>
#include <string>
#include "globals.hpp"
#include "yaml-cpp/yaml.h"

namespace utils {

void die();
void die(std::string);
void die(std::stringstream&);
std::string to_lower(std::string);
void to_lower(YAML::Node);
void print_one_line(std::string);
void print_one_line(const char*);
void print_one_line(std::stringstream&);
void print_one_line(std::ofstream&, std::string);
void print_one_line(std::ofstream&, std::stringstream&);
}  // namespace utils

#endif  // UTILS_HPP
