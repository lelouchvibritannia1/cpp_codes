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

bool isSmaller(string s1,string s2){int n1=s1.length(),n2=s2.length();return((n1<n2)?true:false);for(int i=0;i<n1;i++){if(s1[i]<s2[i]) return true; else return false;} return false;}
bool difference(string s1,string s2){if(isSmaller(s1,s2)swap(s1,s2);string ans="";int n1=s1.length(),n2=s2.length,diff=n1-n2;    for (int i = n2 - 1; i >= 0; i--) {int sub = ((str1[i + diff] - '0') - (str2[i] - '0')- carry);if (sub < 0) {sub = sub + 10;carry = 1;}else carry = 0;str.push_back(sub + '0');}}

void solve(){
}


int main(){
    fast_cin();ll t;cin>>t;while(t--) solve();
}
/*which ends here*/
