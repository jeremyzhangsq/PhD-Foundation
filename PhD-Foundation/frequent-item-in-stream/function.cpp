//
// Created by Jeremy Shiqi Zhang on 2019-08-02.
//

#include "lib.h"
using namespace std;

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

vector<int> BruteForce(vector<int> &arr, double s){
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
    sort(result.begin(),result.end());
    return result;
}

/*
 * executing this algorithm with s = ε ensures that the count associated with each item on termination
 * is at most εn below the true value.
 * */
vector<int> FrequentbyMap(vector<int> &arr, double s){
    int m = 1/s-1;
    unordered_map<int,int> dict;
    vector<int> todelete;
    for(int &ele:arr){
        if(dict.count(ele)){
            dict[ele]++;
        }
        else if(dict.size()<m){
            dict.insert(make_pair(ele,1));
        }
        else{
            for(auto &tuple:dict){
                tuple.second--;
                if(!tuple.second)
                    todelete.push_back(tuple.first);
            }
            for(int d:todelete)
                dict.erase(d);
            vector<int>().swap(todelete);
        }
    }

    printf("FrequentbyMap Counting Result:");
    vector<int> result;
    for(auto it:dict){
        printf("%d\t",it.first);
        result.push_back(it.first);
    }
    printf("\n");
    sort(result.begin(),result.end());
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
void groupInit(list<Group> &groups, int &ele, list<Group>::iterator &g) {
    auto head = groups.begin();
    head->capacity--;
    head->add(ele);
    g = head;
}

void groupUpdate(list<Group> &groups, int &ele, list<Group>::iterator &g) {
    auto nxt = next(g, 1);
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
void decrement(list<Group> &groups){
    auto first = groups.begin();
    for(;first!=groups.end();first++){
        if(first->delta>=1){
            first->delta--;
            if(!first->delta){
                prev(first,1)->capacity=first->data.size();
                prev(first,1)->data.erase(prev(first,1)->data.begin(),prev(first,1)->data.end());
                groups.erase(first);
            }
            return;
        }
    }
}


vector<int> FrequentbyList(vector<int> &arr, double s){
    int m = 1/s-1;
    int k = (int)arr.size()*s;
    list<Group> groups;
    Group g0(0,m);
    Group g1(k);
    // insert head and tail into list
    groups.push_back(g0);
    groups.push_back(g1);
    for(int &ele:arr){
        auto g = find(groups,ele);
        // no count represents this element and some counts exist
        if(g==groups.end() and groups.front().delta == 0 and groups.front().capacity){
            groupInit(groups, ele, g);
        }
        // the element is represented by a count
        if(g!=groups.end()){
            groupUpdate(groups, ele, g);

        }
        // decrement
        else{
            decrement(groups);
        }
    }
    printf("FrequentbyList Counting Result:");
    vector<int> result;
    for(auto it = next(groups.begin(),1);it!=groups.end();it++){
        for(int ele: it->data){
            printf("%d\t",ele);
            result.push_back(ele);
        }
    }
    printf("\n");
    sort(result.begin(),result.end());
    return result;
}

void summaryUpdate(list<Group> &groups, int &ele, list<Group>::iterator &g) {
    auto nxt = next(g, 1);
    g->data.erase(ele);
    // move it to next group
    if(nxt==groups.end()){
        Group gc(g->delta+1);
        gc.add(ele);
        groups.push_back(gc);
    }
    else if(nxt->delta-g->delta>1) {
        Group gc(g->delta+1);
        gc.add(ele);
        groups.insert(nxt, gc);
    }else
        nxt->data.insert(ele);
}

void replaceMin(list<Group> &groups, int &ele, unordered_map<int,int> &error){
    auto first = groups.begin();
    for(;first!=groups.end();first++){
        if(first->delta>=1 and !first->data.empty()){
            first->data.erase(first->data.begin());
            error.insert(make_pair(ele,first->delta));
            summaryUpdate(groups,ele,first);
            return;
        }
    }

}

vector<int> SpaceSavingList(vector<int> &arr, double s){
    int m = 1/s;
    int k = (int)arr.size()*s;
    unordered_map<int,int> error;
    list<Group> groups;
    Group g0(0,m);
    Group g1(k);
    // insert head and tail into list
    groups.push_back(g0);
    for(int &ele:arr){
        auto g = find(groups,ele);
        // no count represents this element and some counts exist
        if(g==groups.end() and groups.front().delta == 0 and groups.front().capacity){
            groupInit(groups, ele, g);
            error.insert(make_pair(ele,0));
        }
        // the element is represented by a count
        if(g!=groups.end()){
            summaryUpdate(groups,ele,g);
        }
            // replace val with min count
        else{
            replaceMin(groups,ele,error);
        }
    }
    printf("SpaceSavingList Result:");
    vector<int> result;
    for(auto it = next(groups.begin(),k+1);it!=groups.end();it++){
        Group g = *it;
        for(int ele: it->data){
            if(it->delta-error[ele]>k){
                printf("%d\t",ele);
                result.push_back(ele);
            }
        }
    }
    printf("\n");
    sort(result.begin(),result.end());
    return result;
}


vector<int> SpaceSavingHeap(vector<int> &arr, double s){
    int m = 1/s;
    int CNT = 0;
    int EPS = 1;
    unordered_map<int,int*> dict;
    priority_queue<pair<int,int>,vector<pair<int,int>>,heapCompare> q;
    for(int &ele:arr){
        if(dict.count(ele)){
            int* tuple = dict[ele];
            tuple[CNT]++;
        }
        else if(dict.size()<m){
            int* tuple = new int[2];
            tuple[CNT] = 1;
            tuple[EPS] = 0;
            dict.insert(make_pair(ele,tuple));
            q.push(make_pair(ele,1));
        }
        else{
            // update the priority queue in a lazy manner
            while(1){
                pair<int,int> old = q.top();
                int* cur = dict[old.first];
                if(old.second == cur[CNT])
                    break;
                q.pop();
                old.second = cur[CNT];
                q.push(old);
            }
            pair<int,int> ap = q.top();
            q.pop();
            int* tuple = new int[2];
            tuple[CNT] = ap.second+1;
            tuple[EPS] = ap.second;
            dict.erase(ap.first);
            dict.insert(make_pair(ele,tuple));
            q.push(make_pair(ele,ap.second+1));
        }
    }

    printf("SpaceSavingHeap Counting Result:");
    vector<int> result;
    for(auto it:dict){
        if(it.second[CNT]-it.second[EPS]>m){
            printf("%d\t",it.first);
            result.push_back(it.first);
        }
    }
    printf("\n");
    sort(result.begin(),result.end());
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
    sort(result.begin(),result.end());
    return result;
}

int* getBuckethash(unordered_map<int,int*> &hs, int number, int element){
    if(hs.count(element))
        return hs[element];
    int* result = new int[number];
    return result;
}
int* getCounthash(unordered_map<int,int*> &ss, int number, int element){
    if(ss.count(element))
        return ss[element];
    int* result = new int[number];
    return result;
}
int getMedian(unordered_map<int,int*> &hs, int** C, int ele){
    int* h = hs[ele];
    vector<int> tmp;
    int size = sizeof(C[0])/sizeof(C[0][0]);
    for(int i = 0; i<size; i++){
        tmp.push_back(C[i][h[i]]);
    }
    sort(tmp.begin(),tmp.end());
    if (size % 2 == 0)
        return (tmp[size/2-1]+tmp[size/2])/2;
    else
        return tmp[size/2];

}
vector<int> CountSketch(vector<int> &arr, int t, int b, double support){
    int** C = new int*[t];// t*b matrix for counts
    int* h;
    int* s;
    unordered_map<int,int*> hs;
    unordered_map<int,int*> ss;
    for(int i = 0;i<t;i++){
        C[i] = new int[b];
    }
    for(int& ele:arr){
        h = getBuckethash(hs,t,ele);
        s = getCounthash(ss,t,ele);
        // update count number in given buckets of tables
        for(int i = 0;i<t;i++){
            C[t][h[t]]+=s[t];
        }
    }
    printf("Lossy Counting Result:");
    vector<int> result;
    int element;
    int median;
    int k = (int)(1/support);
    for(auto ele:hs){
        element = ele.first;
        median = getMedian(hs,C,element);
        if(median>k){
            printf("%d\t",element);
            result.push_back(element);
        }
    }
    printf("\n");
    sort(result.begin(),result.end());
    return result;
}