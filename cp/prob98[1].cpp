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

int gcd(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}


void solve(){
    int n;
    cin>>n;
//    int mn=INT_MAX;
//    for(int i=1;i<=n/2;i++){
//        int lcm=i*(n-i)/__gcd(i,n-i);
//        if(mn>lcm){
//            mn=lcm;
//            ans=i;
//        }
//    }
//    cout<<ans<<" "<<(n-ans)<<endl;
// TLE O(N)
        if(!n%2){
            cout<<n/2<<" "<<n/2<<endl;
        }
        else{
        int ans=1;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                ans=i;
                break;
            }
        }
        if(ans==1){
            cout<<ans<<" "<<n-ans<<endl;
        }
        else{
            cout<<n/ans<<" "<<n- n/ans<<endl;
        }
        }


}


int32_t main(){
    fast_cin();
    int t{1};
    cin>>t;
    while(t--) solve();
}
/*which ends here*/
