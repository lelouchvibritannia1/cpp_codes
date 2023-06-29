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

int combi(int n,int k)
{
    int ans=1;
    k=k>n-k?n-k:k;
    int j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}

void solve(){
    string s1, s2;
    cin>>s1;
    cin>>s2;
    int final_pos=count(s1.begin(),s1.end(),'+') - count(s1.begin(),s1.end(),'-');
    int s2_pos=count(s2.begin(),s2.end(),'+') - count(s2.begin(),s2.end(),'-');
    int p = count(s2.begin(),s2.end(),'?');
    if(final_pos - s2_pos == 0 && p==0){
         cout<<fixed<<setprecision(9)<<(double)(1)<<endl;
         return;
    }
    else if(abs(final_pos - s2_pos) > p || final_pos != s2_pos && p==0){
        cout<<fixed<<setprecision(9)<<(double)0<<endl;
    }
    else{
        double ans;
        int dif=abs(final_pos - s2_pos);
        if(dif%2){
            if(!p%2){
                cout<<fixed<<setprecision(9)<<(double)0<<endl;
            }
            else{
                int i;
                for(i=1;i<=p;i++){
                    if(i - (p - i) == dif ){
                        break;
                    }
                }
                ans=combi(p,i)*pow(0.5,p);
                 cout<<fixed<<setprecision(9)<<ans<<endl;

            }

        }
        else{
            if(p%2){
                cout<<fixed<<setprecision(9)<<(double)0<<endl;
            }
            else{
                int i;
                for(i=0;i<=p;i++){
                    if(i - (p - i) == dif ){
                        break;
                    }
                }

                ans=combi(p,i)*pow(0.5,p);
                }
//                cout<<i<<endl;
                 cout<<fixed<<setprecision(9)<<ans<<endl;
//                 cout<<combi(10,4)*pow(0.5,10)<<endl;

            }
        }
    }






int32_t main(){
    fast_cin();int t=1;
//    cin>>t;
    while(t--) solve();
}
/*which ends here*/

