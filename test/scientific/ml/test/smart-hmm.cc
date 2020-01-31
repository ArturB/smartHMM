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
    std::cout << "Initializing randomness... " << std::endl;
    srand( time( NULL ) );
    arma::arma_rng::set_seed_random();
    std::cout << "Done!" << std::endl;

    // arma::mat transitions( 2, 2 );
    // transitions << 0.5 << 0.5 << arma::endr << 0.3 << 0.7 << arma::endr;
    // arma::mat emissions( 2, 2 );
    // emissions << 0.3 << 0.7 << arma::endr << 0.8 << 0.2 << arma::endr;
    // scientific::ml::Hmm<char, std::string> h( transitions, emissions, "ne", 0 );
    // std::string example = "nnnnneennn";

    std::cout << "Initializing HMM object... " << std::endl;
    const unsigned NUM_STATES = 40;
    scientific::ml::Hmm<char, std::string> h( NUM_STATES, "artubodzki.g$", 0 );
    std::cout << "Done!" << std::endl;
    arma::mat pi( 1, NUM_STATES );
    pi.fill( 1 / double( NUM_STATES ) );
    std::string example = "artur.brodzki.org$";

    // std::cout << "Initial HMM: " << std::endl;
    // std::cout << h << std::endl;
    // std::cout << "pi = " << pi << std::endl;

    std::cout << "Learning model..." << std::endl;
    for( unsigned i = 0; i < 10; ++i ) {
        auto path = h.find_viterbi_path( example, pi );
        std::cout << "Learn step " << i + 1 << ", " << path
                  << ", prob/char = " << pow( 10, path.prob / example.size() ) << std::endl;
        pi = h.learn( example, pi, 2 );
    }

    // std::cout << "New HMM: " << std::endl;
    // std::cout << h << std::endl;

    for( unsigned k = 0; k < 5; ++k ) {
        std::cout << h.generate_sequence( (char) '$' ) << std::endl;
    }

    return 0;
}
