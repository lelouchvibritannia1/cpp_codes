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


int taken(string sn,string sx){
    int p1=0,p2=0;
    int ans=0;
    while(p1<sn.size() && p2<sx.size()){
        if(sn[p1]==sx[p2]){
            ans++;
            p1++;
            p2++;
        }
        else{
            p1++;
        }
    }
    return ans;
}

int mx=1e18;
void solve()
{   
    int n;
    cin>>n;
    v64 a(n);
    int n_odd=-,n_even=0;
    for(int i=0;i<n;i++){
        cin>a[i];
        if(a[i]%2) n_odd++;
        else n_even++;
    }
    if(n_odd>n_even+1 || n_odd<n_even-1){
        cout<<-1<<endl;
    }
    int ans,ano,ane;
    v64 cur(n);
    bool k=true; //true is odd
    for(int i=0;i<n;i++){
        cur[i]=k;
        k=!k;
    }
    int po=0,pe=0;
    for(;a[po]%2!=0;po++)
    for(;a[pe]%2==0;pe++)
    for(int i=0;i<n;i++){
        if(a[i]%2==curr[i]){
            continue;
        }
        else{
            if(curr[i]==true )
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