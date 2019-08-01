#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <list>
#include <iterator>
#include <algorithm>
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

vector<int> BruteFore(vector<int> &arr, double s){
    unordered_map<int,int> dict;
    for(int val:arr){
        if(dict.count(val))
            dict[val]++;
        else{
            dict.insert(make_pair(val,1));
        }
    }
    printf("Brute Force Result:");
    vector<int> result;
    int k = arr.size()*s;
    for(auto ele:dict){
        if(ele.second>k){
            printf("%d\t",ele.first);
            result.push_back(ele.first);
        }
    }
    printf("\n");
    return result;
}

list<Group>::iterator find(list<Group> &groups,int i){

    list<Group>::iterator g;
    for(g = groups.begin();g!=groups.end();g++){
        if (g->data.count(i))
            return g;
    }
    return groups.end();

}

void decrement(list<Group> &groups){
    auto first = groups.begin();
    for(;first!=groups.end();first++){
        if(first->delta>=1){
            first->delta--;
            if(!first->delta){
                prev(first,1)->capacity=first->data.size();
//                first->data.erase(first->data.begin(),first->data.end());
            }
            return;
        }
    }
}

vector<int> Frequent(vector<int> &arr, double s){
    int m = 1/s-1;
    int k = (int)arr.size()*s;
    int offset = 0;
    list<Group> groups;
    Group g0(0,m);
    Group g1(k-1);
    // insert head and tail into list
    groups.push_back(g0);
    groups.push_back(g1);
    for(int &ele:arr){
        auto g = find(groups,ele);
        // no count represents this element and some counts exist
        if(g==groups.end() and groups.front().delta == 0 and groups.front().capacity){
            auto head = groups.begin();
            head->capacity--;
            head->add(ele);
            g = head;
        }
        // the element is represented by a count
        if(g!=groups.end()){
            auto nxt = next(g,1);
            g->data.erase(ele);
            // move it to next group
            if(nxt==groups.end()){
                Group gc(1);
                gc.add(ele);
                groups.push_back(gc);
            }
            else if(nxt->delta>1) {
                nxt->delta--;
                Group gc(1);
                gc.add(ele);
                groups.insert(nxt, gc);
            }else
                nxt->data.insert(ele);

        }
        // decrement
        else{
            decrement(groups);
            offset++;
        }
    }
    printf("Frequent Counting Result:");
    vector<int> result;
    if(groups.size()>=k+offset){
        for(auto it = next(groups.begin(),k+offset-1);it!=groups.end();it++){
            for(int ele: it->data){
                printf("%d\t",ele);
                result.push_back(ele);
            }
        }
    }
    printf("\n");
    return result;
}

vector<int> Lossy(vector<int> &arr, double s, double epsilon){
    assert(epsilon<s);
    int n = 0;
    int FREQ = 0;
    int DELTA = 1;
    unordered_map<int,int*> T;
    int w;
    if(epsilon==0)
        w = (int)ceil(1/s);
    else
        w = (int)ceil(1/epsilon);
    int bcur = 0;
    for(int &val:arr){
        n++;
        bcur = (int)ceil(n/w);
        if(T.count(val)){
            T[val][FREQ]++;
        }
        else{
            int* tuple = new int[2];
            tuple[FREQ] = 1;
            tuple[DELTA] = bcur-1;
            T.insert(make_pair(val,tuple));
        }
        if(n%w==0){
            for(auto item:T){
                int ele = item.second[FREQ]+item.second[DELTA];
                if(ele<bcur)
                    T.erase(item.first);
            }
        }
    }
    printf("Lossy Counting Result:");
    vector<int> result;
    double k = arr.size()*(s-epsilon);
    for(auto ele:T){
        if(ele.second[FREQ]>k){
            printf("%d\t",ele.first);
            result.push_back(ele.first);
        }

    }
    printf("\n");
    return result;
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
    double s = 0.01;
    double epsilon = 0;
    Majority(data);
    vector<int> res;
    vector<int> bf = BruteFore(data,s);
    vector<int> fq = Frequent(data,s);
    vector<int> ls = Lossy(data,s,epsilon);
    sort(bf.begin(),bf.end());
    sort(fq.begin(),fq.end());
    sort(ls.begin(),ls.end());
    set_intersection(bf.begin(),bf.end(),fq.begin(),fq.end(),back_inserter(res));
    printf("BF accuracy:%.2f\n",(double)res.size()/bf.size());
    vector<int>().swap(res);
    set_intersection(bf.begin(),bf.end(),ls.begin(),ls.end(),back_inserter(res));
    printf("LS accuracy:%.2f\n",(double)res.size()/ls.size());
    return 0;
}

