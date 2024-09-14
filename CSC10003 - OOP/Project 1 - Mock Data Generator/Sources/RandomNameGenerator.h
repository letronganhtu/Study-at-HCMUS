#include <iostream>
#include <sstream>
using namespace std;

#include "RandomIntegerGenerator.h"

class RandomNameGenerator {
private:
    RandomIntegerGenerator _rng;
public:
    string next();
};