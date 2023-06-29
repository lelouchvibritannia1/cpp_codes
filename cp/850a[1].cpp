 #include "bits/stdc++.h"
// #include<iostream>
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



void init_code(){
    fast_cin();
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

}



/*this here is code */



void solve(){
    G(n);
    v64 v(n,1);
    int aw=1,ab=0,bw=0,bb=0,r=5,k=2;
    bool flag=true;
    for(int i=1;i<n;i++){
        if(flag){
            if(i<r){
                if(i%2){
                    bb+=v[i];
                }
                else{
                    bw+=v[i];
                }

                
            }
            if(i==r){
                if(i%2){
                    bb+=v[i];
                }
                else{
                    bw+=v[i];
                }                
                r+=4*k+1;
                k++;
                flag=false;
            }
            
        }
        else{
            if(i<r){
                if(i%2){
                    ab+=v[i];
                }
                else{
                    aw+=v[i];
                }
            }
            if(i==r){
                if(i%2){
                    ab+=v[i];
                }
                else{
                    aw+=v[i];
                }
                r+=4*k+1;
                k++;
                flag=true;
            }            
        }
    }

    cout<<aw<<" "<<ab<<" "<<bw<<" "<<bb<<endl;;
}


int32_t main(){
    init_code();
    int t{1};
   cin>>t;
    while(t--) solve();
}
/*which ends here*/
