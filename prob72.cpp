#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void init_code(){
   fast_cin();
//    #ifndef ONLINE_JUDGE
//    // for getting input from input.txt
//    freopen("input.txt", "r", stdin);
//    // for writing output to output.txt
//    freopen("output.txt", "w", stdout);
//    #endif
}

vector<int> prime(3005,0);
void build(){
    prime[0]=prime[1]=0;
    for(int i=2;i<3005;i++){
        if(prime[i]==0){
            for(int j=i+i;j<3005;j+=i){
                prime[j]++;
            }
        }

    }
//    for(int i=0;i<3005;i++){
//        cout<<prime[i]<<endl;
//    }
}

void solve(){
    int n;
    cin>>n;
    build();
    int ans=0;
    for(int i=1;i<=n;i++){
        if(prime[i]==2){
            ans++;
        }
    }
    cout<<ans<<endl;
}


int32_t main(){
    init_code();
    solve();
}
