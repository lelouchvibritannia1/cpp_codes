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

int main(){
    int t;
    cin>>t;
    int i=1;
    while(i<=t){
        int n,r;
        cin>>n>>r;
        unordered_map<int,vector<int>> mp;
        bool flag=false;
        for(int i=0;i<n;i++){
            int temp1,temp2;
            cin>>temp1>>temp2;
            auto it=mp.find(temp2);
            if(it!=mp.end()){
                auto temp=it->second;
                auto it2=find(temp.begin(),temp.end(),temp1);
                if(it2!=temp.end()){
                    flag=false;
                    
                }
            }
            else if(it==mp.end()){
                mp[temp2].push_back(temp2);
            }
        }
        cout<<"Scenario #"<<i<<":";
        if(flag) cout<<"possible"<<endl;
        else cout<<"impossible"<<endl;
        i++;
    }
}