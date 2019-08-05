
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
    double s = 0.0102;
    double epsilon = 0.001;
//    Majority(data);
    vector<int> bf = BruteForce(data, s);

    vector<int> fq = FrequentbyList(data, s);
    printf("FQ recall:%.2f\n",printRecall(bf,fq));
    vector<int> fq0 = FrequentbyMap(data, s);
    printf("FQ0 recall:%.2f\n",printRecall(bf,fq0));
    vector<int> ls = Lossy(data,s,epsilon);
    printf("LS recall:%.2f\n",printRecall(bf,ls));
    vector<int> ss = SpaceSavingList(data, s);
    printf("SSL recall:%.2f\n",printRecall(bf,ss));
    vector<int> ssh = SpaceSavingHeap(data, s);
    printf("SSH recall:%.2f\n",printRecall(bf,ssh));
    vector<int> gk = GK(data, s, epsilon);
    printf("GK recall:%.2f\n",printRecall(bf,gk));
    vector<int> cs = CountSketch(data, int(log(4/0.05)), (int)(2/(epsilon*epsilon)), s, epsilon);
    printf("CS recall:%.2f\n",printRecall(bf,cs));
    vector<int> cms = CountMinSketch(data, int(log(4/0.05)), (int)(2/(epsilon*epsilon)), s, epsilon);
    printf("CMS recall:%.2f\n",printRecall(bf,cms));

    return 0;
}

