#include "bits/stdc++.h"
using namespace std;
#define int long long int
const int MOD=1e7 + 7;

void init_code(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int pow(int a,int b,int mod){
    int res=1;
    while(b>0){
        if(b&1) res*=a,res%=mod;
        a*=a,a%=mod;
        b>>=1;
    }
    return res%mod;
}

void solve(int n,int k){
    int a=pow(n,k,MOD);
    int b=2*pow(n-1,k,MOD);
    int c=pow(n,n,MOD);
    int d=2*pow(n-1,n-1,MOD);
    cout<<(a+b+c+d)%MOD<<endl;
}

int32_t main(){
    init_code();
    while(true){
        int n,k;
        cin>>n>>k;
        if(n==0 && k==0){
            break;
        }
        else{
            solve(n,k);
        }

    }
        
}