#include<bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;typedef long double ld;typedef pair<int,int> p32;typedef pair<ll,ll> p64;typedef pair<double,double> pdd;typedef vector<ll> v64;typedef vector<int> v32;typedef vector<vector<int> > vv32;typedef vector<vector<ll> > vv64;typedef vector<vector<p64> > vvp64;typedef vector<p64> vp64;typedef vector<p32> vp32;typedef stack<ll> s64;typedef stack<int> s32;typedef stack<pair<int,int>> sp32;typedef unordered_map<int,int> ump32;ll MOD = 1e9 + 7;double eps = 1e-8;ll MAX=1e5;

vector<bool> prime(MAX,true);void sieve(){prime[0]=prime[1]=false;for(int i=2;i*i<MAX;i++){if(prime[i]){for(int j=i*i;j<MAX;j+=i){prime[j]=false;}}}}


/*this here is code */



void solve(){
    map<int,vector<int>> mp;string s;cin>>s;string l(s);int n=s.length();for(int i=0;i<n;i++) mp[s[i]].push_back(i);int direction=(s[n-1]>s[0])?1:-1;
    v32 ans;for(char c=s[0];c!=s[n-1]+direction;c+=direction){for(auto now:mp[c]) ans.push_back(now);} int cost=0;for(int i=1;i<ans.size();i++){cost+=abs(s[ans[i]]-s[ans[i-1]]);}cout<<cost<<" "<<ans.size()<<endl;for(int i=0;i<ans.size();i++) cout<<ans[i]+1<<" "; cout<<endl;
}

int main(){fast_cin();ll t;cin>>t;while(t--) solve();}
/*which ends here*/