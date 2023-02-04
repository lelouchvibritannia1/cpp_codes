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

void print_stack(stack <char> dq){
    while(dq.size()>0){
        cout<<dq.top()<<" ";
        dq.pop();
    }
    cout<<endl;
}

void removeDuplicates(string s1, int k) {
        stack<char> s;
        int flag=k;
        for(int i=0;i<s1.size();i++){
            int flag2=1;
            while(s.size()>0 && s.top()==s1[i] && flag!=1){
                s.push(s1[i]);
                flag--;
            }
            if(s.size()>0 && s.top()==s1[i] && flag==1){
                while(k--){
                    s.pop();
                }
                flag=k;
            }
            if(s.empty() || s.top()!=s1[i]){
                s.push(s1[i]);
            }
            print_stack(s);
            
        }
        
        // string ans="";
        // while(s.size()>0){
        //     ans+=s.top();
        //     s.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;
        
    }

    int main(){
        removeDuplicates("aaaaaaaaaaaabbbbbbbbbbbbcccccccccccccccccddddddddddeeeeeeeeeeeedddddddddd",6);
    }