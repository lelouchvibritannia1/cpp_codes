#include<bits/stdc++.h>
#include<iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9 + 7;
double eps = 1e-8;

#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ln '\n' 

string solve(int x,int y){
    return (x*2>5*y)?"Chocolate":(x*2<5*y)?"Candy":"Either";
}
int main()
{
	fast_cin();
	ll t;
	cin >> t; 
	string ans; 
	//your code here
    while(t--){
        int x,y; 
        cout<<solve(x,y)<<endl;  
        }
   return 0; 
  }
