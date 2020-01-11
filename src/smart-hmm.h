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
#include <sstream>
#include <string>
#include <unistd.h>
#include <unordered_map>
#include <vector>

class HMM
{
  private:
    arma::mat transitions_;
    arma::mat emissions_;

  public:
    HMM( unsigned num_states, std::string alphabet );

    friend std::ostream& operator<<( std::ostream& os, const HMM& h );
};
