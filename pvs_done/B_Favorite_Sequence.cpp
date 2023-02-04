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
    ll n;
    cin>>n;
    vector<int> a(n),o(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=n-1;
    bool k=true;
    int i=0;
    while(l<=r){
        if(k){
            o[i++]=a[l++];
            k=!k;
        }
        else{
            o[i++]=a[r--];
            k=!k;
        }
    }
    for(int i=0;i<n;i++){
        cout<<o[i]<<" ";
    }
    cout<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) solve();
}