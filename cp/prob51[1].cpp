#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    unordered_set<string> s;
    vector<string> v(n);
    string ans(n,'0');
    for(int i=0;i<n;i++){
        cin>>v[i];
        s.insert(v[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<v[i].size();j++){
            string a=v[i].substr(0,j);
            string b=v[i].substr(j);
            if(s.find(a)!=s.end() && s.find(b)!=s.end()){
                ans[i]='1';
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}