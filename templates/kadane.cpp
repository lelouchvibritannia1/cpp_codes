#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int kadane(vector<int>& nums) {
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int best_sum=INT_MIN;
        int curr_sum=0;
        for(auto x:nums){
            curr_sum=max(x,curr_sum+x);
            best_sum=max(curr_sum,best_sum);
        }
        return best_sum;
}