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
    scientific::ml::Hmm<char, std::string> h( 2, "artubodzki.g$", 0 );
    arma::mat pi( 1, 2 );
    pi.fill( 0.1 );
    std::cout << "Initial HMM: " << std::endl;
    std::cout << h << std::endl;

    for( unsigned k = 0; k < 5; ++k ) {
        pi = h.learn( "artur.brodzki.org$", pi );
        std::cout << "Learn step " << k + 1 << ", emissions = " << h << std::endl;
    }

    std::cout << "New HMM: " << std::endl;
    std::cout << h << std::endl;

    for( unsigned k = 0; k < 5; ++k ) {
        auto path = h.generate_sequence( (char) '$' );
        std::cout << "Sequence: " << path.sequence << ", states: ";
        for( unsigned i = 0; i < path.states.size(); ++i ) {
            std::cout << path.states[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
