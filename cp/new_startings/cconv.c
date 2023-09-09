#include <stdio.h>
#include <math.h>
int n=4;
int x[4]={1,2,3,4};
int h[4]={1,2,3,4};
int y[4];

int main(void){
    int i,j;
    printf("The circular convolution is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            y[i]+=x[j]*h[(i-j+n)%n];
        }
        printf("%d\n",y[i]);
    }
    return 0;
}