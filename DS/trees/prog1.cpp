#include<bits/stdc++.h>
using namespace std;

struct node{
	int D;
	node* LC;
	node* RC;
	node(int x){
		LC=RC=NULL;
		D=x;
	}
};

void preOrder_rec(node *R){
	if(R==NULL) return;
	cout<<R->D<<" ";
	preOrder_rec(R->LC);
	preOrder_rec(R->RC);

}



void inOrder_rec(node* R){
	if(R==NULL) return;
    inOrder_rec(R->LC);
    cout<<R->D<<" ";
	inOrder_rec(R->RC);
    
}

void postOrder_rec(node* R){
	if(R==NULL) return;
	postOrder_rec(R->LC);
	postOrder_rec(R->RC);
    cout<<R->D<<" ";
}

void preOrder_iterative(node* R){
    if(R==NULL) return;
    stack<node*> S;
    S.push(R);
    while(S.size()){
        node* curr=S.top();
        S.pop();
        cout<<curr->D<<" ";
        if(curr->RC!=NULL) S.push(curr->RC);
        if(curr->LC!=NULL) S.push(curr->LC);
    }
    cout<<endl;
}

void inOrder_iterative(node* R){
    if(R==NULL) return;
    stack<node*> S;
    node* curr=R;
    while(true){
        if(curr!=NULL){
            S.push(curr);
            curr=curr->LC;
        }
        else{
            if(S.empty()) break;
            curr=S.top();
            S.pop();
            cout<<curr->D<<" ";
            curr=curr->RC;
        }
    }
    cout<<endl;
}

void postOrder_iterative_1(node* R){
    if(R==NULL){
        return;
    }
    stack<node*> S1,S2;
    S1.push(R);

    while(S1.size()){
        node* curr=S1.top();
        S1.pop();
        S2.push(curr);
        if(curr->LC!=NULL) S1.push(curr->LC);
        if(curr->RC!=NULL) S1.push(curr->RC);
    }

    while(S2.size()){
        cout<<S2.top()->D<<" ";
        S2.pop();
    }

    cout<<endl;
}


void LOT1(node* R){
    if(R==NULL) return;
    queue<node*> q;
    q.push(R);q.push(NULL);
    while(q.size()>1){
        node* curr=q.front();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<curr->D<<" ";
        if(curr->LC!=NULL){
            q.push(curr->LC);
        }
        if(curr->RC!=NULL){
            q.push(curr->RC);
        }
    }
}

void LOT2(node* R){
    if(R==NULL) return;
    queue<node*> q;
    q.push(R);
    while(!q.empty()){
        int count=q.size();
        for(int i=1;i<=count;i++){
            node* curr=q.front();
            q.pop();
            cout<<curr->D<<"  ";
            if(curr->LC!=NULL) q.push(curr->LC);
            if(curr->RC!=NULL) q.push(curr->RC);
        }
        cout<<endl;
    }
}

int main(){
    node* root = new node(1);
    root->LC = new node(2);
    root->RC = new node(3);
    root->LC->LC=new node(4);
    root->LC->RC=new node(5);
    root->RC->RC=new node(7);
    root->RC->LC=new node(6);
    preOrder_rec(root);
    cout<<endl;
    preOrder_iterative(root);
    inOrder_rec(root);
    cout<<endl;
    inOrder_iterative(root);
    postOrder_rec(root);
    cout<<endl;
    postOrder_iterative_1(root);

}
