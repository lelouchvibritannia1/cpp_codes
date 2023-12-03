#include<bits/stdc++.h>
using namespace std;

#define int long long int

bool isValid(vector<int> a, int val, int k, int b){
    int n=a.size();
    int sum=0;
    int d=1;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>val){
            sum=a[i];
            d++;
        }
    }
    // cout<<1<<endl;
    if(d>k){
        return false;
    }
    else{
        return true;
    }
}


int32_t main(){
    int n,k,b;
    cin>>n>>k>>b;
    vector<int> a(n);
    int sum=0,mx=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        mx=max(mx,a[i]);
    }
    int lo=mx,hi=sum;
    int ans=-1;
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(isValid(a,mid,k,b)){
            ans=mid;
            hi=mid;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<(b-5*ans)<<endl;
}


