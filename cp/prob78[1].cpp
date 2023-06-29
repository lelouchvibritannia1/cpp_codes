#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD=1e9 + 7;

int pow(int a,int b,int mod){
    int res=1;
    while(b>0){
        if(b&1) res*=a,res%=mod;
        a*=a,a%=mod;
        b>>=1;
    }
    return res%mod;
}


bool parity(int a,int b){
    if(a%2 == b%2){
        return true;
    } 
    return false;
}

int fact(int n){
    int ans=1;
    for(int i=2;i<=n;i++){
        ans*=i,ans%=MOD;
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    if(n==1) {cout<<0<<endl;return;}
    int a=fact(n);
    int c=((n%MOD)*((n-1)%MOD));
    int ans=((a%MOD)*(c%MOD))%MOD;
    cout<<ans<<endl;
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
        
}