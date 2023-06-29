#include <bits/stdc++.h>
#include<iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef stack<ll> s64;
typedef stack<int> s32;
typedef stack<pair<int,int>> sp32;
typedef unordered_map<int,int> ump32;
ll MOD = 1e9 + 7;
double eps = 1e-8;
ll MAX=1e5;


#define G(x) ll x; cin >> x
#define GS(x) string x; cin >> x
#define F(i,l,r) for(ll i=l;i<r;i++)
#define FD(i,r,l) for(ll i=r;i>l;i--)
#define CO(x) cout << x << '\n'
#define CO_(x) cout << x << ' '
#define GA(x,n) ll x[n]; F(i,0,n) cin >> x[i]
#define CA(x,n) F(i,0,n) {CO_(x[i]);} cout << '\n'
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<bool> prime(MAX,true);
void sieve(){
    prime[0]=prime[1]=false;
    for(int i=2;i*i<MAX;i++){
        if(prime[i]){
            for(int j=i*i;j<MAX;j+=i){
                prime[j]=false;
            }
        }
    }
}

void init_code(){
    fast_cin();
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
}

 /*here is the code boys*/
int k=0;
vector<int> ans;

bool bfs(vector<int> adj[],int s,vector<int> &vis,int V){
    ans={};
    vis[s]=true;
    queue<int> q;
    q.push(s);
    vector<int> parent(V,-1);
    while(!q.empty()){

        int u=q.front();
        q.pop();
        ans.push_back(u);

        for(auto &v:adj[u]){
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
                ans.push_back(v);
                k++;
                parent[v]=u;
            }
            else{
                if(v!=parent[u]){
                    ans.push_back(v);
                    k++;
                    return true;
                    
                }
                else{
                    
                    return false;
                }
            }
        }

    }
    
    return false;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    vector<int> vis(n,false);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(bfs(adj,i,vis,n)){
                cout<<k<<endl;
                for(int j=0;j<ans.size();j++){
                    cout<<ans[j]+1<<" ";
                }
                cout<<"\n";
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<"\n";
}


int main(){
    init_code();
    ll t{1};
    // cin>>t;
    while(t--) solve();
}

/*the code ends here.*/