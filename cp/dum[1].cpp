
#include "bits/stdc++.h"
// #include<iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define int long long int
#define double long double
typedef pair<int, int> p64;
typedef pair<double, double> pdd;
typedef vector<int> v64;
typedef vector<vector<int>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
int MOD = 1e9 + 7;
double eps = 1e-8;
int MAX = 1e5;
#define G(x) \
    int x;   \
    cin >> x
#define GS(x) \
    string x; \
    cin >> x
#define F(i, l, r) for (int i = l; i < r; i++)
#define FD(i, r, l) for (int i = r; i > l; i--)
#define CO(x) cout << x << '\n'
#define CO_(x) cout << x << ' '
#define GA(x, n) \
    v64 x(n);    \
    F(i, 0, n)   \
    cin >> x[i]
#define CA(x, n)   \
    F(i, 0, n)     \
    {              \
        CO_(x[i]); \
    }              \
    cout << '\n'
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void init_code()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
}



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


    void bfs(int s){ //bfs with source
        queue<int> q;
        vector<bool> visited(V,false);

        q.push(s);
        visited[s]=true;

        while(!q.empty()){
            int f=q.front();
            cout<<f<<endl;
            q.pop();

            for(auto child:l[f]){
                if(!visited[child]){
                    q.push(child);
                    visited[child]=true;
                }
            }
        }
    }



    bool bfs(int s,vector<bool> &visited){
        queue<int> q;
        q.push(s);
        visited[s]=true;
        int ver=1;
        int edg=0;
        vector<bool> done(V+1,false);
        while(!q.empty()){

            int f=q.front();
            // cout<<f<<endl;
            q.pop();

            for(auto v:l[f]){
                if(!done[v]){
                    edg++;
                }
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                    ver++;
                }
            }
            done[f]=true;
        }

        return (ver==edg);
    }

    void bfsdis(){
        vector<bool> visited(V+1,false);
        bool ok=true;
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                ok&=bfs(i,visited);
            }
        }

        if(ok){
            cout<<"Yes\n"<<endl;
        }
        else{
            cout<<"No\n";
        }
    }


    void dfs(){}
};


/*this here is code */

void solve(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g.addedge(v1,v2);
    }
    g.bfsdis();
    
}



int32_t main()
{
    init_code();
    int t{1};
    // cin >> t;
    while (t--)
        solve();
}
/*which ends here*/