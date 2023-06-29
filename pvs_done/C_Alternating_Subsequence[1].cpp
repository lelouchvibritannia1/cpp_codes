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
    vector<ll> as(n);
    vector<set<ll,greater<ll>>> v;
    for(ll i=0;i<n;i++){
        cin>>as[i];
    }
    set<ll,greater<ll>> temp;
    temp.insert(as[0]);
    v.push_back(temp);
    ll ans=0;
    ll i=0;
    for(ll j=1;j<n;j++){
        if(as[j]*as[j-1]>0){
            v[i].insert(as[j]);
        }
        else{
            set<ll,greater<ll>> s;
            s.insert(as[j]);
            v.push_back(s);
            i++;
        }
    }
    // cout<<v.size()<<endl;
    for(auto x:v){
        ans+=*x.begin();
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}