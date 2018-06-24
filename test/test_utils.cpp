// test_utils.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "test_utils.hpp"
#include "catch.hpp"

TEST_CASE("Path manipulation", "[utils]") {
  std::string rel_path = "params.yaml";
  std::string rel_dirname = utils::get_dirname(rel_path);
  REQUIRE(rel_dirname == ".");
  std::string abs_dirname = utils::get_absolute_path(".");
  std::string cwd = utils::get_cwd();
  REQUIRE(abs_dirname == cwd);
  std::string yaml_path = "/path/to/input/params.yaml";
  std::string input_path = utils::get_dirname(yaml_path);
  REQUIRE(input_path == "/path/to/input");
  std::string test_path = utils::get_cwd() + "/test";
  std::string bin_path = utils::join_paths(test_path, "../bin");
  std::string expected_path = utils::get_cwd() + "/bin";
  REQUIRE(utils::join_paths(test_path, "../bin") == expected_path);
  REQUIRE(utils::join_paths(test_path, "/../bin") == expected_path);
  REQUIRE(utils::join_paths(test_path + "/", "../bin") == expected_path);
  REQUIRE(utils::join_paths(test_path + "/", "/../bin") == expected_path);
}
