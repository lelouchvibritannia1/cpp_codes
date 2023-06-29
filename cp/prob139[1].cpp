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
#define G(x) \
    int x;   \
    cin >> x
#define GS(x) \
    string x; \
    cin >> x
#define F(i, l, r) for (int i = l; i < r; i++)
#define FD(i, r, l) for (int i = r; i > l; i--)
#define CO(x) cout << x << '\n'
#define CO_(x) cout << x << ' '
#define GA(x, n) \
    v64 x(n);    \
    F(i, 0, n)   \
    cin >> x[i]
#define CA(x, n)   \
    F(i, 0, n)     \
    {              \
        CO_(x[i]); \
    }              \
    cout << '\n'
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

int cnt(int y)
{
    return ((y * (y + 1)) / 2);
}
void solve()
{
    int n,k;
    cin>>n>>k;
    v64 x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    int ans{0};
    for(int i=n-1;i>=0 && x[i]>=0;i-=k){
        ans+=x[i];
    }
    for(int i=0;i<n && x[i]<0;i+=k){
        ans-=x[i];
    }
    cout<<2*ans-max(abs(x[0]),x[n-1])<<endl;
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