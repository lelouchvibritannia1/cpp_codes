#include<bits/stdc++.h>
using namespace std;
#define int long long int


int pow(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
            res*=a;
        }
        a*=a;
        b>>=1;
    }
    return res;

}

void solve(){
    int n;
    cin>>n;

    set<int> s;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int p{i},q{0},c{1},ans{0};
            while(n%p==0){
                n=n/p;
                q++;
                if(q==c){
                    ans++;c++;q=0;
                }
            }
        }
    }

    if(s.size()>=3){
        cout<<"YES"<<endl;
        int a=*s.begin();
        int b=*(++s.begin());
        cout<<a<<" "<<b<<" "<<(n/(a*b))<<endl;

    }

    else{
        cout<<"NO"<<endl;
        return;
    }
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}