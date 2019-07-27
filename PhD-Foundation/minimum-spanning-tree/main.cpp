#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Edge{
public:
    int u;
    int v;
    int w;
    Edge(int s, int t, int l){
        u = s;
        v = t;
        w = l;
    }
};
class Graph{
public:
    int n; // vertex number
    int m; // edge number
    unordered_map<int, vector<Edge*>> graph; // adjacent list

    Graph(int a, int b){
        n = a;
        m = 0;
        while(m<b){
            int s = m%n;
            int t = rand()%n;
            if(s==t)
                continue;
            int w = rand()%b;
            addEdge(s,t,w);
            m++;
        }

    }

    void checkPoint(int u, Edge *e){
        auto iter = graph.find(u);
        if(iter == graph.end()){
            vector<Edge*> edges;
            edges.reserve(n);
            graph.insert(make_pair(u,edges));
            iter = graph.find(u);
        }

        iter->second.push_back(e);
    }
    void addEdge(int u, int v, int w){
        Edge* e = new Edge(u,v,w);
        checkPoint(u,e);
    }


};
int main() {
    srand((unsigned) time(NULL));
    Graph graph(5,10);
    return 0;
}