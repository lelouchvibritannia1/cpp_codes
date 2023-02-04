#include "bits/stdc++.h"
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
// int MOD = 1e9 + 7;
const int MOD=998244353;
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

string PROD(string num1, string num2) {
   if (num1 == "0" || num2 == "0") {
      return "0";
   }
   string product(num1.size() + num2.size(), 0);
   for (int i = num1.size() - 1; i >= 0; i--) {
      for (int j = num2.size() - 1; j >= 0; j--) {
            int n = (num1[i] - '0') * (num2[j] - '0') + product[i + j + 1];
            product[i + j + 1] = n % 10;
            product[i + j] += n / 10;
      }
   }
   for (int i = 0; i < product.size(); i++) {
      product[i] += '0';
   }
   if (product[0] == '0') {
      return product.substr(1);
   }
   return product;
}

int calcRem(string num, int R){
   int currDigit, rem = 0;
   for (int i = 0; i < num.length(); i++) {
      currDigit = rem * 10 + (num[i] - '0');
      rem = currDigit % R;
   }
   return rem;
}



void solve(){
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    string mn(n*n,'9');
    for(int i=0;i<n;i++){
        swap(s1[i],s2[i]);
        mn=min(mn,PROD(s1,s2));
        swap(s1[i],s2[i]);
    }
    cout<<mn<<endl;
//    cout<<calcRem(mn,MOD)%MOD<<endl;
    cout<<stoll(mn) % MOD<<endl;

}


int32_t main(){
    fast_cin();
    int t{1};
    // cin>>t;
    while(t--) solve();
}
/*which ends here*/
