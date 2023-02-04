#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>n>>m;
    int maze[n][m];
    int x,y;
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    for(int j=0;j<m;j++){
        if(maze[0][j]==1){
             x=j-1;
            for(int i=0;i<n;i++){
                if(maze[i][x]){
                    int y=i-1;
                    for(int k=x;k>=0;k--){
                        if(maze[y][k]==1){
                            x=k-1;
                            flag=true;
                        }
                        if(!true){
                            x=0
                        }
                    }

                }
            }
        }
        }
    }
   
}