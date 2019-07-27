#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    vector<int> vertex;
    vector<Edge*> edges;
    unordered_map<int, vector<Edge*>> graph; // adjacent list

    Graph(int a, int b){
        n = a;
        m = 0;
        vertex.reserve(a);
        edges.reserve(b);
        while(m<b){
            int s = rand()%n;
            int t = rand()%n;
            if(s==t)
                continue;
            int w = rand()%b;
            if(m<n){
                vertex.push_back(m);
            }
            addEdge(s,t,w);
            m++;
        }

    }

    void checkPoint(int u, Edge *e){
        auto iter = graph.find(u);
        if(iter == graph.end()){
            vector<Edge*> edges;
            edges.reserve(n);
            edges.push_back(e);
            graph.insert(make_pair(u,edges));
        }
        else{
            iter->second.push_back(e);
        }
        edges.push_back(e);
    }
    void addEdge(int u, int v, int w){
        Edge* e = new Edge(u,v,w);
        checkPoint(u,e);
    }


};

class Ptr;

class Node{
public:
    int val;
    Ptr* pre;
    Node* next;
    Node(int a){
        val = a;
        pre = nullptr;
        next = nullptr;
    }
    Node(int a, Node* reprsnt){
        val = a;
        next = reprsnt;
    }
};

bool cpEdge(const Edge* res1, const Edge* res2){
    return res1->w < res2->w;

}
class Ptr{
public:
    Node *head;
    Node *tail;
    int weight; // heuristic weight: every time merge small to large
    Ptr(Node* reprsnt){
        head = new Node(-1,reprsnt);
        tail = new Node(-1,reprsnt);
    }
};

// use linked list to implement disjoint set data structure
class setBylist{
public:
    Ptr* makeSet(Node* a){
        Ptr *ptr = new Ptr(a);
        a->pre = ptr;
        ptr->head->next = a;
        ptr->tail->next = a;
        ptr->weight = 1;
        a->next = nullptr;
        return ptr;
    }

    Ptr* findSet(Node* a){
        return a->pre;
    }

    Ptr* unionSet(Ptr* p1, Ptr* p2){
        Ptr* a;
        Ptr* b;
        if(p1->weight>=p2->weight){
            a = p1;
            b = p2;
        }
        else{
            a = p2;
            b = p1;
        }

        a->weight += b->weight;
        Node* first = b->head->next;
        Node* end = b->tail->next;
        for(Node* node = first; node!= nullptr;node = node->next){
            node->pre = a;
        }
        a->tail->next->next = first;
        a->tail->next = end;

        return a;
    }

};

class setBytree{

};

void printMST(Ptr* ptr){
    Node* head = ptr->head;
    for(Node* node = head->next;node!=nullptr;node = node->next){
        printf("%d\t",node->val);
    }
    printf("\n");
}
void Kruskal(Graph &g){

    setBylist util;
    vector<Ptr*> ptrs(g.n);
    vector<Node*> nodes(g.n);
    // make set for every vertex
    for(int val:g.vertex){
        Node *node = new Node(val);
        ptrs[val] = util.makeSet(node);
        nodes[val] = node;
    }
    // sort edges by weight ascendingly
    sort(g.edges.begin(),g.edges.end(),cpEdge);

    // traversal all edges and do union-set()
    Ptr* final;
    for(Edge* e: g.edges){
        Node* u = nodes[e->u];
        Node* v = nodes[e->v];
        if(u->pre != v->pre){
            final = util.unionSet(util.findSet(u),util.findSet(v));
            printMST(final);
        }
    }

}

int main() {
//    srand((unsigned) time(NULL));
    srand(1);
    Graph graph(5,10);
    Kruskal(graph);
    return 0;
}