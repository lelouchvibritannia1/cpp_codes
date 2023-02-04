#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vv64 vector<vector<int>>
#define v64 vector<int>
#define MOD (int)(1e9+7)
#define sz 10

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

Mat pow(Mat T,int n){
    Mat res;
    res.identity();
    while(n){
        if(n&1) res=res*T;
        T=T*T;
        n>>=1;
    }

    return res;
}



int32_t main(){

}