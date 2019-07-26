#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    srand((unsigned)(time(NULL)));
    string name = "/Users/jeremy/Documents/PhD-Foundation/reservoir-random-sampling/" + string(argv[1]);
    int n = stoi(argv[2]);
    int current;
    int reservoir[n];
    int t = 0;
    FILE* fp;
    fp = fopen(name.c_str(),"r");
    while (fscanf(fp, "%d\t", &current) != EOF){
        if(t<n)
            reservoir[t] = current;
        else{
            // generate a random int from [m,n]: rand()%(n - m + 1) + m
            int r = rand()%(t+1);
            if (r<n) {
                reservoir[r] = current;
            }
        }
        t++;
    }
    fclose(fp);
    for(int i:reservoir)
        printf("%d\n",i);
    return 0;
}