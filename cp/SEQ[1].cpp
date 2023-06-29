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
int MOD = 1e9;
double eps = 1e-8;
int MAX=1e5;
const int sz=10;
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

struct Mat{
    int m[sz][sz];
    Mat(){
        memset(m,0,sizeof(m));
    }

    void identity(){
        for(int i=0;i<sz;i++){
            m[i][i]=1;
        }
    }
    // overloading operator
    Mat operator* (Mat a){
        Mat res;
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                for(int k=0;k<sz;k++){
                    res.m[i][j]+=m[i][k]*a.m[k][j];
                    res.m[i][j]%=MOD;
                }
            }
        }
        return res;
    }

};

Mat pow(Mat T,int n){
    Mat res;
    res.identity();
    while(n){
        if(n&1) res=res*T;
        T=T*T;
        n>>=1;
    }

    return res;
}




void solve(){
    int k;cin>>k;
    v64 a(10),c;
    Mat T;
    Mat res;
    res.identity();
    for(int i=1;i<10;i++){
        T.m[i][i-1]=1;
    }
    for(int i=0;i<k;i++){
        cin>>a[i];
    }

    for(int i=0;i<k;i++){
        cin>>T.m[0][i];
    }
    int n;
    cin>>n;

    if(n<=k) {cout<<a[n-1]<<endl;return;}

    Mat T2=pow(T,n-k);

    int ans=0;

    for(int i=0;i<k;i++){
        ans+=(T2.m[0][i]*a[k-1-i])%MOD;
        ans%=MOD;
    }


    cout<<ans%MOD<<endl;

}


int32_t main(){
    fast_cin();int t;cin>>t;while(t--) solve();
}
/*which ends here*/
