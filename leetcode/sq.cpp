class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]*nums[i]);
        }
        vector<int> ans(s.begin(),s.end());
        return ans;
       
        
    }
};