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

int CEIL(v64 A, int L, int H, int T)
{
    int R = H + 1;
    while (L <= H)
    {
        int M = L + (H - L) / 2;
        if (A[M] > T)
        {
            R = M;
            H = M - 1;
        }
        else if (A[M] < T)
        {
            L = M + 1;
        }
        else
        {
            return M + 1;
        }
    }
    return R + 1;
}

int FLOOR(v64 A, int L, int H, int T)
{
    int R = -1;
    while (L <= H)
    {
        int M = L + (H - L) / 2;
        if (A[M] > T)
        {
            H = M - 1;
        }
        else if (A[M] < T)
        {
            R = M;
            L = M + 1;
        }
        else
        {
            return M + 1;
        }
    }
    return R + 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> r(n);
    vector<pair<int, int>> ans;
    v64 a(n), b(n);
    int ops = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> r[i].first;
        r[i].second = i + 1;
    }
    sort(r.begin(), r.end());

    for (int i = 0; i < n; i++)
    {
        a[i] = r[i].first;
        b[i] = r[i].second;
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    if (a[0] == 1)
    {
        if (a[n - 1] == 1)
            cout << 0 << endl;
        else
            cout << -1 << endl;
        return;
    }
    else
    {
        int t = CEIL(a, 0, n - 1, 2 * a[0]);
        // cout << a[t] << endl;
        if (a[t - 1] == a[0] && t == n)
        {
            cout << 0 << endl;
            return;
        }
        else
        {
            while (a[t - 1] > 2)
            {
                a[t - 1] = (int)(ceil((float)a[t - 1] / (float)a[0]));
                ans.push_back({b[t - 1], b[0]});
                ops++;
            }
            for (int i = 0; i < n; i++)
            {
                while (a[i] > 2)
                {
                    a[i] = (int)(ceil((float)a[i] / (float)2));
                    ans.push_back({b[i], b[t - 1]});
                    ops++;
                }
            }
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<n && j!=i;j++){
            //         if((int)(ceil))
            //     }
            // }
            // cout<<t<<endl;
        }
        cout << ops << endl;
        for (int i = 0; i < ops; i++)
        {
            cout << ans[i].first << " " << ans[i].second << "\n";
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