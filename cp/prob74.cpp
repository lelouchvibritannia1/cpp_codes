#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<" "<<1<<endl;
        return;
    }
    int ans;
    for(int i=1;i*i<n;i++){
        if(n%i==0){
            ans=i;
        }
    }
    cout<<ans<<" "<<(n/ans)<<endl;
}


int32_t main(){
    solve();
}