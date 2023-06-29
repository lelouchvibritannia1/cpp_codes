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
    v64 a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    b[0]=a[0];
    for(int i=1;i<n;i++){
        b[i]=a[i]+b[i-1];
    }
    if(b[n-1]!=0){
        cout<<"NO\n";return;
    }
    int c=1;
    for(int i=0;i<n;i++){
        if(b[i]<0) c=0;
    }
    int vz=0;
    for(int i=0;i<n;i++){
        if(b[i]==0) vz=1;
        else if(vz) c=0;
    }
    if(c) cout<<"YES\n";
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
