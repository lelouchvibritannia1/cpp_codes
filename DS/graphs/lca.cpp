//to do
//lca and shortest path today night
//17: oops, dbms, 15 more questions
//18: oops, dbms, 15 more questions
//19 dday lol

//bruteforce

 #include "bits/stdc++.h"
// #include<iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define int long long int
#define double long double
typedef pair<int,int> p64;
typedef pair<double,double> pdd;
typedef vector<int> v64;
typedef vector<vector<int> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
int MOD = 1e9 + 7;
double eps = 1e-8;
int MAX=1e5;
#define G(x) int x; cin >> x
#define GS(x) string x; cin >> x
#define F(i,l,r) for(int i=l;i<r;i++)
#define FD(i,r,l) for(int i=r;i>l;i--)
#define CO(x) cout << x << '\n'
#define CO_(x) cout << x << ' '
#define GA(x,n) v64 x(n); F(i,0,n) cin >> x[i]
#define CA(x,n) F(i,0,n) {CO_(x[i]);} cout << '\n'
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)



void init_code(){
    fast_cin();
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

}


const int N=1e5+5;
vector<int> gr[N];
int Par[N], dep[N];

void dfs(int cur,int par){
    Par[cur]=par;
    dep[cur]=dep[par]+1;
    for(auto x:gr[cur]){
        if(par!=x){
            dfs(x, cur);
        }
    }
}

int LCA(int u, int v){
    if(u==v) return u;

    if(dep[v]>dep[u]) swap(u,v);
    
    int dif=dep[u]-dep[v];

    while(dif--){
        u=Par[u];
    }

    while(u!=v){
        v=Par[v];
        u=Par[u];
    }

    return u;
}


int32_t main(){
    init_code();
    int n,m;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int f,t;
        cin>>f>>t;
        gr[f].push_back(t);
        gr[t].push_back(f);
    }
    dfs(1,0);

    for(int i=1;i<=n;i++){
        cout<<i<<" "<<dep[i]<<"\n";
    }

    cout<<LCA(9,12)<<"\n";
    cout<<LCA(10,8)<<"\n";
    cout<<LCA(9,11)<<"\n";
}
 