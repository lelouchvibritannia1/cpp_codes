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

v64 construct(ll f,ll k){
    v64 c(k);
    loop(i,0,k){
        if(i<f-1) c[i]=i+2;
        else c[i]=1;
    }
    return c;
}

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    string s2;
    bool flag=false;
    for(int i=0;i<n-2;i++){
        s2.push_back(s[i]);
            // cout<<s.substr(i,2)<<endl;
            if(s2.find(s.substr(i+1,2))!=string::npos){
                flag=true;
                break;
            }
            else{
                continue;
            }
        
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}


int main(){
    fast_cin();
    ll t;
    cin>>t;
    while(t--) solve();
}