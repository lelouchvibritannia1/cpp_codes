#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
int MAX=1e6;
vector<int> spf(MAX+5,0);
void sf(){
    for(int i=1;i<=MAX;i++){
        spf[i]=i;
    }
    for(int i=2;i*i<=MAX;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=MAX;j+=i){
                spf[j]=min(spf[j],i);
            }
        }
    }
}


// int c=1;
void solve(){
    ll n;
    cin>>n;
    // sf();
    // map<int,int> m;
    // while(n!=1){
    //     int p=spf[n];
    //     int q=0;
    //     while(n%p==0){
    //         n/=p;
    //         q++;
    //     }
    //     m[p]=q;
    // }
//tle

    multiset<ll> s;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            ll p=i,q=0;
            ll c=1;
            ll ans=0;
            while(n%p==0){
                n=n/p;
                q++;
                if(q==c){
                    ans++;c++;q=0;
                }
            }
            s.insert(ans);
        }
    }
    if(n!=1) s.insert(1);
    // cout<<"Case "<<c<<":"<<" ";
    ll ans=0;
    for(auto x:s){
        ans+=x;
    }
    cout<<ans<<endl;
    // c++;
}

int main(){
    int t=1;
    while(t--){
        solve();
    }
}