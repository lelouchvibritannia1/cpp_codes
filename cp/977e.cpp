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




const int N=1e6+5;
vector<int> g[N];
bool vis[N];
vector<int> com;
int deg[N];
void dfs(int u){
    vis[u]=1;
    com.push_back(u);
    // cout<<u<<" ";
    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    // cout<<endl;
}




void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++deg[u];
        ++deg[v];

    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            com.clear();
            dfs(i);
            bool ok=1;
            for(auto c:com){
                ok = ok&(deg[c]==2);
            }
            ans+=ok;
        }
    }
    cout<<ans<<endl;
}


int32_t main()
{
    init_code();
    int t{1};
//     cin >> t;
    while (t--)
        solve();
}
/*which ends here*/