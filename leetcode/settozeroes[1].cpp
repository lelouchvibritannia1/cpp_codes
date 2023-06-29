#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int> > &A) {
    cout<<A.size()<<endl;
    cout<<A[0].size()<<endl;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   vector<int> rows_0, columns_0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            if(A[i][j]==0){
                rows_0.push_back(i);
                columns_0.push_back(j);
            }
        }
    }
    for(auto x:rows_0){
        for(int i=0;i<A[i].size();i++){
            A[x][i]=0;
        }
    }
    for(auto x:columns_0){
        for(int i=0;i<A.size();i++){
            A[i][x]=0;
        }
    }
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> A={{0,0,1},{1,1,1}};
    setZeroes(A);
}