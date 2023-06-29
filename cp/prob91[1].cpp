
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

int gcd(int a,int b){
    if(a==0){
        return b;
    }
    else return gcd(b%a,a);
}


/*this here is code */



void solve(){
    int n;
    cin>>n;
    GA(a,n);
    int od=0,ev=0;
    for(int i=0;i<n;i++){
        if(a[i]%2) od++;
        else ev++;
    }
    if(od > ev && ev!=0){
        int j=0,sum=a[0];
        vector<int> b;
        for(int i=1;i<n;i++){
            if((sum+a[i])%2 == 0){
                b.push_back(sum);
                sum=a[i];
            }
            else{
                sum+=a[i];
                continue;
            }
        }
        int ans=b[0];
        for(int i=1;i<b.size();i++){
            ans=gcd(ans,b[i]);
        }
        cout<<ans<<endl;
    }
    else if(ev>od && od!=0){
        vector<int> b;
        int sum=a[0];
        for(int i=1;i<n;i++){
            if((sum+a[i])%2){
                b.push_back(sum);
                sum=a[i];
            }
            else{
                sum+=a[i];
                continue;
            }
        }
        int ans=b[0];
        for(int i=1;i<b.size();i++){
            ans=gcd(ans,b[i]);
        }
        cout<<ans<<endl;

    }
    else if(od==0 || ev==0){
        int s=accumulate(a.begin(),a.end(),0);
        int a1=accumulate(a.begin(),a.begin() + (n+1)/2, 0);
        int b1=s-a1;
        int ans=gcd(a1,b1);
        cout<<ans<<endl;
    }
}


int32_t main(){
    fast_cin();int t;cin>>t;while(t--) solve();
}
/*which ends here*/
