#include "bits/stdc++.h"
// #include<iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define int long long int
#define double long double
typedef pair<int, int> p64;
typedef pair<double, double> pdd;
typedef vector<int> v64;
typedef vector<vector<int>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
int MOD = 1e9 + 7;
double eps = 1e-8;
int MAX = 1e5;
#define F(i, l, r) for (int i = l; i < r; i++)
#define FD(i, r, l) for (int i = r; i > l; i--)
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void init_code()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
}

/*this here is code */
int bs_sqrt(int n){
    int ans=0;
    int left=0,right=2000000123;
    while(left<right){
        int mid=left+ (right- left)/2;
        if(mid*mid > n){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    return left-1;
}


void solve()
{
    int n;
    cin>>n;
    v64 a(n),b(n),d(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    
    bool flag=true;
    for(int i=0;i<n;i++){
        if((a[i]!=b[i] && b[i]>(b[(i+1)%n]+1))||b[i]<a[i]){
            flag=false;
        }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";

}

int32_t main()
{
    init_code();
    int t{1};
    cin >> t;
    while (t--)
        solve();
}
/*which ends here*/
