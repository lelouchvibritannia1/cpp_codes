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

v64 nsl(v64 p){
    int n=p.size();
    sp32 s;
    v64 v;
    bool fl=s.empty();
    for(int i=0;i<n;i++){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top().first<p[i]){
            v.push_back(s.top().second);
        }
        else if(s.size()>0 && s.top().first>=p[i]){
            while(s.size()>0 && s.top().first>=p[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top().second);
            }
        }
        s.push({p[i],i});
    }
    //reverse(v.begin(),v.end());
    v[0]=-1;
    return v;
}

v64 nsr(v64 p){
    int n=p.size();
    sp32 s;
    v64 v;
    bool fl=s.empty();
    for(int i=n-1;i>=0;i--){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top().first<p[i]){
            v.push_back(s.top().second);
        }
        else if(s.size()>0 && s.top().first>=p[i]){
            while(s.size()>0 && s.top().first>=p[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top().second);
            }
        }
        s.push({p[i],i});
    }
    reverse(v.begin(),v.end());
    v[n-1]=n;
    return v;
}

int mah(v64 p){
    v64 width;
    v64 right=nsr(p);
    v64 left=nsl(p);
    ll ans=INT64_MIN;
    for(int i=0;i<p.size();i++){
        width.push_back(right[i]-left[i]-1);
        ans=max(ans,p[i]*width[i]);
    }
    return ans;
}

int main(){
    v64 v1={2,1,1,2};
    v64 v2=nsl(v1);
    v64 v3=nsr(v2);
    for(auto x:v2){
        cout<<x<<" ";
    }
    cout<<"\n";
    for(auto x:v3){
        cout<<x<<" ";
    }
    cout<<mah(v1)<<endl;
}