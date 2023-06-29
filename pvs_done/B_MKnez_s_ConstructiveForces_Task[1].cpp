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


void solve(){
    ll n;
    cin>>n;
    if(n==3) {cout<<"NO"<<endl; return;}
    if(n%2==0){
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++){
            if(i%2) cout<<1<<" ";
            else cout<<-1<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"YES"<<endl;
        ll c=(n-3)/2;
        for(ll i=1;i<=n;i++){
            if(i%2) cout<<c<<" ";
            else cout<<-(c+1)<<" ";
        }
        cout<<endl;
        // c++;
    }
}


int main(){
    fast_cin();
    ll t;
    cin>>t;
    while(t--) solve();
}