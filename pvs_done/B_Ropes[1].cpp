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

#define loop(i,k,n) for(int i=k;i<n;i++)
#define loopr(i,k,n) for(int i=n-1;i>=k;i--)
#define loopeq(i,k,n) for(int i=k;i<=n;i++)
#define first fi
#define second se
#define all(x) (x).begin(),(x).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ln '\n' 

bool check(v64& a,double x,ll k){
    ll pieces=0;
    loop(i,0,a.size()){
        pieces+=(a[i]/x);
    }
    return pieces>=k;
}

int main(){
    fast_cin();
    ll n,k;
    cin>>n>>k;
    v64 arr(n);
    loop(i,0,n) cin>>arr[i];
    sort(arr.begin(),arr.end());
    double l=0.0,r=1.0;
    while(check(arr,r,k)) r*=2.0;
    loop(i,0,100){
        double m=l+(r-l)/2;
        if(check(arr,m,k)){
            l=m;
        }
        else{
            r=m;
        }
    }
    cout<<setprecision(20)<<l<<ln;
}