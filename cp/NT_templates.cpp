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


vector<bool> prime(MAX,true);
void sieve(){
    prime[0]=prime[1]=false;
    for(int i=2;i*i<MAX;i++){
        if(prime[i]){
            for(int j=i*i;j<MAX;j+=i){
                prime[j]=false;
            }
        }
    }
}

// int gcd(int a,int b){
//     if(b==0) return a;
//     else return gcd(b,a%b);
// }

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

int extended_eucledean(int a,int b,int &x,int &y){
    if(b==0){
        x=1;y=0;return a;
    }
    int x1,y1;
    int d=extended_eucledean(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

int binpowrec(int a,int b){
    if(b==0) return 1;
    int res=binpowrec(a,b/2);
    if(b%2==0) return res*res;
    else return res*res*a;
}

int binpowitera(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
            res=res*a;
        }
        a=a*a;
        b>>=1;
    }
    return res;
}

int binpowmodm(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
            res*=a;res%=MOD;
        }
        a=a*a;a%=MOD;
        b>>=1;
    }
    return res%MOD;
}
// given a,b,c<=10^15
int fast_multiplication(int a,int b,int c){
    int res=0;
    while(b>0){
        if(b&1){
            res+=a;res%=c;
        }
        a+=a;a%=c;
        b>>=1;
    }
    return res%c;
}




int Fib(int n){
    Mat res;
    res.identity();
    Mat T;
    T.m[0][0]=T.m[0][1]=T.m[1][0]=1;

    if(n<=2) return 1;
    n-=2;

    //log n
    while(n){
        if(n&1) res=res*T;
        T=T*T;
        n/=2;
    }

    return(res.m[0][0] + res.m[0][1])%MOD;
}


int32_t main(){
}