
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
    GA(x,n);
    vector<int> odd,even;
    for(int i=0;i<n;i++){
        if(x[i]%2) odd.push_back(i);
        else even.push_back(i);
    }
    if(odd.size() >= 3){
        cout<<"YES"<<endl;
        F(i,0,3){
                cout<<odd[i]+1<<" ";
        }
        cout<<endl;
    }
    else{
        if(odd.size()==0){
            cout<<"NO"<<endl;
        }
        else if(odd.size()==1){
            cout<<"YES"<<endl;
            cout<<odd[0]+1<<" ";
            for(int i=0;i<2;i++){
                cout<<even[i]+1<<" ";
            }
            cout<<endl;
        }
        else if(odd.size() == 2){
            if(even.size()<2){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
                cout<<odd[0]+1<<" ";
                F(i,0,2){
                    cout<<even[i]+1<<" ";
                }
                cout<<endl;
            }
        }
    }

}


int32_t main(){
    fast_cin();int t;cin>>t;while(t--) solve();
}
/*which ends here*/
