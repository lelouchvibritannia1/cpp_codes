#include <bits/stdc++.h>
#include <iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9 + 7;
double eps = 1e-8;

#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ln '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        unordered_map<char, int> mp;
        string s;
        int ans = INT_MAX;
        cin >> n >> k;
        cin >> s;
        int l = 0, r = 0;
        while (r < s.size())
        {
            mp[s[r]]++;
            if ((r - l + 1) < k)
            {
                r++;
            }
            else if ((r - l + 1) == k)
            {
                if (mp['B'] <= k)
                    ans = min(ans, k - mp['B']);
                mp[s[l]]--;
                l++;
                r++;
            }
        }
        cout<<ans<<endl;
    }
}