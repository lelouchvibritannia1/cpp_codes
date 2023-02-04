#include<bits/stdc++.h>
using namespace std;
#define int long long int


int pow(int a,int b,int mod){
    int res=1;
    while(b>0){
        if(b&1) res*=a,res%=mod;
        a*=a,a%=mod;
        b>>=1;
    }
    return res%mod;
}

void solve(){
    int a,b;
    cin>>a>>b;
    cout<<pow(a,b,10)<<endl;


}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}