#include<bits/stdc++.h>
#include<iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef stack<ll> s64;
typedef stack<int> s32;
typedef stack<pair<int,int>> sp32;
typedef unordered_map<int,int> ump32;
ll MOD = 1e9 + 7;
double eps = 1e-8;

int lcs(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        int dp[n+1][m+1];
        
        for(int i=0; i<=n; i++)
            dp[i][0] = 0;
        
        for(int i=0; i<=m; i++)
            dp[0][i] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
              
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
}


void solve(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll  cnt=0;
    for(ll i=0;i<k-1;i++){
        if(s[i]!=s[i+1]) cnt++;
    }
    ll ans=LLONG_MAX;
    if(s[k-1]=='0') ans=min(ans,cnt+1);
    else ans=min(ans,cnt);
    for(int i=k;i<n-1;i++){
        if(s[i-1]!=s[i]) cnt++;
        if(s[i-k]!=s[i-k+1]) cnt--;
        if(s[i-1]=='0') ans=min(ans,cnt+1);
        else ans=min(ans,cnt);
    }
    if(s[n-1]=='0') ans=min(ans,cnt+1);
    else ans=min(ans,cnt);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--) solve();
}