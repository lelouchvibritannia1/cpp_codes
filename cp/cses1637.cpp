//  #include "bits/stdc++.h"
// // #include<iostream>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

// using namespace std;

// #define int long long int
// #define double long double
// typedef pair<int,int> p64;
// typedef pair<double,double> pdd;
// typedef vector<int> v64;
// typedef vector<vector<int> > vv64;
// typedef vector<vector<p64> > vvp64;
// typedef vector<p64> vp64;
// int MOD = 1e9 + 7;
// double eps = 1e-8;
// int MAX=1e5;
// #define G(x) int x; cin >> x
// #define GS(x) string x; cin >> x
// #define F(i,l,r) for(int i=l;i<r;i++)
// #define FD(i,r,l) for(int i=r;i>l;i--)
// #define CO(x) cout << x << '\n'
// #define CO_(x) cout << x << ' '
// #define GA(x,n) v64 x(n); F(i,0,n) cin >> x[i]
// #define CA(x,n) F(i,0,n) {CO_(x[i]);} cout << '\n'
// #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)



// void init_code(){
//     fast_cin();
//     #ifndef ONLINE_JUDGE
//     // for getting input from input.txt
//     freopen("input.txt", "r", stdin);
//     // for writing output to output.txt
//     freopen("output.txt", "w", stdout);
//     #endif

// }



// /*this here is code */

// const int N=1e2+5;


// void solve(){
//     string s1,s2;
//     cin>>s1;
//     cin>>s2;
//     int n=s1.length(),m=s2.length();
//     vv64 dp(n+1,v64(m+1,1e9));
//     dp[0][0]=0;
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=m;j++){
//             if(i) dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
//             if(j) dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
//             if(i&&j) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s1[i-1]!=s2[j-1]));
//         }
//     }
//     cout<<dp[n][m];
// }


// int32_t main(){
//     init_code();
//     int t{1};
//     // cin>>t;
//     while(t--) solve();
// }
// /*which ends here*/



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
#define G(x) int x; cin >> x
#define GS(x) string x; cin >> x
#define F(i,l,r) for(int i=l;i<r;i++)
#define FD(i,r,l) for(int i=r;i>l;i--)
#define CO(x) cout << x << '\n'
#define CO_(x) cout << x << ' '
#define GA(x,n) v64 x(n); F(i,0,n) cin >> x[i]
#define CA(x,n) F(i,0,n) {CO_(x[i]);} cout << '\n'
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
 
const int N=1e2+5;
 
 
void solve(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length(),m=s2.length();
    vv64 dp(n+1,v64(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
            }
        }
    }
    cout<<dp[n][m];
}
 
 
int32_t main(){
    init_code();
    int t{1};
    // cin>>t;
    while(t--) solve();
}
/*which ends here*/