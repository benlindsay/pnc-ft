// test_init.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>
#include "catch.hpp"

#include "test_init.hpp"

TEST_CASE("Bare bones input", "[input]") {
  const char* yaml_1 =
      "dim: 3\n"
      "lx:  [1,2,3]\n"
      "nx:  [10,10,10]\n";
  YAML::Node input = YAML::Load(yaml_1);

  // Test sim_plan Input
  std::cout.setstate(std::ios_base::failbit);
  Sim_Plan* sim_plan = Sim_Plan_Factory::New_Sim_Plan(input);
  std::cout.clear();

  REQUIRE(dynamic_cast<Single_Sim_Plan*>(sim_plan) != NULL);
  REQUIRE(dynamic_cast<Canonical_Sim*>(sim_plan->sim) != NULL);

  SECTION("dx calculation") {
    REQUIRE(sim_plan->sim->dx[0] == 0.1);
    REQUIRE(sim_plan->sim->dx[1] == 0.2);
    REQUIRE(sim_plan->sim->dx[2] == 0.3);
  }

  const char* yaml_2 =
      "dim: 3\n"
      "dx:  [.1,.2,.3]\n"
      "nx:  [10,10,10]\n";
  input = YAML::Load(yaml_2);

  // Test sim_plan Input
  std::cout.setstate(std::ios_base::failbit);
  sim_plan = Sim_Plan_Factory::New_Sim_Plan(input);
  std::cout.clear();

  REQUIRE(dynamic_cast<Single_Sim_Plan*>(sim_plan) != NULL);
  REQUIRE(dynamic_cast<Canonical_Sim*>(sim_plan->sim) != NULL);

  SECTION("Lx calculation") {
    REQUIRE(sim_plan->sim->Lx[0] == 1);
    REQUIRE(sim_plan->sim->Lx[1] == 2);
    REQUIRE(sim_plan->sim->Lx[2] == 3);
  }

  const char* yaml_3 =
      "dim: 3\n"
      "dx:  [.1,.1,.1]\n"
      "lx:  [0.9,1.0,1.05]\n";
  input = YAML::Load(yaml_3);

  // Test sim_plan Input
  std::cout.setstate(std::ios_base::failbit);
  sim_plan = Sim_Plan_Factory::New_Sim_Plan(input);
  std::cout.clear();

  REQUIRE(dynamic_cast<Single_Sim_Plan*>(sim_plan) != NULL);
  REQUIRE(dynamic_cast<Canonical_Sim*>(sim_plan->sim) != NULL);

  SECTION("Nx calculation") {
    REQUIRE(sim_plan->sim->Nx[0] == 9);
    REQUIRE(sim_plan->sim->Nx[1] == 11);
    REQUIRE(sim_plan->sim->Nx[2] == 11);
  }
}
