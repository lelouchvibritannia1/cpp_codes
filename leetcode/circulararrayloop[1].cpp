#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> a,vector<int> b,int k);

bool circularArrayLoop(vector<int>& nums) {
    int k=nums.size();
    vector<int> color(nums.size());
    while(k--){
        color[k]=0;
    }
    for(int i=0;i<k;i++){
        if(color[i]==0 && dfs(nums,color,i)==true){
            return true;
        }
    }
    return false;
}

bool dfs(vector<int> nums,vector<int> color,int begin){
    int k=nums.size();
    if(color[begin]==2){
        return false;
    }
    color[begin]=1;
    int next=((begin+nums[begin])<0)?((begin+nums[begin]+k)%k):(begin+nums[begin])%k;
    if(next==begin || nums[begin]*nums[next]<0){
        color[next]=2;
        return false;
    }
    if(color[next]==1){
        color[begin]=2;
        return true;
    }
    if(dfs(nums,color,next)) return true;
    color[begin]=2;
    return false;
}

int main(){
    vector<int> num={1,-1,5,1,4};
    cout<<circularArrayLoop(num);
}