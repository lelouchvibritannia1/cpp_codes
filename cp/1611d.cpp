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

const int N=2e5+5;
vector<int> graph[N+1];
vector<int> b(N+1);
vector<int> dfs(N+1,0);

void fn(int c,int p){
    dfs[c]=1;
    for(auto x:graph[c]){
        if(x!=p){
            dfs[c]+=1;
            fn(x,c);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    int root=-1;
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]!=i+1){
            graph[i+1].push_back(b[i]);
            graph[b[i]].push_back(i+1);

        }
        else root=i+1;
    }
    unordered_map<int,int> p;
    vector<int> temp(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        p[x]=i+1;
        temp[i]=x;
    }
    vector<int> ans(n,0);
    if(p[root]!=1){ 
        cout<<-1<<endl;
        return;
    }
    else{
        bool ok=true;
        for(int i=0;i<n;i++){
            if(i+1!=root) ok&=p[i+1]>p[b[i]];
        }
        if(!ok){
            cout<<-1<<endl;
            return;
        }
        int prev=root-1;
        for(int i=1;i<n;i++){
            ans[temp[i]-1]+=ans[temp[i-1]-1]+1;
        }
        F(i,0,n){
            cout<<ans[i]-ans[b[i]-1]<<" ";
        } 
        cout<<endl;
    }
}


int32_t main(){
    init_code();
    int t{1};
    cin>>t;
    while(t--) solve();
}
/*which ends here*/

