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
    ll n,d;
    cin>>n>>d;
    v64 a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll ans=0;
    ll temp=n;
    while(temp>0){
        if(a.back()>d){
//            cout<<10000<<endl;
            ans++;
            a.pop_back();
            temp--;
//            cout<<1<<endl;
        }
        else{
            ll no_of_ele=ceil((d-a.back())/a.back());
            // cout<<2+no_of_ele<<endl;
            temp-=(2+no_of_ele);
            if(temp<0) break;
            a.pop_back();
            ans++;
        }
//        Ccout<<ans<<endl;
    }
    cout<<ans<<endl;


}


int main(){
    fast_cin();
    ll t=1;
    // cin>>t;
    while(t--) solve();
}
