#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;typedef long double ld;typedef pair<int,int> p32;typedef pair<ll,ll> p64;typedef pair<double,double> pdd;typedef vector<ll> v64;typedef vector<int> v32;typedef vector<vector<int> > vv32;typedef vector<vector<ll> > vv64;typedef vector<vector<p64> > vvp64;typedef vector<p64> vp64;typedef vector<p32> vp32;typedef stack<ll> s64;typedef stack<int> s32;typedef stack<pair<int,int>> sp32;typedef unordered_map<int,int> ump32;ll MOD = 1e9 + 7;double eps = 1e-8;ll MAX=1e5;

vector<bool> prime(MAX,true);void sieve(){prime[0]=prime[1]=false;for(int i=2;i*i<MAX;i++){if(prime[i]){for(int j=i*i;j<MAX;j+=i){prime[j]=false;}}}}

bool isPrime(ll x){
    for(ll i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

ll gcd(ll a,ll b){
    if(a==0) return b;
    return gcd(b%a,a);
}

ll nearestMultiple(ll x,ll l){
    ll temp=(l/x)*x;
    if(temp<l){
        temp+=x;
    }
    return temp;
}
/*this here is code */

void solve(){
    ll n,l,r;
    cin>>n>>l>>r;
    bool flag=true;
    v64 a;
    for(int i=1;i<=n;i++){
        ll now=nearestMultiple(i,l);
        if( now>=l && now<=r){
            a.push_back(now);
        }
        else{
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
        for(auto&x:a) cout<<x<<" "; cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}


int main(){fast_cin();ll t;cin>>t;while(t--) solve();}
/*which ends here*/