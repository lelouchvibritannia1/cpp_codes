#include <bits/stdc++.h>
using namespace std;

int rwt(int heights[], int n){
    int maxl[n];
    int maxr[n];
    maxl[0]=heights[0];
    for(int i=1;i<n;i++){
        maxl[i]=max(maxl[i-1],heights[i]);
    }
    maxr[n-1]=heights[n-1];
    for(int i=n-2;i>=0;i--){
        maxr[i]=max(maxr[i+1],heights[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+(min(maxl[i],maxr[i])-heights[i]);
    }
    return sum;
}

int main(){
    int h[]={3,0,0,2,0,4};
    cout<<rwt(h,6);
}
