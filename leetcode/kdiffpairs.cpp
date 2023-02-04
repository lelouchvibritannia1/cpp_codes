#include<bits/stdc++.h>
using namespace std;

int findPairs(vector<int>& nums,int k){
    unordered_map<int,int> mp;
    int ans=0;
    for(auto x:nums){
        mp[x]++;
    }
    for(auto x:mp){
        if(k==0){
            if(x.second>=2){
                ans++;
            }
        }
        else if(k!=0){
            if(mp.find(x.first+k)!=mp.end()){
                ans++;
            }
        }
    }
    return ans;
}


int main(){
    vector<int> nums={1,2,3,1,5};
    cout<<findPairs(nums,2)<<endl;
}