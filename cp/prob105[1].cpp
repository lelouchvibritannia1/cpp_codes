
#include<bits/stdc++.h>
#include<iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define int long long int
#define double long double
typedef pair<int,int> p64;
typedef pair<double,double> pdd;
typedef vector<int> v64;
typedef vector<vector<int> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
int MOD = 1e9 + 7;
double eps = 1e-8;
int MAX=1e5;
#define G(x) int x; cin >> x
#define GS(x) string x; cin >> x
#define F(i,l,r) for(int i=l;i<r;i++)
#define FD(i,r,l) for(int i=r;i>l;i--)
#define CO(x) cout << x << '\n'
#define CO_(x) cout << x << ' '
#define GA(x,n) v64 x(n); F(i,0,n) cin >> x[i]
#define CA(x,n) F(i,0,n) {CO_(x[i]);} cout << '\n'
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)




/*this here is code */



void solve(){
    int n;
    cin>>n;
    v64 a(n);
    F(i,0,n) cin>>a[i];
    int l=0,r=n-1,a_c=a[l],b_c=0,moves{1};
    int cur_size=a[l],flag=0;
    l++;
    while(l<=r){
            if(!flag){
                int s=0;
                while(s <= cur_size && r>l-1){
                    s+=a[r];
//                    cout<<a[r]<<" ";
                    r--;
                }
//                cout<<endl;
                b_c+=s;
                cur_size=s;
                moves++;
                flag=1;
//                cout<<s<<endl;
            }
            else{
                int s=0;
                while(s <= cur_size && r>l-1){
                    s+=a[l];
//                    cout<<a[l]<<" ";
                    l++;
                }
                a_c+=s;
                cur_size=s;
                moves++;
                flag=0;
//                cout<<s<<endl;
            }
    }
    cout<<moves<<" "<<a_c<<" "<<b_c<<endl;


}


int32_t main(){
    fast_cin();
    int t{1};
    cin>>t;
    while(t--) solve();
}
/*which ends here*/



