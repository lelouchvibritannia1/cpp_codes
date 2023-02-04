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

void checkInclusion(string s1, string s2) {
        int k=s1.length();
        int i=0,j=0;
        if(s2.length()<s1.length()){
            //return false;
            cout<<"false"<<ln;
        }
        unordered_map<char,int> mp;
        for(auto it:s1){
            mp[it]++;
        }
        for(auto it:mp){
            cout<<(it.first)<<" "<<it.second<<ln;
        }
        int count=mp.size();
        cout<<count<<ln;
        while(j<s2.length()){
            if(mp.find(s2[j])!=mp.end()){
                mp[s2[i]]--;
                if(mp[s2[j]]==0){
                count--;
                cout<<count<<ln;
                }
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(count==0){
                   cout<<true<<endl;
                }
                if(mp.find(s2[j])!=mp.end() && mp[s2[j]]==0){
                    count++;
                    cout<<count<<ln;
                }
                mp[s2[i]]--;
                i++;
                j++;
            }
        }
        cout<<"reached end"<<ln;
        }

        int main(){
            checkInclusion("ab","eidboaoo");
        }