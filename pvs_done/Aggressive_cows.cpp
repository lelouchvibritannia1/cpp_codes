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

#define loop(i,k,n) for(ll i=k;i<n;i++)
#define loopr(i,k,n) for(ll i=n-1;i>=k;i--)
#define loopeq(i,k,n) for(ll i=k;i<=n;i++)
#define first fi
#define second se
#define all(x) (x).begin(),(x).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ln '\n' 

bool check(v64 a,ll n,ll k,ll c){
   ll cnt=1;
   ll last=a[0];
   loop(i,0,n){
    if((a[i]-last) >= k){
        cnt++;
        if(cnt==c) return true;
        last=a[i];
    }
   }
   return false;
}
void solve(){
    ll n,c;
    cin>>n>>c;
    v64 a(n);
    loop(i,0,n){cin>>a[i]; }
    sort(a.begin(),a.end());
    // for(auto x:a) cout<<x<<endl;
    ll l=1,h=a[n-1];
    ll res=-1;
    while(l<=h){
        ll m=l+(h-l)/2;
        if(check(a,n,m,c)){
            res=m;
            l=m+1;
        }
        else{
            h=m-1;
        }
        // cout<<1<<endl;
    }
    cout<<res<<endl;
}


int main(){
    fast_cin();
    ll t;
    cin>>t;
    while(t--) solve();
}