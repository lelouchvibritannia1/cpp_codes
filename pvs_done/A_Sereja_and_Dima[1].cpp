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
typedef stack<pair<int,int>> sp32;
typedef unordered_map<int,int> ump32;
ll MOD = 1e9 + 7;
double eps = 1e-8;


void solve(){
    int n;
    cin>>n;
    deque<int> dq;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        dq.push_back(temp);
    }
    bool k=true;
    int s=0,d=0;
    while(dq.size()!=0){
        if(k){
            if(dq.front()>dq.back()){
                s+=dq.front();
                dq.pop_front();
            }
            else{
                s+=dq.back();
                dq.pop_back();
            }
            k=!k;
        }
        else{
            if(dq.front()>dq.back()){
                d+=dq.front();
                dq.pop_front();
            }
            else{
                d+=dq.back();
                dq.pop_back();
            }
            k=!k;
        }
    }
    cout<<s<<" "<<d<<endl;
}

int main(){
    solve();
}