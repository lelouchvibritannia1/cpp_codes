 #include "bits/stdc++.h"
using namespace std;

#define int long long int
int32_t main(){
    int n,x;
    cin>>n>>x;
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];
    int ans=0;
    ans+=c[0]+c[n-1];
    int nskr=0;
    for(int i=1;i<n-1;i++){
        if(c[i]<=x || nskr>=3){
            ans+=c[i];
            nskr=0;
        }
        else{
            if(c[i]>x && nskr<=3){
                ans+=x;
                nskr++;
            }
        }
    }
    cout<<ans<<endl;
}
