// FAILED ON SOME TEST CASE I CAN't FIGURE OUT
// #include<bits/stdc++.h>
// #include<iostream>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

// using namespace std;

// typedef long long ll;
// typedef long double ld;
// typedef pair<int,int> p32;
// typedef pair<ll,ll> p64;
// typedef pair<double,double> pdd;
// typedef vector<ll> v64;
// typedef vector<int> v32;
// typedef vector<vector<int> > vv32;
// typedef vector<vector<ll> > vv64;
// typedef vector<vector<p64> > vvp64;
// typedef vector<p64> vp64;
// typedef vector<p32> vp32;
// typedef stack<ll> s64;
// typedef stack<int> s32;
// typedef stack<pair<int,int>> sp32;
// typedef unordered_map<int,int> ump32;
// ll MOD = 1e9 + 7;
// double eps = 1e-8;


// #define G(x) ll x; cin >> x
// #define GS(x) string x; cin >> x
// #define F(i,l,r) for(ll i=l;i<r;i++)
// #define FD(i,r,l) for(ll i=r;i>l;i--)
// #define CO(x) cout << x << '\n'
// #define CO_(x) cout << x << ' '
// #define GA(x,n) ll x[n]; F(i,0,n) cin >> x[i]
// #define CA(x,n) F(i,0,n) {CO_(x[i]);} cout << '\n'
// #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// void solve(){
//     G(n);
//     vv64 A(n,v64(5));
//     v64 count(5,0);
//     F(i,0,n){
//         F(j,0,5){
//             cin>>A[i][j];
//             if(A[i][j]==1) count[j]++;
//         }
//     }
//     int ch=0;
//     F(i,0,5){
//         if(count[i]>=n/2){
//             ch++;
//         }
//     }
//     if(ch>=2){
//         cout<<"YES"<<endl;
//     }
//     else{
//         cout<<"NO"<<endl;
//     }
// }


// int main(){
//     fast_cin();
//     ll t;
//     cin>>t;
//     while(t--) solve();
// }

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
    vv64 A(n,v64(5));
    v64 count(5,0);
    F(i,0,n){
        F(j,0,5){
            cin>>A[i][j];
        }
    }
    bool ans=false;
    F(i,0,5){
        F(j,0,5){
            if(i!=j){
                ll cnta=0,cntb=0,cntno=0;
                F(k,0,n){
                    if(A[k][i]==1) cnta++;
                    if(A[k][j]==1) cntb++;
                    if(A[k][i]==0 && A[k][j]==0) cntno++;
                }
                    if(cnta>=(int)floor(n/2) && cntb>=(int)floor(n/2) && cntno==0){
                    ans=true;
                    }
            }
            
            
        }
    }
    if(ans){
        CO("YES");
    }
    else{
        CO("NO");
    }

}


int main(){
    fast_cin();
    ll t;
    cin>>t;
    while(t--) solve();
}