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
#define FD(i,r,l) for(int i=r;i>=l;i--)
#define CO(x) cout << x << '\n'
#define CO_(x) cout << x << ' '
#define GA(x,n) v64 x(n); F(i,0,n) cin >> x[i]
#define CA(x,n) F(i,0,n) {CO_(x[i]);} cout << '\n'
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void init_code(){
    fast_cin();
//   #ifndef ONLINE_JUDGE
//   // for getting input from input.txt
//   freopen("input.txt", "r", stdin);
//   // for writing output to output.txt
//   freopen("output.txt", "w", stdout);
//   #endif
}


/*this here is code */
//based on the fact that if a segment of a (increasing)sorted array is reversed, the array is like incr->decr->incr.


const int N=1e5+5;
int a[N],b[N];

void solve(){
    G(n);
    F(i,0,n){
        cin>>a[i];
        b[i]=a[i];
    }
    map<int,int> mp;
    sort(b,b+n);
    F(i,0,n){
        mp[b[i]]=i;
    }
    F(i,0,n){
        a[i]=mp[a[i]];
    }
    int L=-1;
    F(i,0,n){
        if(a[i]!=i){
            L=i;break;
        }
    }
    int R=-1;
    FD(i,n-1,0){
        if(a[i]!=i){
            R=i;break;
        }
    }
    if(L==-1 || R==-1){
        cout<<"yes"<<endl;
        cout<<1<<" "<<1<<endl;
    }
    else{
        reverse(a+L,a+R+1);
        bool ok=true;
        F(i,0,n){
            if(a[i]!=i){
                ok=false;
            }
        }
        if(ok){
            cout<<"yes"<<endl;
            cout<<L+1<<" "<<R+1<<endl;
        }
        else{
            cout<<"no"<<endl;
        }

    }

}
int32_t main(){
    init_code();
    int t;
    cin>>t;
    while(t--) solve();
}
/*which ends here*/
