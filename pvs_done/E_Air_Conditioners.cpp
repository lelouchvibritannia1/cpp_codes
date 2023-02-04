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

void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[k];
    ll t[k];
    ll temp[n];
    for(ll i=0;i<k;i++){
        cin>>a[i];
    }
    for(ll i=0;i<k;i++){
        cin>>t[i];
    }
    ll mini=INT64_MAX;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<k;j++){
            mini=min(mini,(t[k]+abs(a[k]-i)));
        } 
        temp[i]=mini;   
    }

    for(ll i=0;i<n;i++){
        cout<<temp[i]<<" ";
    }

    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) { solve();}
}