#include <bits/stdc++.h>
using namespace std;
#define int long long

int balancedSum(vector<int> arr){
    int n=arr.size();
    vector<int> prefix(n,arr[0]);
    for(int i=1;i<n;i++){
        prefix[i]=arr[i]+prefix[i-1];
    }
    vector<pair<int,int>> m;
    for(int i=1;i<n-1;i++){
        if(prefix[i]==prefix[n-1]-prefix[i-1]){
            m.push_back({arr[i],i});
        }
    }
    stable_sort(m.begin(),m.end());
    return m[0].second;
}
int32_t main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<balancedSum(arr)<<"\n";
}