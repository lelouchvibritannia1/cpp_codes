#include<bits/stdc++.h>
using namespace std;


void print_pq(priority_queue<long long,vector<long long>, greater<long long>> dq){
    while(dq.size()>0){
        cout<<dq.top()<<" ";
        dq.pop();
    }
    cout<<endl;
}
void minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>, greater<long long>> pq(arr,arr+n);
        long long ans=0;
        while(pq.size()!=1){
            long long t1=pq.top();
            pq.pop();
            long long t2=pq.top();
            pq.pop(); 
            ans+=t1+t2;
            pq.push(t1+t2);
            print_pq(pq);
            cout<<ans<<endl;
        }
        ans+=pq.top();
        cout<<ans<<endl;
        //return ans;
}

int main(){
    long long v1[]={4,3,2,6};
    minCost(v1,4);
}