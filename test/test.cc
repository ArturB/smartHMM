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

#include <smart-hmm>

int main()
{
    srand( time( NULL ) );
    arma::mat transitions( 2, 2 );
    transitions << 0.8 << 0.2 << arma::endr << 0.2 << 0.8 << arma::endr;
    arma::mat emissions( 2, 4 );
    emissions << 1.0 << 0.0 << 0.0 << 0.0 << arma::endr << 0.0 << 1.0 << 0.0 << 0.0
              << arma::endr;

    scientific::ml::Hmm<char, std::string> h( 5, "abcd", 0 );
    std::cout << h << std::endl;
    std::string seq = h.generate_sequence( 100 );
    std::cout << "Sequence: " << seq << std::endl;
}
