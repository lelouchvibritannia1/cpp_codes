

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define el '\n'
#define yes cout<<"YES"<<el
#define no cout<<"NO"<<el
#define f(i,a,b) for(ll i = a; i <= b; i++)
#define fr(i,a,b) for(ll i = a; i >= b; i--)
#define vi vector<int>
#define speed ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)(x).size())
#define test ll _x86_; cin>>_x86_; while(_x86_--)

void init_code(){
    speed;
//    #ifndef ONLINE_JUDGE
//    // for getting input from input.txt
//    freopen("input.txt", "r", stdin);
//    // for writing output to output.txt
//    freopen("output.txt", "w", stdout);
//    #endif
}

void solve()
{
    int n, k, baseh{0}; cin>>n>>k;
    vector<pair<int,int>> m(n); vi h(n);

    f(i,0,n-1) cin>>m[i].first;
    f(i,0,n-1) cin>>m[i].second;

    sort(all(m));

    f(i, 0, n-1) h[i] = m[i].first;

    fr(i, n-2, 0) m[i].second = min(m[i+1].second, m[i].second);

    while(k > 0)
    {
        int ded = upper_bound(all(h), k+baseh) - h.begin();

        if(ded == n) { yes; return; }

        baseh += k;
        k -= m[ded].second;
    }
    no;
}

int32_t main()
{
    speed;      test

    solve();
}
