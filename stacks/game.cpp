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
int findTheWinner(int n, int k) {
        deque<int> dq;
        for(int i=0;i<n;i++){
            dq.push_back(i+1);
        }
        //print_deque(dq);
        while(dq.size()!=1){
            dq.push_back(dq.front());
            dq.pop_front();
            for(int i=0;i<k-1;i++){
                dq.pop_front();
            }
            dq.push_back(dq.front());
            dq.pop_front();
            //print_deque(dq);
        }
        return dq.front();
        //cout<<dq.front()<<endl;
}

int main(){
    int ans=findTheWinner(6,2);
    cout<<ans<<endl;
}