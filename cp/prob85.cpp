#include<bits/stdc++.h>
#include<iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define int long long int
#define double long double
typedef pair<int,int> p64;
typedef pair<double,double> pdd;
typedef vector<int> v64;
typedef vector<vector<int> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
int MOD = 1e9 + 7;
double eps = 1e-8;
int MAX=1e5;
#define G(x) int x; cin >> x
#define GS(x) string x; cin >> x
#define F(i,l,r) for(int i=l;i<r;i++)
#define FD(i,r,l) for(int i=r;i>l;i--)
#define CO(x) cout << x << '\n'
#define CO_(x) cout << x << ' '
#define GA(x,n) v64 x(n); F(i,0,n) cin >> x[i]
#define CA(x,n) F(i,0,n) {CO_(x[i]);} cout << '\n'
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)




/*this here is code */



void solve(){
    int n,k;cin>>n>>k;
    int l=0,h=n-1,ans=0;
    while(l<=h){
        int mid= l + (h-l)/2;
        if((mid*(mid+1))/2 < k){
            ans=mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
//    cout<<ans<<endl;
    string s(n,'a');
    s[n-ans-2]='b';
    int dif=k - (ans*(ans+1))/2;
    s[n-dif]='b';
    cout<<s<<endl;
}


int32_t main(){
    fast_cin();int t;cin>>t;while(t--) solve();
}
/*which ends here*/
