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

string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int m=INT_MAX;
        bool flag=true;
        for(int i=0;i<strs.size();i++){
            if(m<=strs[i].size()){
                m=strs[i].size();
            }
        }
        for(int i=0;i<m;i++){
            if(strs[i].find(strs[0][0])!=string::npos){
                ans+=strs[0][0];
            }
            else{
                flag=false;
                break;
            }
        }
        if(!flag){
            return "";
        }
        else{
            return ans;
        }
}

int main(){
    
}