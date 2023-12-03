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



/*this here is code */
const int N=1e5+5, M=20; //log of 1e5
vector<int> graph[N];
int dep[N], Par[N][M];

void dfs(int cur, int par){
    dep[cur]=dep[par]+1;

    Par[cur][0]=par;
    for(int j=1;j<M;j++){
        Par[cur][j] = Par[Par[cur][j-1]][j-1];
    }
    for(auto x:graph[cur]){
        if(x!=par){
            dfs(x,cur);
        }
    }
}

int LCA(int u, int v){
    if(u==v) return v;

    if(dep[u]<dep[v]) swap(u,v);

    int diff = dep[u] -dep[v];

    for(int j=M-1;j>=0;j--){
        if((diff>>j)&&1){
            u=Par[u][j];
        }
    }

    for(int j=M-1;j>=0;j--){
        if(Par[u][j]!=Par[v][j]){
            u=Par[u][j];
            v=Par[v][j];
        }
    }

    return Par[u][0];
}

void solve(){
    int n, m;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int f, t;
        cin >> f >> t;
        graph[f].push_back(t);
        graph[t].push_back(f);
    }
    dfs(1, 0);
    for(int i=1;i<=12;i++){
        cout<<i<<"-> ";
        for(int j=0;j<4;j++){
            cout<<Par[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout << LCA(9, 12) << "\n";
    cout << LCA(10, 8) << "\n";
    cout << LCA(9, 11) << "\n";
}


int32_t main(){
    init_code();
    int t{1};
    // cin>>t;
    while(t--) solve();
}
/*which ends here*/
