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



// ump32 ngl(v64 p){
//     ump32 mp1;
//     int n=p.size();
//     for(int i=0;i<n;i++){
//         mp1[p[i]]=i;
//     }
    
//     s64 s;
//     ump32 mp;
//     bool fl=s.empty();
//     for(int i=0;i<n;i++){
//         if(s.size()==0){
//             mp[p[i]]=-1;
//         }
//         else if(s.size() > 0 && s.top()>p[i]){
//             mp[p[i]]=mp1[s.top()];
//         }
//         else if(s.size()>0 && s.top()<=p[i]){
//             while(s.size()>0 && s.top()<=p[i]){
//                 s.pop();
//             }
//             if(s.size()==0){
//                mp[p[i]]=-1;
//             }
//             else{
//                 mp[p[i]]=mp1[s.top()];
//             }
//         }
//         s.push(p[i]);
//     }
//     //reverse(v.begin(),v.end());
//     return mp;
// }

// v64 span(v64 p){
//     ump32 m=ngl(p);
//     int n=p.size();
//     v64 ans;
//     for(int i=0;i<n;i++){
//         if(m[p[i]]==-1){
//             ans.push_back(i+1);
//         }
//         else{
//             ans.push_back(abs(i-m[p[i]]));
//         }
//     }
//     return ans;
// }

v64 ngl(v64 p){
    int n=p.size();
    sp32 s;
    v64 v;
    bool fl=s.empty();
    for(int i=0;i<n;i++){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top().first>p[i]){
            v.push_back(s.top().second);
        }
        else if(s.size()>0 && s.top().first<=p[i]){
            while(s.size()>0 && s.top().first<=p[i]){
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
    return v;
}


int main(){
    v64 v1={100,80,60,70,60,75,85};
    v64 v2=ngl(v1);
    int i=0;
    for(;i<v2.size();i++){
        cout<<(i-v2[i])<<" ";
    }
    cout<<endl;
}