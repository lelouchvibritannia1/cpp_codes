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
#define F(i, l, r) for (int i = l; i < r; i++)
#define FD(i, r, l) for (int i = r; i > l; i--)
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
int bs_sqrt(int n){
    int ans=0;
    int left=0,right=2000000123;
    while(left<right){
        int mid=left+ (right- left)/2;
        if(mid*mid > n){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    return left-1;
}


void solve()
{
    int n;
    cin>>n;
    v64 pos,neg,a;
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        s.insert(val);
        if(val<0){
            neg.push_back(val);
        }
        else if(val>0){
            pos.push_back(val);
        }
        else{
            if(a.size()<2){
                a.push_back(val);
            }
        }
    }
    
    if(pos.size()>2||neg.size()>2){
        cout<<"NO\n";
        return;
    }
    for(auto x:neg){
        a.push_back(x);
    }
    for(auto x:pos){
        a.push_back(x);
    }
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            for(int k=j+1;k<a.size();k++){
                char ok=false;
                if(s.find(a[i]+a[j]+a[k])!=s.end()){
                    ok=true;
                }
                if(!ok){
                    cout<<"NO\n";return;
                }
            }
        }
    }
    cout<<"YES\n";

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
