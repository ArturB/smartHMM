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

    std::cout << "Initializing HMM object... " << std::endl;
    const unsigned NUM_STATES = 8;
    const unsigned TRAIN_SIZE = 30000000;
    const unsigned TEST_SIZE = 2000000;
    const double LEARN_RATE = 0.0001;
    const double REJECT_THRESHOLD = -1;

    std::string alphabet = "():/<>%_1234567890abcdefghijklmnopqrstuvwxyz.-$";

    scientific::ml::Hmm<char, std::string> h( NUM_STATES, alphabet );
    std::cout << "Done!" << std::endl;
    std::cout << "Learning model..." << std::endl;

    // Learning
    std::ifstream dataset_file( "data/rb-domains.log" );
    std::string line;
    unsigned processed_lines = 0;
    std::cout.imbue( std::locale( "" ) );

    while( getline( dataset_file, line ) && processed_lines < TRAIN_SIZE ) {
        if( line.size() < 4 ) {
            continue;
        }
        h.learn( line + "$", LEARN_RATE, false );
        ++processed_lines;
        if( processed_lines % 1024 == 0 ) {
            h.update( LEARN_RATE );
            std::cout << "\rProcessed lines: " << processed_lines << "    " << std::flush;
        }
    }

    // Testing valid class
    std::cout << "Testing model..." << std::endl;
    std::cout << "Non-malicious class: " << std::endl;
    processed_lines = 0;
    double score_sum = 0;
    double min_score = 10;
    unsigned false_positive = 0;

    while( getline( dataset_file, line ) && processed_lines < TEST_SIZE ) {
        auto path = h.find_viterbi_path( line + "$" );
        double score = ( path.prob / line.size() ) + log10( alphabet.size() );

        score_sum += score;
        min_score = std::min( min_score, score );
        if( score < REJECT_THRESHOLD ) {
            ++false_positive;
        }

        ++processed_lines;
        if( processed_lines % 253 == 0 ) {
            std::cout << "\rProcessed lines: " << processed_lines << "    " << std::flush;
        }
    }

    std::cout << "Valid class: avg score = " << score_sum / TEST_SIZE
              << ", min score = " << min_score
              << ", false positives = " << double( false_positive ) / TEST_SIZE << std::endl;

    // Testing malicious class
    std::cout << std::endl;
    std::cout << "Malicious class: " << std::endl;
    auto path = h.find_viterbi_path( "4lkn54lk35n3l4k.best-malware.com$" );
    std::cout << path << ", prob/char = " << path.prob / line.size() + log10( alphabet.size() )
              << std::endl;
    path = h.find_viterbi_path( "y7n6klyn.best-malware.com$" );
    std::cout << path << ", prob/char = " << path.prob / line.size() + log10( alphabet.size() )
              << std::endl;
    path = h.find_viterbi_path( "f5l4tklmgl5k4mygklm.best-malware.com$" );
    std::cout << path << ", prob/char = " << path.prob / line.size() + log10( alphabet.size() )
              << std::endl;
    path = h.find_viterbi_path( "6nm5lktn5k4ynt.best-malware.com$" );
    std::cout << path << ", prob/char = " << path.prob / line.size() + log10( alphabet.size() )
              << std::endl;
    path = h.find_viterbi_path( "6nmtlkgnmmn56.best-malware.com$" );
    std::cout << path << ", prob/char = " << path.prob / line.size() + log10( alphabet.size() )
              << std::endl;
    path = h.find_viterbi_path( "6mklghml56mgh.best-malware.com$" );
    std::cout << path << ", prob/char = " << path.prob / line.size() + log10( alphabet.size() )
              << std::endl;
    path = h.find_viterbi_path( "6nmylkynm66n6.best-malware.com$" );
    std::cout << path << ", prob/char = " << path.prob / line.size() + log10( alphabet.size() )
              << std::endl;
    path = h.find_viterbi_path( "vm6y65ln65y.best-malware.com$" );
    std::cout << path << ", prob/char = " << path.prob / line.size() + log10( alphabet.size() )
              << std::endl;
    path = h.find_viterbi_path( "vmlk6mn5yl65nn65hgnk.best-malware.com$" );
    std::cout << path << ", prob/char = " << path.prob / line.size() + log10( alphabet.size() )
              << std::endl;
    path = h.find_viterbi_path( "6mygklmnl6yk5.best-malware.com$" );
    std::cout << path << ", prob/char = " << path.prob / line.size() + log10( alphabet.size() )
              << std::endl;

    return 0;
}
