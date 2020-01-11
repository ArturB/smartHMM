#include <algorithm>
#include <armadillo>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <queue>
#include <set>
#include "smart-hmm.h"
#include <sstream>
#include <string>
#include <unistd.h>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace arma;

HMM::HMM( unsigned num_states, string alphabet )
    {
        unsigned num_outputs = alphabet.size();
        transitions_ = randu<mat>( num_states, num_states );
        emissions_ = randu<mat>( num_states, num_outputs );
    }

std::ostream& operator<<( std::ostream& os, const HMM& h )
{
    os << "Transitions: " << endl << h.transitions_ << endl << "Emissions: " << endl << h.emissions_;
    return os;
}
