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

int parent[100005], len[100005];
int find(int i){
            if(parent[i]==i){
                return i;
            }
            else{
                return parent[i]=find(parent[i]);
            }
        }

void unite(int u,int v){
    int p1=find(u);
    int p2=find(v);
    if(p1==p2) return;
    if(len[p1]>len[p2]) swap(p1,p2);
    len[p2]+=len[p1];
    parent[p1]=p2;
}


//great imokemenetaion of kruskal



void solve()
{
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,int>> e;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        e.push_back({w,--x,--y});
    }
    sort(e.begin(),e.end());
    for(int i=0;i<n;i++){
        parent[i]=i;
        len[i]=1;
    }
    int ans=0;
    for(auto [w,a,b]:e){
        if(find(a)==find(b)) continue;
        ans+=w;
        unite(a,b);
    }
    int c=0;
    for(int i=0;i<n;i++){
        if(parent[i]==i) c++;
    }
    if(c==1){
        cout<<ans<<endl;
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
    
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