// **********************************************************************
// Copyright (c) Artur M. Brodzki 2020. All rights reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// **********************************************************************

#ifndef SCIENTIFIC_ML_SMART_HMM_H
#define SCIENTIFIC_ML_SMART_HMM_H

#include <algorithm>
#include <armadillo>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <unordered_map>
#include <vector>

namespace scientific
{
namespace ml
{

template<class E, class S>
class Hmm
{
  public:
    unsigned current_state_;
    arma::mat transitions_;
    arma::mat emissions_;
    S alphabet_;

    unsigned num_states();
    unsigned num_outputs();
    unsigned max_state();
    unsigned max_output();

    unsigned random_element( const arma::mat& );

    E next_state();

  public:
    Hmm( unsigned num_states, const S&, unsigned );
    Hmm( const arma::mat& transitions, const arma::mat& emissions, const S&, unsigned );

    S generate_sequence( unsigned );
    // std::vector<double> find_viterbi_path( const S& sequence, unsigned initial_state );

    template<class E2, class S2>
    friend std::ostream& operator<<( std::ostream&, const Hmm<E2, S2>& );
};

template<class E, class S>
unsigned Hmm<E, S>::num_states()
{
    return transitions_.n_rows;
}

template<class E, class S>
unsigned Hmm<E, S>::num_outputs()
{
    return alphabet_.size();
}

template<class E, class S>
unsigned Hmm<E, S>::max_state()
{
    return transitions_.n_rows - 1;
}

template<class E, class S>
unsigned Hmm<E, S>::max_output()
{
    return alphabet_.size() - 1;
}

template<class E, class S>
unsigned Hmm<E, S>::random_element( const arma::mat& probabilities )
{
    double seed = double( rand() % 1000 ) / 1000;
    unsigned i = 0;
    do {
        seed = seed - probabilities( i );
        if( seed < 0 ) {
            break;
        }
        ++i;
    } while( i < probabilities.n_cols );
    return i;
}

template<class E, class S>
E Hmm<E, S>::next_state()
{
    arma::mat current_transitions =
      transitions_( arma::span( current_state_ ), arma::span( 0, max_state() ) );
    arma::mat current_emissions =
      emissions_( arma::span( current_state_ ), arma::span( 0, max_output() ) );

    current_state_ = random_element( current_transitions );
    return alphabet_[random_element( current_emissions )];
}

template<class E, class S>
Hmm<E, S>::Hmm( unsigned num_states, const S& alphabet, unsigned initial_state )
    : alphabet_( alphabet )
{
    current_state_ = initial_state;
    transitions_.set_size( num_states, num_states );
    transitions_.fill( 1 / double( num_states ) );
    emissions_.set_size( num_states, num_outputs() );
    emissions_.fill( 1 / double( num_outputs() ) );
}

template<class E, class S>
Hmm<E, S>::Hmm( const arma::mat& transitions, const arma::mat& emissions, const S& alphabet,
                unsigned initial_state )
    : current_state_( initial_state )
    , transitions_( transitions )
    , emissions_( emissions )
    , alphabet_( alphabet )
{
}

template<class E, class S>
S Hmm<E, S>::generate_sequence( unsigned sequence_length )
{
    S result;
    for( unsigned i = 0; i < sequence_length; ++i ) {
        result.push_back( next_state() );
    }
    return result;
}

// std::vector<double> find_viterbi_path( const S& sequence, unsigned initial_state )
// {
//     arma::mat pi = transitions_( span( initial_state ), span( 0, max_state() ) );
//     arma::mat t1( num_states(), sequence.size() );
//     arma::mat t2( num_states(), sequence.size() );
// }

template<class E, class S>
std::ostream& operator<<( std::ostream& os, const Hmm<E, S>& h )
{
    os << "Current state: " << std::endl
       << h.current_state_ << std::endl
       << "Transitions: " << std::endl
       << h.transitions_ << std::endl
       << "Emissions: " << std::endl
       << h.emissions_;
    return os;
};

} // namespace ml
} // namespace scientific

#endif // SCIENTIFIC_ML_SMART_HMM_H
