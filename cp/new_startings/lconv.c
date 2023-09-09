#include <stdio.h>
#include <math.h> 
int x[7] = {1, 2, 3, 4, 0, 0, 0};
int h[7] = {1, 2, 3, 4, 0, 0, 0};
int y[7];

int main(void)
{
    int i, j;
    printf("The linear convolution is:\n");
    for(int i=0;i<7;i++){
        y[i]=0;
        for(int j=0;j<=i;j++){
            y[i]+=x[j]*h[i-j];
        }
        printf("%d\n",y[i]);
    }
    return 0;
}