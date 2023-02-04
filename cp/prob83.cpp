#include<bits/stdc++.h>
using namespace std;


#define int long long int


void solve(){
    int n,m,c,mn=INT_MAX,mx=INT_MIN;
    cin>>n>>m;
    if(n%m==0){
        c=n/m;
        mn=((c*(c-1))/2)*m;
    }
    else{
        int sm=(n/m)*m;
        c=n-sm;
        int x=ceil((double)n/double(m));
        int y=n/m;
        mn = ((x*(x-1))/2)*c + ((y*(y-1))/2)*(m-c);
    }
    mx=n-m+1;
    mx=(mx*(mx-1))/2;
    cout<<mn<<" "<<mx<<endl;
}
int32_t main(){
    int t=1 ;
//    cin>>t;
    while(t--){
        solve();
    }
}
