#include "bits/stdc++.h"
// #include<iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define int long long int
// #define double long double
typedef pair<int, int> p64;
typedef pair<double, double> pdd;
typedef vector<int> v64;
typedef vector<vector<int>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
int MOD = 1e9 + 7;
double eps = 1e-8;
int MAX = 1e5;
#define G(x) \
    int x;   \
    cin >> x
#define GS(x) \
    string x; \
    cin >> x
#define F(i, l, r) for (int i = l; i < r; i++)
#define FD(i, r, l) for (int i = r; i > l; i--)
#define CO(x) cout << x << '\n'
#define CO_(x) cout << x << ' '
#define GA(x, n) \
    v64 x(n);    \
    F(i, 0, n)   \
    cin >> x[i]
#define CA(x, n)   \
    F(i, 0, n)     \
    {              \
        CO_(x[i]); \
    }              \
    cout << '\n'
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void init_code()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
}

/*this here is code */
//bfs and dfs can't be used as O(m*n) complexity
class Graph{
    int V;
    vector<int> *l;

    public:

        Graph(int V){
            this->V=V;
            l = new vector<int>[V+1];
        }

        void add_edge(int u,int v,bool undir=true){
            l[u].push_back(v);
            if(!undir) l[v].push_back(u);
        }

        int bfs(int s,vector<bool> &visited){
            queue<int> q;
            q.push(s);
            int ans{0};
            while(!q.empty()){
                int f=q.front();
                q.pop();

                for(auto child:l[f]){
                    if(!visited[child]){
                        visited[child]=true;
                        q.push(child);
                        ans++;
                    }
                }
            }

            return ans;
        }

        pair<int,int> bfsdis(){
            vector<bool> visited(V+1,false);
            int ans1{0},ans2{0};
            for(int i=1;i<V+1;i++){
                if(visited[V]==false){
                    ans2=max(ans2,bfs(i,visited));
                    ans1++;
                }
            }

            return make_pair(ans1,ans2);
        }


};


class DSU{
    int V;
    vector<int> e;

    public:
        DSU(int V){
            this->V=V;
            e=vector<int>(V,-1);
        }

        int get(int i){
            return e[i]<0?i:e[i]=get(e[i]);
        }

        bool same_set(int u,int v){
            return get(u)==get(v);
        }

        int size(int x){
            return -e[get(x)];
        }

        bool unite(int x,int y){
            x=get(x),y=get(y);
            if(x==y) return 0;
            if(e[x] > e[y]) swap(x,y);
            e[x]+=e[y];
            e[y]=x;
            return 1;
        }


};

void solve(){
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    int cc=n,ans=1;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(dsu.unite(--x,--y)){
            ans=max(ans,dsu.size(x));
            cc--;
        }

        cout<<cc<<" "<<ans<<endl;
    }
    
}





int32_t main(){
    init_code();
    int n,m,k;
    cin>>n>>m>>k;
    DSU dsu(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
    }
    vector<string> o(k);
    vector<int> u(k);
    vector<int> v(k);
    for(int i=0;i<k;i++){
        cin>>o[i];
        cin>>u[i]>>v[i];
    }
    // CA(o,k);
    vector<string> ans;
    for(int i=k-1;i>=0;i--){
        if(o[i]=="cut"){
            if(dsu.unite(--u[i],--v[i])){
                // cout<<i<<endl;
                continue;
            }
        }
        else{
            if(dsu.same_set(--u[i],--v[i])){
                // cout<<ans.size()<<" "<<i<<endl;
                ans.push_back("YES");  
                
            }
            else{
                // cout<<ans.size()<<" "<<i<<endl;
                ans.push_back("NO");
            }
        }
    }

    

    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<endl;
    }

}
/*which ends here*/

