
#include<bits/stdc++.h>
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

#define first fi
#define second se
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;i<(n);(i)++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ln '\n'


ll FLOOR(v64& A,int L,int H,ll T){
    ll R=-1;
    while(L<=H){
        int M=L+(H-L)/2;
        if(A[M]>T){
            H=M-1;
        }
        else if(A[M]<T){
            R=M;
            L=M+1;
        }
        else{
            return M+1;
        }
    }
    return R+1;
}

 ll BS(v64& A,ll L,ll H,ll X){
    // if(L==H) return X==A[L];
    if(L>H) return -1;
    ll M=L+((H-L)/2);
    if(A[M]==X) return M;
    else if(A[M]>X) return BS(A,L,M-1,X);
    else return BS(A,M+1,H,X);
 }

int main(){
    fast_cin();
    int n,k;
    cin>>n>>k;
    v64 A(n),Q(k);
    rep(i,n) cin>>A[i];
    rep(i,k) cin>>Q[i];
    for(auto x:Q){
        cout<<FLOOR(A,0,n-1,x)<<endl;
    }
}
