//
// Created by Jeremy Shiqi Zhang on 2019-08-02.
//

#ifndef FREQUENT_ITEM_IN_STREAM_LIB_H
#define FREQUENT_ITEM_IN_STREAM_LIB_H

#define MOD 2147483647
#define HL 31
#define PI 3.141592653589793
#define KK  17
#define NTAB 32
// following definitions needed for the random number generator
#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)
/* define parameters (R1 and R2 must be smaller than the integer size): */
#define JJ  10
#define R1   5
#define R2   3


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <list>
#include <iterator>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include "group.h"
#include "function.h"
#include "prng.h"


using namespace std;

#endif //FREQUENT_ITEM_IN_STREAM_LIB_H