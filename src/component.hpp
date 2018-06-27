// component.hpp
//
// Copyright (c) 2018 Ben Lindsay <benjlindsay@gmail.com>

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Eigen/Dense"
#include "globals.hpp"
#include "sim.hpp"

class Sim;

using Eigen::ArrayXcd;  // Dynamically sized complex double Array
using Eigen::ArrayXd;   // Dynamically sized double Array

class Component {
 public:
  Component(Sim *sim) : sim(sim){};
  virtual ~Component(){};
  enum Species_Type { A, B, C, D, E, F, G };
  Sim *sim;
};

class FT_Component : public Component {
 public:
  FT_Component(Sim *sim) : Component(sim){};
  virtual ~FT_Component(){};
  double vol_frac;          // Total volume fraction
  ArrayXcd rho_center;      // Center density distribution
  ArrayXcd rho_center_hat;  // Fourier transform of center density
  ArrayXcd rho;             // Smeared/total density distribution
  ArrayXcd rho_hat;         // Fourier transform of total density
};

#include "component_types/ft_homopolymer.hpp"

#endif  // COMPONENT_HPP