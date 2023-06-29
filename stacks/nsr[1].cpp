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
typedef stack<ll> s64;
typedef stack<int> s32;
ll MOD = 1e9 + 7;
double eps = 1e-8;



v64 nsr(v64 p){
    int n=p.size();
    s64 s;
    v64 v(n);
    bool fl=s.empty();
    for(int i=n-1;i>=0;i--){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top()<p[i]){
            v.push_back(s.top());
        }
        else if(s.size()>0 && s.top()>=p[i]){
            while(s.size()>0 && s.top()>=p[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
            }
        }
        s.push(p[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}

int main(){
    v64 v1={1,3,2,4};
    v64 v2=nsr(v1);
    int i=0;
    for(auto x:v2){
        if(i++ < v1.size()) cout<<x<<" ";
        else break;
    }
    cout<<endl;
}