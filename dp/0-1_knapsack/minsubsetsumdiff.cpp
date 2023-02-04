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

int minimumSubsetSumDiff(int arr[],int n){
    int sum=0,ans=INT_MAX;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    vector<int> possibleSums;
    for(int i=0;i<sum;i++){
        if(knapsack(arr,i,n)){
            possibleSums.push_back(i);
        }
    }
    for(int i=0;i<=possibleSums.size()/2;i++){
        ans=min(ans,(sum-2*possibleSums[i]));
    }
    return ans;

}

int main(){
    int arr[]={1,2,7};
    cout<<minimumSubsetSumDiff(arr,3);
}