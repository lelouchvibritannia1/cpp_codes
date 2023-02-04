#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return (a>b)?a:b;
}

int knapsack(int arr[],int sum,int n){
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        t[i][0]=1;
    }
    for(int i=1;i<sum+1;i++){
        t[0][i]=0;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int subsetGivenDiff(int arr[],int n,int diff){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    int k=(int)(diff+sum)/2;
    return knapsack(arr,k,n);
}

int main(){
    int arr[]={1,1,2,3};
    cout<<subsetGivenDiff(arr,4,1)<<endl;
}