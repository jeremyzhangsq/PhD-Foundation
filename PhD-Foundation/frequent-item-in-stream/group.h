//
// Created by Jeremy Shiqi Zhang on 2019-08-02.
//


#ifndef FREQUENT_ITEM_IN_STREAM_GROUP_H
#define FREQUENT_ITEM_IN_STREAM_GROUP_H

#include "lib.h"
using namespace std;

class Group{
public:
    int delta;
    int capacity;
    unordered_set<int> data;
    Group(int i,int j);
    Group(int i);
    void add(int &i);
};

class heapCompare
{
public:
    int operator() (const pair<int,int>& p1, const pair<int,int>& p2);
};

class Tuple{
public:
    int ele;
    int g;
    int delta;
    Tuple(int val, int d);
    bool operator< (const Tuple &right) const;

};
#endif //FREQUENT_ITEM_IN_STREAM_GROUP_H
