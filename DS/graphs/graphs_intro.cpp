#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
    int V;
    list<int> *l;

    public:
    Graph(int v){
        V=v;
        l=new list<int>[V];
    }

    void addedge(int i,int j,bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void printAdj(){
        for(int i=0;i<V;i++){
            cout<<i<<" -> ";

            for(auto node:l[i]){
                cout<<node<<" ";
            }

            cout<<endl;
        }
    }
};

int32_t  main(){
    Graph g(7);

    g.addedge(1,2);
    g.addedge(1,4);
    g.addedge(1,3);
    g.addedge(4,6);

    g.printAdj();
}