#include<bits/stdc++.h>
using namespace std;

int balancedStringSplit(string s) {
        int ans=0;
        int rs=0;
        unordered_map<int,int> sum;
        for(int i=0;i<str.length();i++){
            rs=(s[i]=='L')?1:-1;
            auto it=sum.find(rs);
            if(rs==sum.end()){
                sum.insert({rs,i});
            }
            else{
                ans++;
            }
        }
        return ans;
        
    }