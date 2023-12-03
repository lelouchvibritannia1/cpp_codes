#include <bits/stdc++.h>
#include <iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;
#define int long long
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
typedef stack<ll> s64;
typedef stack<int> s32;
typedef stack<pair<int, int>> sp32;
typedef unordered_map<int, int> ump32;
ll MOD = 1e9 + 7;
double eps = 1e-8;

int mah(v64 a)
{
    int n = a.size();
    stack<int> s;
    s.push(-1);
    int ar = a[0];
    v64 lt(n, -1), rt(n, n);
    int i{0};
    while (i < n)
    {
        while (!s.empty() && s.top() != -1 && a[s.top()] > a[i])
        {
            rt[s.top()] = i;
            s.pop();
        }
        if (i > 0 && a[i] == a[i - 1])
        {
            lt[i] = lt[i - 1];
        }
        else
        {
            lt[i] = s.top();
        }
        s.push(i);
        i++;
    }

    for (int i = 0; i < n; i++)
    {
        ar = max(ar, a[i] * (rt[i] - lt[i] - 1));
    }

    return ar;
}
int32_t main()
{
    int n;
    cin >> n;
    v64 v1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    int c;
    cin >> c;
    cout << mah(v1) * c << endl;
}