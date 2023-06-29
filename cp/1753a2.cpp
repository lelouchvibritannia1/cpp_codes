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
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(accumulate(a+1,a+n+1,0LL)%2!=0){ 
        cout<<-1<<endl;
        return;
    }   
    else{
        vector<pair<int,int>>ans;
        int i=1, r=0;
        while(i<=n){
            if(a[i]!=0){
                int j=i+1;
                while(a[j]==0 && j<=n){
                    j++;
                }
                if(a[i]==a[j]){
                    ans.push_back({i,j-2});
                    ans.push_back({j-1,j});
                }
                else{
                    ans.push_back({i,j-1});
                    ans.push_back({j,j});
                }
                i=j+1;
            }
            else{
                ans.push_back({i,i});
                i++;
            }
        }
        cout<<ans.size()<<endl;
        for(auto p:ans){
            cout<<p.first<<" "<<p.second<<endl;
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

