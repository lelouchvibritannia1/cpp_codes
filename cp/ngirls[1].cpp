#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int MAX=100005;

vector<bool> prime(MAX,true);
unordered_set<int> s,s1;
void sieve(){
    prime[0]=prime[1]=false;
    for(int i=2;i*i<MAX;i++){
        if(prime[i]){
            s.insert(i);
            for(int j=i*i;j<MAX;j+=i){
                prime[j]=false;
            }
        }
    }
}



void solve(){
    int n,k;
    cin>>n>>k;
    sieve();
    cout<<s.size()<<" ";
    int ans=0;
    for(int i=sqrt(k);i<=sqrt(n);i++){
        if(prime[i]){
            ans++;
        }
    }
    cout<<ans<<endl;
}


int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}