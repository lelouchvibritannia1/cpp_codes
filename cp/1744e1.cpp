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
//wrote an O(n^2) solution for this one, wen dp should have been used with dfs
//kek



const int N=2e5+5;
int a[N];
int n;

void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int> s1,s2;
    for(int i=1;i*i<=a;i++){
        if(a%i==0){
            s1.push_back(i);
            if(i*i!=a) s1.push_back(a/i);
        }
    }
    for(int i=1;i*i<=b;i++){
        if(b%i==0){
            s2.push_back(i);
            if(i*i!=b) s2.push_back(b/i);
        }
    }

    auto check = [](int x,int l,int r){
        l++;
        if(l%x==0) return l;
        int y = (l/x)*x+x;
        if(y<=r){
            return y;
        }
        else return 0LL;
    };

    for(auto i:s1){
        for(auto j:s2){
            int x=i*j;

            if(check(x,a,c) && check((a*b)/x,b,d)){
                cout<<check(x,a,c)<<" "<<check((a*b)/x,b,d)<<endl;
                return;
            }
        }
    }

    cout<<"-1 -1\n";





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

