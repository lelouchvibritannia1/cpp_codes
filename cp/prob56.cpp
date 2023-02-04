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
#define GA(x,n) ll x[n]; F(i,0,n) cin >> x[i]
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


// this is O(nlogn+q.n) which is slow.
// void solve(){
//     ll n,q;
//     cin>>n>>q;
//     GA(x,n);
//     sort(x,x+n,greater<int>());
//     for(int i=1;i<=q;i++){
//         ll xq;
//         cin>>xq;
//         ll sum=0,cnt=0;
//         for(auto y:x){
//             cnt++;
//             sum+=y;
//             if(sum>=xq){
//                 cout<<cnt<<endl;
//                 break;
//             }
//         }
//         if(sum<xq && cnt<=n) cout<<-1<<endl;

//     }
// }



// this uses prefix sums and tries to find an element with prefix sum of atleast x. since array is increasing, we binary search. O(logn)

void solve(){
    G(n);G(q);
    GA(x,n);
    sort(x,x+n,greater<int>());
    vector<ll> pref(n);
    pref[0]=x[0];
    F(i,1,n) pref[i]=pref[i-1]+x[i];
    for(int i=1;i<=q;i++){
        ll query;
        cin>>query;
        ll l=1,h=n;
        ll ans=-1;
        while(l<=h){
            ll mid=l+(h-l)/2;
            if(pref[mid-1]>=query){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        cout<<ans<<endl;
    }
}


int main(){
    fast_cin();ll t;cin>>t;while(t--) solve();
}
/*which ends here*/
