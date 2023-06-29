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

void init_code(){
    fast_cin();
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
}

int main(){
    init_code();
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        unordered_set<long long> s; 
        unordered_set<long long> s1;
        long long mx=LLONG_MIN;
        long long mn=LLONG_MAX;
        for(int i=0;i<n;i++){
            cin>>a[i];
            s1.insert(a[i]);
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
        }
        long long ans=mx*mn;
        for(long long i=2;i*i<=ans;i++){
            if(ans%i==0){
                s.insert(i);
                s.insert(ans/i);
            }
        }
        if(s==s1){
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}