#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),zero,one;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i{0};i<n;i++){
        int x;
        cin>>x;
        if(x==0){
            zero.push_back(a[i]);
        }
        else{
            one.push_back(a[i]);
        }
    }
    if(zero.size() == 0 && !is_sorted(one.begin(),one.end())){
        cout<<"No"<<endl;
        return;
    }
    else if(one.size() == 0 && !is_sorted(zero.begin(),zero.end())){
        cout<<"No"<<endl;
        return;
    }
    else{
        cout<<"Yes"<<endl;
    }

}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
