// ft_homopolymer.hpp
//
// Copyright (c) 2018 Ben Lindsay <benjlindsay@gmail.com>

#ifndef FT_HOMOPOLYMER_HPP
#define FT_HOMOPOLYMER_HPP

#include "../component.hpp"

class FT_Homopolymer : public FT_Component {
 public:
  FT_Homopolymer(Sim *sim, int n_segments, Component::Species_Type species);
  virtual ~FT_Homopolymer(){};
  int n_segments;
};

#endif  // FT_HOMOPOLYMER_HPP