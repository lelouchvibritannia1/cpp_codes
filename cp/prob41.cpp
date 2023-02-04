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
ll MAX=1e5;


#define G(x) ll x; cin >> x
#define GS(x) string x; cin >> x
#define F(i,l,r) for(ll i=l;i<r;i++)
#define FD(i,r,l) for(ll i=r;i>l;i--)
#define CO(x) cout << x << '\n'
#define CO_(x) cout << x << ' '
#define GA(x,n) v64 x(n); F(i,0,n) cin >> x[i]
#define CA(x,n) F(i,0,n) {CO_(x[i]);} cout << '\n'
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<bool> prime(MAX,true);
void sieve(){
    prime[0]=prime[1]=false;
    for(int i=2;i*i<MAX;i++){
        if(prime[i]){
            for(int j=i*i;j<MAX;j+=i){
                prime[j]=false;
            }
        }
    }
}


/*this here is code */
void init_code(){
    fast_cin();
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
}

bool isBeautiful(v64 x){
    ll n=x.size();
    v64 prefix(n);
    prefix[0]=0;
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+x[i-1];
        if(prefix[i]==x[i]){
            return false;
        }
    }
    return true;
}



void solve(){
    G(n);
    GA(x,n);
    if(isBeautiful(x)){
        cout<<"YES"<<endl;
        CA(x,n);
    }
    else{
        ll i=0,j=n-1;
        while(!isBeautiful(x) && i<j){
            int temp=x[i];
            x[i]=x[j];
            x[j]=temp;
            i++;j--;
        }
        if(isBeautiful(x)) {cout<<"YES"<<endl;CA(x,n);}
        else cout<<"NO"<<endl;
    }
}


int main(){
    init_code();
    ll t;
    cin>>t;
    while(t--) solve();
}
/*which ends here*/