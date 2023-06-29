
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
    v64 a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll i=1;
    while(i<n && a[i-1]<=a[i]){
        i++;
    }
    if(i==n) {cout<<"YES"<<endl;return;}
    while(i<n && a[i-1]>=a[i]){
        i++;
    }
    if(i==n) {cout<<"YES"<<endl;return;}

    cout<<"NO"<<endl;
    return;
}


int main(){
    fast_cin();
    ll t;
    cin>>t;
    while(t--) solve();
}

//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long int ll;
//typedef long double ld;
//typedef pair<ll,ll> pll;
//
//#define G(x) ll x; cin >> x;
//#define GS(x) string x; cin >> x;
//#define F(i,l,r) for(ll i=l;i<r;i++)
//#define FD(i,r,l) for(ll i=r;i>l;i--)
//#define CO(x) cout << x << '\n';
//#define CO_(x) cout << x << ' ';
//#define GA(x,n) ll x[n]; F(i,0,n) cin >> x[i];
//#define CA(x,n) F(i,0,n) {CO_(x[i]);} cout << '\n';
//
//void solve() {
//    G(n);
//    GA(a,n);
//    if(n < 3) {CO("YES"); return;}
//    ll index = 1;
//    while(index < n && a[index] >= a[index-1]) index++;
//    if(index == n) {CO("YES"); return;}
//    while(index < n && a[index] <= a[index-1]) index++;
//    if(index == n) {CO("YES"); return;}
//    CO("NO")
//    return;
//}
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    G(t)
//    while(t--)
//        solve();
//
//    return 0;
//
//}
