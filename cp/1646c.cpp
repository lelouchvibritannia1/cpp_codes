#include "bits/stdc++.h"
// #include<iostream>
#include <cstdint>
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
// int MAX = 1e5;
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
//wrote an O(n^2) solution for this one, wen dp should have been used with dfs
//kek

const int MAX=1e12;

int gfb(int n){
    return 63-__builtin_clzll(n);
}


void solve()
{   
    int n,k;
    cin>>n>>k;
    if(k==0){
        for(int i=0;i<=n/2-1;i++){
            cout<<i<<" "<<(i^(n-1))<<endl;
        }
    }
    else if(0<k && k<n-1){
        int k_s=min(k,k^(n-1));
        cout<<0<<" "<<(k^(n-1))<<endl;
        cout<<n-1<<" "<<k<<endl;
        for(int i=0;i<n/2;i++){
            if(i!=0 && i!=k_s) cout<<i<<" "<<(i^(n-1))<<endl;
        }
    }
    else{
        if(n==4){
            cout<<-1<<endl;
            return;
        }
        else{
            cout<<(n-1)<<" "<<(n-2)<<endl;
            cout<<(n-3)<<" "<<1<<endl;
            cout<<0<<" "<<2<<endl;
            for(int i=3;i<n/2;i++){
                cout<<i<<" "<<(i^(n-1))<<endl;
            }
        }
    }
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

