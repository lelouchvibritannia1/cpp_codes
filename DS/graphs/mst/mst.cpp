#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<pair<int,int>> *l;
    int V;

    public:
        Graph(int V){
            this->V=V;
            l = new vector<pair<int,int>> [V+1];
        }

        void add_edge(int x,int y,int w){
            l[x].push_back({y,w});
            l[y].push_back({x,w});
            
        }

        int prim_mst(){

            priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

            bool *vis = new bool[V+1]{0};
            int ans=0;

            pq.push({0,0}); //dummy {weight,node} as pairs are compared based on the first value

            while(!pq.empty()){
                auto best = pq.top();
                pq.pop();

                int to=best.second;
                int weight=best.first;

                if(vis[to]){
                    continue;
                }

                ans+=weight;
                vis[to]=1;

                for(auto x:l[to]){
                    if(vis[x.first]==0){
                        pq.push({x.second,x.first});
                    }
                }
            }
            return ans;
        }


};




//Kruskal

class DSU{
    vector<int> parent;
    vector<int> rank;

    public:
        DSU(int n){
            parent.resize(n+1,-1);
            rank.resize(n+1,1);
        }

        int find(int i){
            if(parent[i]==-1){
                return i;
            }
            else{
                return parent[i]=find(parent[i]);
            }
        }

        void unite(int u,int v){
            int p1=find(u);
            int p2=find(v);

            if(p1!=p2){
                if(rank[p1]>=rank[p2]){
                    parent[p2]=p1;
                    rank[p1]+=rank[p2];
                }            
                else{   
                    parent[p1]=p2;
                    rank[p2]+=rank[p1];
                }   
            }
        }

};



class Graph_2{
    int V;
    vector<vector<int>> edgelist;

    public:
        Graph_2(int V){
            this->V=V;
        }

        void add_edge(int x,int y, int w){
            edgelist.push_back({w,x,y});
        }


        int kruskal_mst(){

            sort(edgelist.begin(),edgelist.end());

            DSU s(V);

            int ans=0;
            for(auto edge:edgelist){
                int w=edge[0];
                int x=edge[1];
                int y=edge[2];

                if(s.find(x)!=s.find(y)){
                    s.unite(x,y);
                    ans+=w;
                }

            }

            return ans;
        }

};







int main(){
    int n,m;
    cin>>n>>m;
    Graph_2 g(n);
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g.add_edge(x-1,y-1,w);
    }

    cout<<g.kruskal_mst()<<endl;
    
}