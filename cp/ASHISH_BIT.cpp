#include<bits/stdc++.h>
using namespace std;


class segmentree{
    public:
        int n;
        vector<int> st;

        void init(int _n){
            this->n =_n;
            st.resize(4*n,0);
        }

        void build(int start,int ending,int node,vector<int> &v,int ctr){

           //base case
            if(start == ending){
                st[node]=v[start];
                return;
            }


           int mid = start + (ending-start)/2;

           build(start,mid,2*node + 1,v,ctr-1);

           build(mid+1,ending,2*node +2,v,ctr-1);

           if(ctr % 2==0){
                st[node] = st[node*2+1]^st[node*2+2];
           }
           else{
                st[node] = st[node*2+1]|st[node*2+2];
           }
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
//        void build(vector<int> &v){
//            build(0,n-1,0,v,ctr);
//        }

        void update(int start,int ending,int node,int index,int value,int ctr){
            if(start == ending){
                st[node] = value;
                return;
            }

            int mid=start+(ending-start)/2;
            if(index<=mid){
                update(start,mid,(2*node)+1,index,value,ctr-1);
            }

            else{
                update(mid+1,ending,(2*node+2),index,value,ctr-1);
            }

            if(ctr % 2==0){
                st[node] = st[node*2+1]^st[node*2+2];
            }
            else{
                st[node] = st[node*2+1]|st[node*2+2];
            }
        }
        int query(int l,int r){
            return query(0,n-1,l,r,0);
        }

        void update(int x,int y,int ctr){
            update(0,n-1,0,x,y,ctr);
        }


};


vector<int> solve(int n, vector<int>a, vector<vector<int>> queries){
    vector<int> ans;
        segmentree tree;
        tree.init(pow(2,n));
        int val=pow(2,n);
        tree.build(0,a.size()-1,0,a,val-1);
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0],y=queries[i][1];
            tree.update()
        }

}
