#include "rand.h"
#include <QDateTime>

Rand::Rand(void) : mSeed (RAND_INITIAL_SEED)
{
    set_table();
}
Rand::Rand(unsigned long iseed) {
    mSeed = iseed;
    set_table();
}

void Rand::timeSeed(void) {
    mSeed = QDateTime::currentMSecsSinceEpoch()/1000;
    set_table();
}

void Rand::set_table(void) {
    int i = 0;
    std::srand(mSeed);
    for (; i<RAND_TABLE_SIZE; i++) { mRand_table[i]=rand()/(RAND_MAX+1.0); }
    mLast_rand_int = mRand_table[--i];
    mLast_rand = (mLast_rand_int = rand())/(RAND_MAX+1.0);
}

float Rand::getRand(void) {
  int index = RAND_TABLE_SIZE*mLast_rand;
  mLast_rand = mRand_table[index];
  mRand_table[index] = (mLast_rand_int = rand())/(RAND_MAX+1.0);
  return mLast_rand;
}
float Rand::getRand(int n) { return n*getRand(); }
