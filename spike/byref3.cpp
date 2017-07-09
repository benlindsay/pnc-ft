// byref3.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include <iostream>
#include <vector>
#include "yaml-cpp/yaml.h"

std::string edit_string(std::string str) {
  return str + "_edited";
}

void iterate_node(YAML::Node node) {
  if (node.IsNull()) {
    return;
  }
  if (node.IsScalar()) {
    node = edit_string(node.as<std::string>());
  }
  else if (node.IsMap()) {
    for (YAML::iterator it = node.begin(); it != node.end(); ++it) {
      iterate_node(it->first);
      iterate_node(it->second);
    }
  }
  else if (node.IsSequence()) {
    for (std::size_t i=0; i < node.size(); i++) {
      iterate_node(node[i]);
    }
  }
}

int main(int argc, const char *argv[])
{
  YAML::Node input = YAML::Load("{sequence: [foo: bar, baz, qux]}");
  std::cout << input << std::endl;
  iterate_node(input);
  std::cout << input << std::endl;
  return 0;
}
