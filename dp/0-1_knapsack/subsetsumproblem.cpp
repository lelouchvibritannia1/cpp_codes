#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return (a>b)?a:b;
}

bool knapsack(int arr[],int sum,int n){
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        t[i][0]=true;
    }
    for(int i=1;i<sum+1;i++){
        t[0][i]=false;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            
            if(arr[i-1]<=j){
                t[i][j]=((t[i-1][j-arr[i-1]])||(t[i-1][j]));
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

bool isSubsetSum(vector<int>& arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(arr[0]<=sum) dp[0][arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notTake=dp[i-1][j];
                bool take=false;
                if(arr[i]<=j) take=dp[i-1][j-arr[i]];
                dp[i][j]=notTake|take;
            }
        }
        return dp[n-1][sum];
    }

    bool isSubsetSumSpace(vector<int>& arr, int sum){
        // code here 
        int n=arr.size();
        vector<bool> prev(sum+1,0),curr(sum+1,0);
        prev[0]=curr[0]=true;
        if(arr[0]<=sum) prev[arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notTake=prev[j];
                bool take=false;
                if(arr[i]<=j) take=prev[j-arr[i]];
                curr[j]=notTake|take;
            }
            prev=curr;
        }
        return prev[sum];
    }

int main(){
    vector<int> arr={2,3,8,7,10};
    cout<<isSubsetSumSpace(arr,2000);
}