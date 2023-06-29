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


void print_deque(deque<int> dq){
    while(dq.size()!=0){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    cout<<endl;
}

void canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        deque<int> dq;
        int curr=0,i=0;
        bool flag=true;
        int ans=0;
        while(flag){
            ans=i;
            if(flag && i==n-1){
                break;
            }
            curr+=(gas[i]-cost[i]);
            if(curr>0){
                dq.push_back(i);
            }
            else if(curr<0){
                dq.pop_front();
            }
            if(dq.size()==n && curr>=0){
                flag=false;
                break;
            }
            i=(i+1)%n;
            print_deque(dq);
        }
        if(!flag){
           cout<<ans+1<<endl;
        }
        else{
            cout<<-1<<endl;
        }
}

int main(){
    vector<int> v1={50,10,60,100};
    vector<int> v2={30,20,100,10};
    canCompleteCircuit(v1,v2);
    cout<<endl;
}