//very important question atleast
#include "bits/stdc++.h"
// #include<iostream>
#include <cstdint>
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

const int N=1e5+5;
vector<int> g[N];
bool vis[N];
int  nodes;


void dfs(int i){
    vis[i]=1;
    nodes++;
    for(auto v:g[i]){
        if(!vis[v]){
            dfs(v);
        }
    }
}




void solve()
{
    int n,m,cl,cr;
    cin>>n>>m>>cl>>cr;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int cost=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            nodes=0;
            dfs(i);
            cost=cost+cl;
            if(cl>cr){
                cost+=cr*(nodes-1);
            }
            else{
                cost+=cl*(nodes-1);
            }
        }
    }
    cout<<cost<<endl;
    for(int i=0;i<n;i++){
        g[i].clear();
        vis[i]=false;
    }
    
}


int32_t main()
{
    init_code();
    int t{1};
    cin >> t;
    while (t--)
        solve();
}
/*which ends here*/