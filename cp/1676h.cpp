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

int merge(int a[],int temp[],int l,int m,int r){
    int c=0;
    int k=l;
    int i=l,j=m;
    while((i<=m-1) && (j<=r)){
        if(a[i]>a[j]){
            temp[k++]=a[j++];
            c+=(m-i);
        }
        else{
            temp[k++]=a[i++];
        }
    }
    while(i<=m-1){
        temp[k++]=a[i++];
        
    }
    while(j<=r){
        temp[k++]=a[j++];
    }
    for(i=l;i<=r;i++){
        a[i]=temp[i];
    }
    return c;
}

int mergeSort(int a[],int temp[],int l,int r){
    int m;
    int c=0;
    if(r>l){
        m=l+(r-l)/2;
        c=mergeSort(a,temp,l,m);
        c+=mergeSort(a,temp,m+1,r);
        c+=merge(a,temp,l,m+1,r);
    }
    return c;
}

int inv(int a[],int n){
    int temp[n];
    return mergeSort(a,temp,0,n-1);
}



void solve()
{   
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int res=inv(a,n);
    sort(a,a+n);
    int cur=1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){res+=(cur*(cur-1))/2; cur=1;}
        else cur++;
    }
    res+=(cur*(cur-1))/2;
    cout<<res<<endl;
    
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

