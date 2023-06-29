#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define v64 vector<int>
#define vv64 vector<v64>

int T[16][16];
int a[16];
int mod,d,n;

void multiply(int a[16][16],int b[16][16]){
    int r[16][16];
    memset(r,0,sizeof(r));
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            for(int k=0;k<d;k++){
                r[i][j]+=a[i][k]*b[k][j];
                r[i][j]%=mod;
            }
        }
    }
    memcpy(a,r,sizeof(r));
}

void pow(int a[16][16],int n){
    int r[16][16];
    // memset(r,0,sizeof(r));
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            a[i][j]=0;
            r[i][j]=T[i][j];
        }
        a[i][i]=1;
    }
    while(n>0){
        if(n&1) multiply(a,r);
        multiply(r,r);
        n/=2;
    }
}

int S(int x){
    int res=0;
    if(x<=n){
        for(int i=1;i<=x;i++){
            res+=a[n-i];res%=mod;
        }
    }
    else{
        int r[16][16];
        pow(r,x-n);
        for(int i=0;i<d;i++){
            res+=r[n][i]*a[i];res%=mod;
        }
    }
    return res;
}

void solve(){
    cin>>n;
    d=n+1;

    a[n]=0;
    for(int i=n-1;i>=0;i--){
        cin>>a[i];
        a[n]+=a[i];
    }

    memset(T,0,sizeof(T));

    for(int i=1;i<n;i++){
        T[i][i-1]=1;
    }

    for(int i=0;i<n;i++){
        cin>>T[0][i];
        T[n][i]=T[0][i];
    }

    T[n][n]=1;

    int a,b;
    cin>>a>>b>>mod;

    cout<<(S(b)-S(a-1)+mod)%mod<<endl;


}
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;while(t--) solve();
}