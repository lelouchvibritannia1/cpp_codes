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

void print_pq(priority_queue<int> dq){
    while(dq.size()>0){
        cout<<dq.top()<<" ";
        dq.pop();
    }
    cout<<endl;
}

// void solve(vector<pair<int,bool>>& arr,int n){
    // priority_queue<pair<int,bool>> pq(arr.begin(),arr.end());
    // int prev=-1;
    // for(int i=0;i<n;i++){
    //     pq
    //     if(arr[i].first!=pq.top().first){
    //         cout<<endl;
    //     }
    //         else{
    //         int k=i-prev;
	// 		// int temp=pq.top();
    //         while(k-- && pq.top().second){
    //             cout<<pq.top().first<<" ";
    //             pq.pop();
	// 			// temp--;
    //         }
    //         cout<<endl;
    //         prev=i;
    //     }
    //     // print_pq(pq);
    // }
// }


// 




void solve(vector<int>& arr,int n){
    map<int,bool> mp;
    for(int i=0;i<n;i++){
        mp[-arr[i]]=false;
    }
    for(int i=0;i<n;i++){
        mp[-arr[i]]=true;
        if(-arr[i] != (mp.begin()->first)){
            cout<<endl;
        }
        else{
            // int temp=mp.begin()->first;
            while(mp.begin()->second){
                cout<<-mp.begin()->first<<" ";
                mp.erase(mp.begin());
            }
            cout<<endl;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr,n);
}