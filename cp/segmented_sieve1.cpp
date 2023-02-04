#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


//counting no. of primes within 1 to n using block sieveing
ll count_primes(ll n){
    const ll S=10000;

    vector<ll> primes;
    ll nsqrt=sqrt(n);
    vector<char> is_prime(nsqrt+2,true);
    for(int i=2;i<=nsqrt;i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j=i*i;j<=nsqrt;j+=i){
                is_prime[j]=false;
            }
        }
    }

    ll result=0;
    vector<char> block(S);
    for(int k=0;k*S<=n;k++){
        fill(block.begin(),block.end(),true);
        int start=k*S;
        for(int p:primes){
            int start_idx=(start+p-1)/p;
            int j=max(start_idx,p)*p-start;
            for(;j<S;j++){
                block[j]=false;
            }
        }

        if(k==0){
            block[0]=block[1]=false;
        }
        for(int i=0;i<S && start+i<=n;i++){
            if(block[i]){
                result++;
            }
        }
    }

    return result;

}

int main(){
    ll n;
    cin>>n;
    cout<<count_primes((ll))<<endl;
    
}