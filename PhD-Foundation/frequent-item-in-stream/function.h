//
// Created by Jeremy Shiqi Zhang on 2019-08-02.
//

#ifndef FREQUENT_ITEM_IN_STREAM_FUNCTION_H
#define FREQUENT_ITEM_IN_STREAM_FUNCTION_H


#include "lib.h"
using namespace std;

void Majority(vector<int> &arr);
double printRecall(vector<int> &tc, vector<int> &pc);
vector<int> BruteForce(vector<int> &arr, double s);
vector<int> FrequentbyMap(vector<int> &arr, double s);
vector<int> FrequentbyList(vector<int> &arr, double s);
vector<int> SpaceSavingList(vector<int> &arr, double s);
vector<int> SpaceSavingHeap(vector<int> &arr, double s);
vector<int> Lossy(vector<int> &arr, double s, double epsilon);
vector<int> GK(vector<int> &arr, double s, double epsilon);
vector<int> CountSketch(vector<int> &arr, int d, int w, double support, double epsilon);
vector<int> CountMinSketch(vector<int> &arr, int d, int w, double support, double epsilon);

#endif //FREQUENT_ITEM_IN_STREAM_FUNCTION_H
