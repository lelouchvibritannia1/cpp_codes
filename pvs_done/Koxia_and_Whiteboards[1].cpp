#include<bits/stdc++.h>
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
 
#define first fi
#define second se
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;i<(n);(i)++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ln '\n' 

void solve(){
    ll N,K;
    cin>>N>>K;
    ll ans=0;
    v64 A(N);
    v64 B(K);
    rep(i,N) cin>>A[i];
    sort(A.begin(),A.end())
    rep(i,K){
         cin>>B[i];
    }
    
}

int main(){
    fast_cin();
    ll T;
    cin>>T;
    while(T--) solve();
}
