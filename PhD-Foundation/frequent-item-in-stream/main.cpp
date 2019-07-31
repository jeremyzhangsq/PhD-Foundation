#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <list>
#include <iterator>
#include <unordered_set>

using namespace std;

class Group{
public:
    int delta;
    int capacity;
    unordered_set<int> data;
    Group(int i,int j){
        delta = i;
        capacity = j;
    }
    Group(int i){
        delta = i;
        capacity = 0;
    }
    void add(int &i){
        data.insert(i);
    }
    int get(int &i){
        return *(data.find(i));
    }
};
void Majority(vector<int> &arr){
    int count=0;
    int majority=0;
    for(int val:arr){
        if(val==majority)
            count++;
        else{
            if (count){
                count--;
            }
            else{
                count = 1;
                majority = val;
            }
        }
    }
    count = 0;
    for(int val:arr){
        if(val==majority)
            count++;
    }

    majority = (float)count/arr.size()>=0.5 ? majority : -1;
    printf("majority: %d\n",majority);

}

void BruteFore(vector<int> &arr, int k){
    unordered_map<int,int> dict;
    for(int val:arr){
        if(dict.count(val))
            dict[val]++;
        else{
            dict.insert(make_pair(val,1));
        }
    }
    printf("Brute Force Result:");
    for(auto ele:dict){
        if(ele.second>k)
            printf("%d\t",ele.first);
    }
    printf("\n");
}

list<Group>::iterator find(list<Group> &groups,int i){

    list<Group>::iterator g;
    for(g = groups.begin();g!=groups.end();g++){
        if (g->data.count(i))
            return g;
    }
    return groups.end();

}

void Frequent(vector<int> &arr, int k){
    int m = arr.size()/k-1;
    list<Group> groups;
    Group g0(0,m);
    Group g1(1);
    // insert head and tail into list
    groups.push_back(g0);
    groups.push_back(g1);
    for(int &ele:arr){
        auto g = find(groups,ele);
        // no count represents this element and some counts exist
        if(g==groups.end() and groups.front().delta == 0 and groups.front().capacity){
            auto head = groups.begin();
            head->capacity--;
            auto nxt = next(head,1);
            nxt->add(ele);
        }
        // the element is represented by a count
        else if(g!=groups.end()){
            g->data.erase(ele);
            auto nxt = next(g,1);
            // move it to next group
            if(nxt == groups.end()){
                Group gc(1);
                gc.add(ele);
                groups.push_back(gc);

            }else
                nxt->data.insert(ele);

        }
        // decrement
        else{
            auto first = groups.begin();
            for(;first!=groups.end();first++){
                if(first->delta>=1){
                    first->delta--;
                    first->capacity=first->data.size();
                    groups.erase(prev(first,1));
                    return;
                }
            }
        }
    }
    printf("Frequent Counting Result:");
    for(auto it = next(groups.begin(),k);it!=groups.end();it++){
        for(int ele: it->data){
            printf("%d\t",ele);
        }
    }
    printf("\n");
}


int main() {
    FILE *fp;
    char* file = "/Users/jeremy/Documents/PhD-Foundation/frequent-item-in-stream/record.txt";
    fp = fopen(file,"r");
    vector<int> data;
    int val;
    while(fscanf(fp,"%d\t",&val)!=EOF){
        data.push_back(val);
    }
    Majority(data);
    BruteFore(data,8);
    Frequent(data,8);
    return 0;
}

