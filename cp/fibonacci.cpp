#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define MAX (int)(1e6+5)
#define MOD (int)(1e9+7)
#define sz 2

struct Mat{
    int m[sz][sz];
    Mat(){
        memset(m,0,sizeof(m));
    }

    void identity(){
        for(int i=0;i<sz;i++){
            m[i][i]=1;
        }
    }
    // overloading operator
    Mat operator* (Mat a){
        Mat res;
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                for(int k=0;k<sz;k++){
                    res.m[i][j]+=m[i][k]*a.m[k][j];
                    res.m[i][j]%=MOD;
                }
            }
        }
        return res;
    }
};

int Fib(int n){
    Mat res;
    res.identity();
    Mat T;
    T.m[0][0]=T.m[0][1]=T.m[1][0]=1;

    if(n==0) return 0;
    if(n==1) return 1;
    n-=2;

    //log n
    while(n){
        if(n&1) res=res*T;
        T=T*T;
        n/=2;
    }

    return(res.m[0][0]+res.m[0][1])%MOD;
}


int32_t main(){
    int n;
    cin>>n;
    cout<<Fib(n)<<endl;
}