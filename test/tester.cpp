// tester.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "tester.hpp"

const size_t MAX_NAME_WIDTH = 25;

void test(std::string test_name, bool test) {
  std::cout.clear();
  std::cout << "Test: " << std::left << std::setw(MAX_NAME_WIDTH)
            << test_name;
  if (test) {
    std::cout << "passed" <<std::endl;
  }
  else {
    std::cout << "===FAILED===" <<std::endl;
  }
  std::cout.setstate(std::ios_base::failbit);
}

int main(int argc, const char *argv[])
{
  YAML::Node input;

  // Test Sim_Plan Input
  Sim_Plan *sim_plan;

  // Turn off stdout. We only want to turn it on for test results.
  std::cout.setstate(std::ios_base::failbit);

  // Empty input
  input = YAML::Load("");
  sim_plan = Sim_Plan_Factory::New_Sim_Plan(input);
  test("Empty input", dynamic_cast<Single_Sim_Plan*>(sim_plan) != NULL);

  // Single_Sim input
  input = YAML::Load("{sim_plan: single_sim}");
  sim_plan = Sim_Plan_Factory::New_Sim_Plan(input);
  test("Single Sim Plan", dynamic_cast<Single_Sim_Plan*>(sim_plan) != NULL);

  // Brent input
  input = YAML::Load("{sim_plan: brent}");
  sim_plan = Sim_Plan_Factory::New_Sim_Plan(input);
  test("Brent Plan", dynamic_cast<Brent_Plan*>(sim_plan) != NULL);

  return 0;
}
