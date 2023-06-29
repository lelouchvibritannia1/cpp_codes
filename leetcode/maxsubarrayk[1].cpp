#include<bits/stdc++.h>
using namespace std;

int maxSubArrayk(vector<int> nums){
    int ans=0;
    int n=nums.size();
    unordered_map<int,int> mp;
    int rs=sum[0];
    for(int i=0;i<n;i++){
        rs=rs+sum[i];
        auto it=mp.find(rs);
        if(rs!=mp.end())
    }
}