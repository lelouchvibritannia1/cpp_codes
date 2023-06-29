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

/*this here is code */
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



    void bfs(int s,vector<bool> &visited){
        queue<int> q;
        q.push(s);
        visited[s]=true;

        while(!q.empty()){

            int f=q.front();
            cout<<f<<endl;
            q.pop();

            for(auto v:l[f]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
    }

    void bfsdis(){
        vector<bool> visited(V+1,false);

        for(int i=0;i<V;i++){
            if(visited[i]==false){
                bfs(i,visited);
            }
        }
    }


    void dfsrec(int s,vector<bool> &visited){
        visited[s]=true;
        // cout<<s<<" ";
        for(auto u:l[s]){
            if(visited[u]==false){
                dfsrec(u,visited);
            }
        }
    }

    void dfs(){
        int prev=0;
        int k=0;
        vector<bool> visited(V+1,false);
        vp64 ans;
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                dfsrec(i,visited);
                ans.push_back({prev,i});
                prev=i;
                k++;
            }
        }
        cout<<k-1<<endl;
        for(int i=1;i<k;i++){
            cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
        }
    }
};






void solve(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addedge(u-1,v-1);
    }
    // g.bfsdis();
    g.dfs();
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