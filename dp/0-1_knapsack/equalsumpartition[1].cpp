#include <iostream>
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

bool equalSumPartition(int arr[],int n){
    int sum=0;
    for(int i=0;i<=n-1;i++){
        sum=sum+arr[i];
    }
    if(sum%2!=0){
        return false;
    }
    else{
        return knapsack(arr,sum/2,n);
    }
}

int main(){
    int arr[]={2,5,12,5};
    cout<<equalSumPartition(arr,4);
}