ww#include<bits/stdc++.h>
using namespace std;

long long MAX=1e6;
vector<long long> spf(MAX+5,0);
void sf(){
    for(long long i=1;i<=MAX;i++){
        spf[i]=i;
    }
    for(long long i=2;i*i<=MAX;i++){
        if(spf[i]==i){
            for(long long j=i*i;j<=MAX;j+=i){
                spf[j]=min(spf[j],i);
            }
        }
    }
}


long long c=1;
void solve(){
    long long n;
    cin>>n;
    // sf();
    // map<long long,long long> m;
    // while(n!=1){
    //     long long p=spf[n];
    //     long long q=0;
    //     while(n%p==0){
    //         n/=p;
    //         q++;
    //     }
    //     m[p]=q;
    // }
//tle

    map<long long,long long> s;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            long long p=i,q=0;
            while(n%p==0){
                n=n/p;
                q++;
            }
            s.insert({p,q});
        }
    }
    if(n!=1) s.insert({n,1});
    cout<<"Case "<<c<<":"<<" ";
    for(auto x:s){
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;
    c++;
}

int main(){
    long long t;cin>>t;
    while(t--){
        solve();
    }
}