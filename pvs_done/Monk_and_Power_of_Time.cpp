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
typedef deque<int> d32;
typedef deque<ll> d64;
ll MOD = 1e9 + 7;
double eps = 1e-8;

int solution(v32& calling,v32& ideal){
    int n=calling.size();
    int ans=0;
    d32 dq1,dq2;
    for(int i=0;i<n;i++){
        dq1.push_back(calling[i]);
        dq2.push_back(ideal[i]);
    }
    while(dq2.size()!=0){
        //int prev=0;
        if(dq1.front() != dq2.front()){
            dq1.push_back(dq1.front());
            dq1.pop_front();
        }
        else if(dq1.front()==dq2.front()){
            dq1.pop_front();
            dq2.pop_front();
        }
        ans++;
    }
    return ans;

}

int main(){
    int n;
    cin>>n;
    v32 c(n);
    v32 ide(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        cin>>ide[i];
    }
    cout<<solution(c,ide)<<endl;
}