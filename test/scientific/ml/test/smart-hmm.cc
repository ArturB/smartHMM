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

#include <smart-hmm.h>

int main()
{
    srand( time( NULL ) );
    // arma::mat transitions( 2, 2 );
    // transitions << 0.9 << 0.1 << arma::endr << 0.1 << 0.9 << arma::endr;
    // arma::mat emissions( 2, 4 );
    // emissions << 0.99 << 0.0 << 0.01 << 0.0 << arma::endr << 0.0 << 0.99 << 0.01 << 0.0
    //           << arma::endr;

    // scientific::ml::Hmm<char, std::string> h( transitions, emissions, "abcd", 1 );
    // std::cout << h << std::endl;

    // auto path = h.generate_sequence( (unsigned) 100 );
    // // std::cout << "Sequence generated!" << std::endl;
    // std::cout << "Sequence : " << path.sequence << std::endl;
    // std::cout << "States   : ";
    // for( auto s: path.states ) {
    //     std::cout << s;
    // }
    // std::cout << ", path probability = " << pow( 10, path.prob / path.sequence.size() )
    //           << " per transition" << std::endl;

    // auto path_viterbi = h.find_viterbi_path( path.sequence );
    // // std::cout << "Viterbi path found!" << std::endl;
    // std::cout << "Viterbi  : ";
    // for( unsigned i = 0; i < path_viterbi.sequence.size(); ++i ) {
    //     std::cout << path_viterbi.states[i];
    // }
    // std::cout << ", path probability = " << pow( 10, path_viterbi.prob / path.sequence.size()
    // )
    //           << " per transition" << std::endl;

    arma::arma_rng::set_seed_random();

    arma::mat transitions( 2, 2 );
    transitions << 0.5 << 0.5 << arma::endr << 0.3 << 0.7 << arma::endr;
    arma::mat emissions( 2, 2 );
    emissions << 0.3 << 0.7 << arma::endr << 0.8 << 0.2 << arma::endr;

    scientific::ml::Hmm<char, std::string> h( transitions, emissions, "ne", 0 );
    // scientific::ml::Hmm<char, std::string> h( 2, "artubodzki.g$", 0 );
    arma::mat pi( 1, 2 );
    pi << 0.2 << 0.8 << arma::endr;
    std::cout << "Initial HMM: " << std::endl;
    std::cout << h << std::endl;
    std::cout << "pi = " << pi << std::endl;

    std::string example = "nnnnneennn";
    // std::string example = "artur.brodzki.org$";
    for( unsigned i = 0; i < 1; ++i ) {
        pi = h.learn2( example, pi );
        h.normalize();
        std::cout << "Learn step " << i << ", h = " << h << std::endl;
    }

    // std::cout << "New HMM: " << std::endl;
    // std::cout << h << std::endl;

    // for( unsigned k = 0; k < 5; ++k ) {
    //     auto path = h.generate_sequence( (char) '$' );
    //     std::cout << "Sequence: " << path.sequence << ", states: ";
    //     for( unsigned i = 0; i < path.states.size(); ++i ) {
    //         std::cout << path.states[i] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}
