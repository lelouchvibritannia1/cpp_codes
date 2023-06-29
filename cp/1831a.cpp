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
//great implemenetaion of kruskal



const int N=1e5+5;

int parent[N], len[N];
int well[N];
int find(int i){
            if(parent[i]==i){
                return i;
            }
            else{
                return parent[i]=find(parent[i]);
            }
        }

bool unite(int u,int v){
    int p1=find(u);
    int p2=find(v);
    if(p1==p2) return 0 ;
    if(len[p1]>len[p2]) swap(p1,p2);
    len[p2]+=len[p1];
    parent[p1]=p2;
    return 1;
}


void solve()
{
    int n;
    cin>>n;
    int a[n+1];
    int b[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    unordered_map<int,int> mp1,mp2;
    int ans=0;
    int i=0;
    while(i<n){
        if(i<n-1 && a[i]==a[i+1]){
            int j=i;
            while(j<n-1 && a[j+1]==a[j]){
                j++;
            }
            // cout<<j<<" "<<endl;;n
            mp1[a[i]]=max(mp1[a[i]],j-i+1);
            i=j+1;
        }
        else{
            mp1[a[i]]=max(mp1[a[i]],1LL);
            i++;
        }
    }
    // for(auto x:mp1){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    i=0;
    while(i<n){
        if(i<n-1 && b[i]==b[i+1]){
            int j=i;
            while(j<n-1 && b[j+1]==b[j]){
                j++;
            }
            mp2[b[i]]=max(mp2[b[i]],j-i+1);
            i=j;
        }
        else{
            mp2[b[i]]=max(mp2[b[i]],1LL);
            i++;
        }
    }
    int mx=0;
    // for(auto x:mp2){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    for(auto x:mp1){
        mx=max(mx,x.second);
    }
    for(auto x:mp2){
        mx=max(mx,x.second+mp1[x.first]);
    }
    cout<<mx<<endl;
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