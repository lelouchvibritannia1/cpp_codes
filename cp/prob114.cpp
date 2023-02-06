 #include "bits/stdc++.h"
// #include<iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define int long long int
#define double long double
typedef pair<int,int> p64;
typedef pair<double,double> pdd;
typedef vector<int> v64;
typedef vector<vector<int> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
int MOD = 1e9 + 7;
double eps = 1e-8;
int MAX=1e5;
#define F(i,l,r) for(int i=l;i<r;i++)
#define FD(i,r,l) for(int i=r;i>l;i--)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)



void init_code(){
    fast_cin();
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

}



/*this here is code */



void solve(){
    int n;
    cin>>n;
    v64 a(n);
    F(i,0,n){
        cin>>a[i];
    }
    int s=accumulate(a.begin(),a.end(),0);
    if(s%2!=0){
        cout<<-1<<endl;
        return;
    }
    else{
        vector<pair<int,int>> ans;
        bool flag=true;
        int i=0,j=0;
        for(int j=1;j<n;j+=2){
            if(a[j]==a[j-1]){
                ans.push_back({j,j+1});
            }
            else{
                ans.push_back({j,j});
                ans.push_back({j+1,j+1});
            }
        }

        cout<<ans.size()<<endl;
        for(auto &x:ans){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
}


int32_t main(){
    init_code();
    int t{1};
   cin>>t;
    while(t--) solve();
}
/*which ends here*/
