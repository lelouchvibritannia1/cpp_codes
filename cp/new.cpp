#include <bits/stdc++.h>
using namespace std;
#define int long long int


//template<class T>
//summation
class segmentree{
    public:
        int n;
        vector<int> st;

        void init(int _n){
            this->n =_n;
            st.resize(4*n,0);
        }

        void build(int start,int ending,int node,vector<int> &v){

           //base case
            if(start == ending){
                st[node]=v[start];
                return;
            }


           int mid = start + (ending-start)/2;

           build(start,mid,2*node + 1,v);

           build(mid+1,ending,2*node +2,v);

           st[node] = st[node*2+1]+st[node*2+2];
        }

        int query(int start,int ending,int l,int r,int node){
            if(start > r || ending<l){
                return 0;
            }

            //complete overlap
            if(start >=l && ending<=r){
                return st[node];
            }

            //partial overlap
            int mid = start+(ending-start)/2;
            int q1= query(start,mid,l,r,2*node+1);
            int q2= query(mid+1,ending,l,r,2*node+2);

            return q1+q2;
        }
        void build(vector<int> &v){
            build(0,n-1,0,v);
        }

        void update(int start,int ending,int node,int index,int value){
            if(start == ending){
                st[node] = value;
                return;
            }

            int mid=start+(ending-start)/2;
            if(index<=mid){
                update(start,mid,(2*node)+1,index,value);
            }

            else{
                update(mid+1,ending,(2*node+2),index,value);
            }

            st[node] = st[node*2+1]+st[node*2+2];
            return;
        }
        int query(int l,int r){
            return query(0,n-1,l,r,0);
        }

        void update(int x,int y){
            update(0,n-1,0,x,y);
        }


};



int32_t main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt","w",stderr);
#endif

    vector<int> v={2,5,6,7,7,8,8,8};
    segmentree tree;
    tree.init(v.size());
    tree.build(v);
    tree.update(0,5);
    cout<<tree.query(0,4)<<"\n";
    cout<<tree.query(3,7)<<"\n";
}
