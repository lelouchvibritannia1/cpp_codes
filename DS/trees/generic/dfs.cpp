#include<bits/stdc++.h>
using namespace std;


const int N=1e5;

vector<int> gr[N];


void dfs(int cur, int par){
    for(auto x:gr[cur]){
        if(x!=par){
            dfs(x,cur);
        }
    }
}