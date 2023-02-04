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
    G(k);
    v64 a(n);
    bool flag=true;;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i!=0 && a[i-1]>a[i]){
            flag=false;
        }
    }

    if(flag || k==n) cout<<0<<endl;
    else if(k==n-1) cout<<1<<endl;
    else if(k==1) cout<<n-1<<endl; 
    else if(n==)
    else{
        if(n%2==0){
        if(a[0]!=1){
            cout<<(n-k)<<endl;
        }
        else{
            cout<<(n-k-1)<<endl;
        }
        }
        else{
            cout<<(n-k)<<endl;
        }
    }


}


int main(){
    fast_cin();
    ll t;
    cin>>t;
    while(t--) solve();
}
