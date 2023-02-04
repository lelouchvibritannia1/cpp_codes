#include <bits/stdc++.h>
using namespace std;

int t[101][101]; //given the constraints are n<=100, w<=100

int knapsack_ub(int wt[],int W,int n){

    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0||j==0){
                    t[i][j]=0;
            }
            else if(wt[i-1]<=j){
                t[i][j]=max(t[i][j-wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][W];
}

int main(){
    int wt[]={1,3,4,5};
  
    cout<<knapsack_ub(wt,11,4);
}