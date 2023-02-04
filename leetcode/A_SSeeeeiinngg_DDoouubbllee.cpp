#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s,s1;
        cin>>s;
        for(auto c:s){
            s1=c+s1;
        }
        cout<<s<<s1<<endl;
}
}