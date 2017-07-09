// byref.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include <iostream>
#include <vector>
#include "yaml-cpp/yaml.h"

void edit_node(YAML::Node node) {
  for (YAML::iterator it = node.begin(); it != node.end(); ++it) {
    it->first  = it->first.as<std::string>()  + "_edited";
    it->second = it->second.as<std::string>() + "_edited";
  }
}

void edit_vector(std::vector<std::string> vec) {
  for (size_t i = 0; i < vec.size(); i++) {
    vec[i] += "_edited";
  }
}

int main(int argc, const char *argv[])
{
  YAML::Node input = YAML::Load("{foo: bar, baz: qux}");
  // Edit node without passing by reference
  edit_node(input);
  std::cout << input << std::endl;
  // Outputs "{foo_edited: bar_edited, baz_edited: qux_edited}"
  // Changes in function lasted outside the scope of the function
  std::vector<std::string> vec = {"foo", "bar", "baz", "qux"};
  // Attempt to edit vector without passing by reference
  edit_vector(vec);
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << "\n";
  // Outputs "1 2 3 4"
  // Changes in function remained only within scope of function
  return 0;
}

