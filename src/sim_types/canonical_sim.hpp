// canonical_sim.hpp
//
// Copyright (c) 2017 Ben Lindsay <benjlindsay@gmail.com>

#ifndef CANONICAL_SIM_HPP
#define CANONICAL_SIM_HPP

#include "../sim.hpp"
#include "../component.hpp"

class Canonical_Sim : public Sim {
 public:
  Canonical_Sim(YAML::Node input);
  virtual ~Canonical_Sim();
  virtual std::string get_var_as_string(std::string var_name, int str_len);
  virtual void init_default_summary_var_list();
  virtual void init_output_list(YAML::Node input);
  virtual void run(void);

  std::vector<FT_Component*> component_list;
  std::complex<double> calc_hamiltonian();
  void init_component_list(YAML::Node input);
  void update_hamiltonian();
  std::complex<double> hamiltonian;
  std::complex<double> hamiltonian_prev;
  double hamiltonian_err;
  int last_hamiltonian_iter;
};

#endif  // CANONICAL_SIM_HPP
