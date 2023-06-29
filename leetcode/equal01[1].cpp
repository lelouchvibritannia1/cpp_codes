#include<bits/stdc++.h>
using namespace std;

void findMaxLength(vector<int>& nums) {
        unordered_map <int,set<int>> mp;
        int rs=0;
        for(int i=0;i<nums.size();i++){
            cout<<rs<<endl;;
            rs+=(nums[i]==1)?1:-1;
            mp[rs].insert(i);
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            cout<<it->first<<":";
            for(auto it1=it->second.begin();it1!=it->second.end();it1++){
                cout<<*it1<<" ";
            }
            cout<<endl;
        }
        if (rs==0){cout<<nums.size()<<endl;}
        int ans=INT_MIN;
        for(auto it=mp.begin();it!=mp.end();it++){
            cout<<*((it->second).crbegin())-*((it->second).begin())<<endl;
            ans=max(ans,*((it->second).crbegin())-*((it->second).begin()));
            cout<<ans<<endl;
        }
        cout<<ans<<endl;
}

int main(){
    vector<int> nums={0,1};
    findMaxLength(nums);

}