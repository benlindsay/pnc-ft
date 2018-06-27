// ft_homopolymer.cpp
//
// Copyright (c) 2018 Ben Lindsay <benjlindsay@gmail.com>

#include "ft_homopolymer.hpp"

FT_Homopolymer::FT_Homopolymer(Sim *sim, int _n_segments,
                               Component::Species_Type species)
    : FT_Component(sim) {
  n_segments = _n_segments;
}