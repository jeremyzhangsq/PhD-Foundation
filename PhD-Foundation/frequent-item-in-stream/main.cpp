
#include "lib.h"
using namespace std;


int main() {
    FILE *fp;
    char* file = (char*)"/Users/jeremy/Documents/PhD-Foundation/frequent-item-in-stream/record.txt";
    fp = fopen(file,"r");
    vector<int> data;
    int val;
    while(fscanf(fp,"%d\t",&val)!=EOF){
        data.push_back(val);
    }
    double s = 0.01;
    double epsilon = 0.0001;
    Majority(data);
    vector<int> res;
    vector<int> bf = BruteForce(data, s);
    vector<int> fq = FrequentbyList(data, s);
    vector<int> fq0 = FrequentbyMap(data, s);
    vector<int> ls = Lossy(data,s,epsilon);
    vector<int> ss = SpaceSavingList(data, s);
    vector<int> ssh = SpaceSavingHeap(data, s);
    vector<int> cs = CountSketch(data, 4, (int)(2/s) , s);
    set_intersection(bf.begin(),bf.end(),fq.begin(),fq.end(),back_inserter(res));
    printf("FQ accuracy:%.2f\n",(double)res.size()/bf.size());
    vector<int>().swap(res);
    set_intersection(bf.begin(),bf.end(),fq0.begin(),fq0.end(),back_inserter(res));
    printf("FQ0 accuracy:%.2f\n",(double)res.size()/bf.size());
    vector<int>().swap(res);
    set_intersection(bf.begin(),bf.end(),ls.begin(),ls.end(),back_inserter(res));
    printf("LS accuracy:%.2f\n",(double)res.size()/bf.size());
    vector<int>().swap(res);
    set_intersection(bf.begin(),bf.end(),ss.begin(),ss.end(),back_inserter(res));
    printf("SSL accuracy:%.2f\n",(double)res.size()/bf.size());
    vector<int>().swap(res);
    set_intersection(bf.begin(),bf.end(),ssh.begin(),ssh.end(),back_inserter(res));
    printf("SSH accuracy:%.2f\n",(double)res.size()/bf.size());
    vector<int>().swap(res);
    set_intersection(bf.begin(),bf.end(),cs.begin(),cs.end(),back_inserter(res));
    printf("CS accuracy:%.2f\n",(double)res.size()/bf.size());
    return 0;
}

