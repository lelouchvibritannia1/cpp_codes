#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int MAX=1e5;

void init_code(){
   fast_cin();
   #ifndef ONLINE_JUDGE
   // for getting input from input.txt
   freopen("input.txt", "r", stdin);
   // for writing output to output.txt
   freopen("output.txt", "w", stdout);
   #endif
}

vector<int> factors[MAX+5];

void init(){
    for(int i=1;i<=MAX;i++){
        for(int j=i;j<=MAX;j+=i){
            factors[j].push_back(i);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        v.push_back({val,i});
    }
    sort(v.begin(),v.end());
    vector<int> freq(m+5,0);
    int cur_count=0,j=0,glob_ans{INT_MAX};
    for(int i=0;i<n;i++){
        for(auto x:factors[v[i].first]){
            if(x>m){
                break;
            }
            if(!freq[x]++){
                cur_count++;
            }
        }
        while(cur_count==m){
            int cur_ans=v[i].first - v[j].first;
            if(cur_ans < glob_ans){
                glob_ans=cur_ans;
            }
            for(auto x:factors[v[j].first]){
                if(x > m){
                    break;
                }
                if(--freq[x]==0){
                    cur_count--;
                }
            }
            j++;
        }   
    }
    cout<<((glob_ans>=INT_MAX)?-1:glob_ans)<<endl;
}

int32_t main(){
    init_code();
    // init();
    int t;
    cin>>t;
    while(t--) solve();
}