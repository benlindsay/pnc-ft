// main.cpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#include "main.hpp"

int main(int argc, const char *argv[]) {
#ifdef MPI
  // MPI initialization stuff
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &RANK);
  MPI_Comm_size(MPI_COMM_WORLD, &NPROCS);
  fftw_mpi_init();
#else
  RANK = 0;
  NPROCS = 1;
#endif

  std::string input_file_path;
  std::stringstream ss;
  if (argc < 2) {
    // If input file wasn't passed as command line argument,
    // print usage string and exit program
    ss << "Usage: " << argv[0] << " input_file_path";
    utils::die(ss);
  } else {
    input_file_path = argv[1];
    utils::print_one_line("Input file = " + input_file_path);
  }

  // Read input file and check validity of inputs.
  // Information from input file is stored in input_reader object
  YAML::Node input = YAML::LoadFile(input_file_path);
  utils::to_lower(input);

  // Generate simulation plan (series of simulations or just a single
  // simulation) based on input file
  Sim_Plan *sim_plan = Sim_Plan_Factory::New_Sim_Plan(input);

  // Run the simulation or series of simulations
  sim_plan->run();

  delete sim_plan;

#ifdef MPI
  MPI_Finalize();
#endif

  return 0;
}
