// utils.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "utils.hpp"

void utils::die() {
  std::string message = "";
  utils::die(message);
}

void utils::die(std::string message) {
#ifdef MPI
  if (RANK == 0) {
    std::cout << message << std::endl;
    std::cout << "Exiting program." << std::endl;
  }

  MPI_Finalize();
#else
  std::cout << message << std::endl;
  std::cout << "Exiting program." << std::endl;
#endif
  exit(1);
}

std::string utils::to_lower(std::string str) {
  // transform is from algorithm library
  // See link below:
  // stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}

void utils::to_lower(YAML::Node node) {
  if (node.IsNull()) {
    return;
  }
  if (node.IsScalar()) {
    node = to_lower(node.as<std::string>());
  } else if (node.IsMap()) {
    for (YAML::iterator it = node.begin(); it != node.end(); ++it) {
      to_lower(it->first);
      to_lower(it->second);
    }
  } else if (node.IsSequence()) {
    for (std::size_t i = 0; i < node.size(); i++) {
      to_lower(node[i]);
    }
  }
}
