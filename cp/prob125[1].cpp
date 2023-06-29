#include "bits/stdc++.h"
// #include<iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define int long long 
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
    freopen("error.txt","w",stderr);
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

int sod(int n){
    int s=0;
    while(n!=0){
        int d=n%10;
        s+=d;
        n/=10;
    }
    return s;
}

void solve()
{
    int n;
    cin>>n;
    if(n==1)    cout<<1<<" "<<0<<"\n";
    else if(n%2==0){
        cout<<n/2<<" "<<n/2<<endl;
        return;
    }
    else{
        if(n%10==9){
            string s=to_string(n);
            bool greater=false;
            string s1="",s2="";
            for(int i=0;i<s.length();i++){
                int v=s[i]-'0';
                if(v%2==0){
                    s1+=to_string(v/2);
                    s2+=to_string(v/2);
                }
                else{
                    if(greater){
                        s1+=to_string(v/2+1);
                        s2+=to_string(v/2);
                        greater=!greater;
                    }
                    else{
                        s2+=to_string(v/2+1);
                        s1+=to_string(v/2);
                        greater=!greater;
                    }
                }
            }
            int i=0;
            int ok=true;
            for(i=0;i<s1.size();i++){
                if(s1[i]=='0' && ok==true){
                    continue;
                }
                else{
                    break;
                }
            }
            s1=s1.substr(i,s1.size());
            cout<<s1<<" "<<s2<<"\n";
            return;
        }
        else{
            cout<<n/2<<" "<<(n/2+1)<<endl;
            return;
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
