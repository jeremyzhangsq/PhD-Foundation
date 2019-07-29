//
// Created by Jeremy Shiqi Zhang on 2019-07-29.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

class Edge{
public:
    int v;
    int w;
    Edge(int t, int l){
        v = t;
        w = l;
    }
};

class Graph{
public:
    int n; // vertex number
    int m; // edge number
    vector<int> vertex;
    vector<vector<Edge*>> graph; // adjacent list

    Graph(int a, int b){
        n = a;
        m = 0;
        vertex.reserve(a);
        vector<vector<Edge*>> matrix(n, vector<Edge*>());
        graph = matrix;
        while(m<b){
            int s = rand()%n;
            int t = rand()%n;
            if(s==t)
                continue;
            int w = rand()%b;
            if(m<n){
                vertex.push_back(m);
                graph[m].reserve(n);
            }
            addEdge(s,t,w);
        }
    }

    bool add(int s, int t, int w){
        bool has = false;
        for(int i = 0;i<graph[s].size();i++){
            Edge* e = graph[s][i];
            if(e->v==t)
                has = true;
        }
        if(!has)
            graph[s].push_back(new Edge(t,w));
        return has;
    }
    void addEdge(int s, int t, int w){
       bool has = add(s,t,w);
       add(t,s,w);
       if (!has){
//           printf("(%d,%d,%d)\t",s,t,w);
           m++;
       }

    }

};

class heapCompare
{
public:
    int operator() (const pair<int,int>& p1, const pair<int,int>& p2)
    {
        return p1.second > p2.second;
    }
};

void prim(Graph &g){
    unordered_map<int,int> keys;
    unordered_map<int,int> parents;
    unordered_set<int> mst;
    priority_queue<pair<int,int>,vector<pair<int,int>>,heapCompare> q;
    int s = *(g.vertex.begin());
    for(int node: g.vertex){
        keys.insert(make_pair(node,100000));
        parents.insert(make_pair(node,-1));
    }
    keys[s]=0;
    parents[s]=s;
    q.push(make_pair(s,0));
    while (!q.empty()){
        pair<int,int> node = q.top();
        q.pop();
        mst.insert(node.first);
        for(Edge* edge:g.graph[node.first]){
            int neighbor = edge->v;
            int weight = edge->w;

            if(!mst.count(neighbor) and keys[neighbor]>weight){
                parents[neighbor] = node.first;
                keys[neighbor] = weight;
                q.push(make_pair(neighbor,weight));
            }
        }
    }

    // print out
    for(int u:mst){
        if(u!=parents[u]){
            printf("(%d,%d)\t",parents[u],u);
        }
    }

}

int main(int argc, char* argv[]) {
//    srand((unsigned) time(NULL));
    srand(1);
    int n = stoi(argv[1]);
    int m = stoi(argv[2]);
    Graph graph(n,m);
    prim(graph);
    return 0;
}