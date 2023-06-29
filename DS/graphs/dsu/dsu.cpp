#include <bits/stdc++.h>
using namespace std;

#define int long long int

class graph{
//   int V;
  vector<int> parent;
  vector<int> rank;
  public:
    
    graph(){
        // this-&gt;V=V;
        parent.resize(100005,-1);
        rank.resize(100005,1);
    }
    int findParent(int i){
        if(parent[i]==-1){
            return i;
        }
        else return parent[i]=findParent(parent[i]);
    }
    
    void union_set(int u,int v){
        int s1=findParent(u);
        int s2=findParent(v);
        
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else{
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }

    }

    

};


class graph2{
    int V;
    list<pair<int,int>> l;

    public: 
    graph2(int V){
        this->V=V;
    }
    void add(int u,int v){
        l.push_back({u,v});
    }

    int find_parent(int i,int parent[]){
        if(parent[i]==-1){
            return i;
        }
        return  parent[i] = find_parent(parent[i],parent);
    }

    void union_set(int x,int y, int parent[], int rank[] ){
        int s1=find_parent(x,parent);
        int s2=find_parent(y,parent);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else{
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }

    bool contains_cycle(){
        //using DSU
        int *parent = new int[V];
        int *rank = new int[V];
        for(int i=0;i<V+1;i++){
            parent[i]=-1;
            rank[i]=1;
        }

        for(auto edge: l){
            int i=edge.first;
            int j=edge.second;

            int s1=find_parent(i,parent);
            int s2=find_parent(j,parent);

            if(s1!=s2){
                union_set(s1,s2,parent,rank);
            }

            else{
                return true;
            }
        }


        delete [] parent;
        delete [] rank;
        return false;

        
    }
};

//2 optimisations : (i) path_compression (ii) union_by_rank


int32_t main(){
    graph g;
    g.union_set(1,0);
    g.union_set(1,3);
    g.union_set(3,2);
    g.union_set(0,3);
    // cout<<g.contains_cycle()<<endl;
} 