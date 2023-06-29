#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define max 524288

int seg[max+1];

void build(int v,int l,int r,vector<int>& a,int val){
    if(l == r){
        seg[v]=a[l];
    }
    else{
        int mid=l+(r-l)/2;

        build(2*v,l,mid,a,val-1);
        build(2*v+1,mid+1,r,a,val-1);

        if(val%2 == 0){
            seg[v]=seg[2*v]^seg[2*v+1];
        }
        else{
            seg[v]=seg[2*v]|seg[2*v+1];
        }

    }
}

void update(int v,int l,int r,int pos, int val, int ctr){
    if(l==r){
        seg[v]=val;
    }
    else{
        int mid=l+(r-l)/2;
        if(pos<=mid){
            //update left subtree
            update(2*v,l,mid,pos,val,ctr-1);
        }
        else{
            //update right subtree
            update(2*v+1,mid+1,r,pos,val,ctr-1);
        }

        if(ctr%2 == 0){
            seg[v]=seg[2*v]^seg[2*v+1];
        }
        else{
            seg[v]=seg[2*v]|seg[2*v+1];
        }

    }
}


vector<int> solve(int n, vector<int>a, vector<vector<int>> queries){
    memset(seg,0,sizeof(seg));
    int val=pow(2,n);
    vector<int> ans;
    build(1,0,val-1,a,n);
    for(int i=0;i<queries.size();i++){
        int x=queries[i][0],y=queries[i][1];
        update(1,0,val-1,x-1,y,n);
        ans.push_back(seg[1]);
    }
    return ans;
}

int32_t main(){

    int n,m;
    cin>>n>>m;
    int l=pow(2,n);
    vector<int> a(l);
    for(int i=0;i<l;i++){
        cin>>a[i];
    }
    vector<vector<int>> queries(m,vector<int>(2,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>queries[i][j];
        }
    }

    vector<int> ans=solve(n,a,queries);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }

}
