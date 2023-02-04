#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define double long double
#define MAX (int)(1e6+5)


void init_code(){
    fast_cin();
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
}

vector<bool> prime(MAX,true);
set<int> sieve(){
    set<int> s;
    prime[0]=prime[1]=false;
    for(int i=2;i*i<MAX;i++){
        if(prime[i]){
            for(int j=i*i;j<MAX;j+=i){
                prime[j]=false;
            }
        }
    }
    for(int i=2;i<MAX;i++){
        if(prime[i]) s.insert((int)i*i);
    }

    return s;
}



void solve(){
    int n;
    cin>>n;
    int a[n];
    set<int> s=sieve();
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(s.find(a[i])!=s.end()){
            cout<<"YES"<<endl;continue;
        }
        else{
            cout<<"NO"<<endl;continue;
        }
    }
}


int32_t main(){
    init_code();
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}