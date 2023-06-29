#include <bits/stdc++.h>
using namespace std;
#define int long long int


        int sod(int n){
            int s=0;
            while(n>0){
                int d=n%10;
                s+=d;
                n/=10;
            }
            return s;
        }

//template<class T>
//summation
class segmentree{
    public:
        int n;
        vector<int> st;
        vector<bool> lazy;

        void init(int _n){
            this->n =_n;
            st.resize(4*n,0);
            lazy.resize(4*n,false);
//            lazy[0]=true;

        }

        void build(int start,int ending,int node,vector<int> &v){

           //base case
            if(start == ending){
                st[node]=v[start];
                return;
            }


           int mid = start + (ending-start)/2;

            //building left subtree
           build(start,mid,2*node + 1,v);


            //building right subtree
           build(mid+1,ending,2*node +2,v);

           st[node] = st[node*2+1]+st[node*2+2];
        }

        int query(int start,int ending,int l,int r,int node){
            if(start > r || ending<l){
                return 0;
            }


            //lazy propagation, clear the lazy update
            if(lazy[node]!=false){

                //update
                st[node] = sod(st[node]);

                if(start!=ending){
                    lazy[2*node+1]=lazy[node];
                    lazy[2*node+2]=lazy[node];
                }

                lazy[node]=false;
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

        void update(int start,int ending,int node,int l,int r){
            if(start>r || ending<l){
                return;
            }

            if(lazy[node]!=false){

                //update
                st[node]=sod(st[node]);

                if(start!=ending){
                    lazy[2*node+1]=lazy[node];
                    lazy[2*node+2]=lazy[node];
                }

                lazy[node]=false;
            }

         // complete overlap
		if (start >= l && ending <= r) {
//			st[node]= sod(st[node]);

            if(start == ending){
                st[node]=sod(st[node]);
            }
			if (start != ending) {
				lazy[2 * node + 1] =true;
				lazy[2 * node + 2] =true;
			}
			return;
		}

            //partial case
            int mid=start+(ending-start)/2;
            update(start,mid,(2*node)+1,l,r);

            update(mid+1,ending,(2*node+2),l,r);


            st[node] = st[node*2+1]+st[node*2+2];
            return;
        }
        int query(int l,int r){
            return query(0,n-1,l,r,0);
        }

        void update(int l,int r){
            update(0,n-1,0,l,r);
        }

        void clear(){
            lazy.resize(0);
            st.resize(0);
        }


};



int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        segmentree tree;
        tree.init(n);
        tree.build(a);
        for(int i=0;i<q;i++){
            int ch;
            cin>>ch;
            if(ch==1){
                int l,r;
                cin>>l>>r;
                tree.update(l-1,r-1);
            }
            else if(ch==2){
                int ind;
                cin>>ind;
                cout<<tree.query(ind-1,ind-1)<<endl;
            }
        }
        tree.clear();
    }
}

