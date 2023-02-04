#include<bits/stdc++.h>
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


#define G(x) ll x; cin >> x
#define GS(x) string x; cin >> x
#define F(i,l,r) for(ll i=l;i<r;i++)
#define FD(i,r,l) for(ll i=r;i>l;i--)
#define CO(x) cout << x << '\n'
#define CO_(x) cout << x << ' '
#define GA(x,n) ll x[n]; F(i,0,n) cin >> x[i]
#define CA(x,n) F(i,0,n) {CO_(x[i]);} cout << '\n'
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    G(n);
    GA(p,n);
    v64 q(n,0);
    GS(s);
    ll c_0=0,c_1=0;
    F(i,0,n) {
        if(s[i]=='0'){
            c_0++;
        }
        else{
            c_1++;
        }
    }
    if(c_0 == 0 || c_0==n) {CA(p,n);return;}
    v64 less,more;
    F(i,0,n){
        if(s[i]=='0'){
            if(p[i]<=c_0){
                q[i]=p[i];
            }
            else{
                more.push_back(p[i]);
            }
        }
        else{
            if(p[i]>c_0){
                q[i]=p[i];
            }
            else{
                less.push_back(p[i]);
            }
        }
    }
    // CA(less,less.size());
    // CA(more,more.size());
    F(i,0,n){
        if(q[i]!=0){
            continue;
        }
        else{
            if(s[i]=='0'){
                q[i]=less.back();
                less.pop_back();
            }
            else{
                q[i]=more.back();
                more.pop_back();
            }
        }
    }
    CA(q,n);
}


int main(){
    fast_cin();
    ll t;
    cin>>t;
    while(t--) solve();
}
