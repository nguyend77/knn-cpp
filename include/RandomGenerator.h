#ifndef __RANDOMGENERATOR__
#define __RANDOMGENERATOR__

#include <random>
using namespace std;

class RandomGenerator {
    private:
        random_device rd;
        mt19937 gen;
    public:
        RandomGenerator();
        int getInt(int min, int max);
};

#endif
