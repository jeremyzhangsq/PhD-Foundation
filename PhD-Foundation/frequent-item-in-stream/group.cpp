//
// Created by Jeremy Shiqi Zhang on 2019-08-02.
//
#include "lib.h"
using namespace std;

Group::Group(int i,int j){
        delta = i;
        capacity = j;
    }
Group::Group(int i) {
    delta = i;
    capacity = 0;
}

void Group::add(int &i){
    data.insert(i);
}


int heapCompare::operator() (const pair<int,int>& p1, const pair<int,int>& p2)
{
    return p1.second > p2.second;
}
Tuple::Tuple(int val, int o, int d){
    ele = val;
    g = o;
    delta = d;
}
Tuple::Tuple(int val, int d){
    ele = val;
    g = 1;
    delta = d;
}


bool Tuple::operator< (const Tuple &right) const
{
    if(ele==right.ele)
        return delta<=right.delta;
    return ele<right.ele;
}
