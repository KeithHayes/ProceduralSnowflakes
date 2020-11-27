#ifndef RAND_H
#define RAND_H
#include "misc.h"
#include <cstdlib>

class Rand {

private:
    long mSeed;
    float mRand_table[RAND_TABLE_SIZE];
    int mLast_rand_int = RAND_INITIAL_SEED;
    float mLast_rand;

public:
    Rand(void);
    Rand(unsigned long iseed);
    void timeSeed(void);
    void set_table(void);
    long getSeed(void){ return mSeed; };
    float getRand(void);
    float getRand(int);
};

#endif
