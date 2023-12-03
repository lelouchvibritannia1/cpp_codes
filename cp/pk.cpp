#include <bits/stdc++.h>
using namespace std;
#include <cmath>

float ca1(float angle, int signal) {

    float x, y, z, xfinal, yfinal, zfinal;
    x = 1.2075; y = 0; z = angle;
    int xx, yy, sig = 1;

    for (int i=2; i<10; i++) {

        if (i==4) {

            xx = ((int)(x * 1000000)) >> (i-1);
            yy = ((int)(y * 1000000)) >> (i-1);

            z > 0 ? sig = 1 : sig = -1;

            xfinal = x + (sig * (yy/1000000 + (yy % 1000000)/1000000));
            yfinal = y + (sig * (xx/1000000 + (xx % 1000000)/1000000));

            x = xfinal;
            y = yfinal;
            z = z - (sig * ((i-1)));
        }

        xx = ((int)(x * 1000000)) >> (i-1);
        yy = ((int)(y * 1000000)) >> (i-1);

        z > 0 ? sig = 1 : sig = -1;

        xfinal = x + (sig * (yy/1000000 + (yy % 1000000)/1000000));
        yfinal = y + (sig * (xx/1000000 + (xx % 1000000)/1000000));

        x = xfinal;
        y = yfinal;
        z = z - (sig * ((i-1)));
    }

    return (signal == 1 ? (yfinal/xfinal) : (yfinal + xfinal));
}
float ca(float angle, int signal)
{
    float x,y,z,xfinal,yfinal,zfinal;
    x=1.2075;
    y=0;
    z=angle;
    float xunchanged, yunchanged;
    float degree;
    int sig=1;
    int j=1;
    int xx,yy;
    float remx,remy;
    for (int i=2; i<10; i++)
    {

        if (i==(3*j+1))
        {
            j=i;
            xunchanged=x;
            yunchanged=y;
            xx=x*1000000;
            xx=xx>>(i-1);
            remx=xx%1000000;
            xx=xx/1000000;
            remx=remx/1000000;
            x=xx+remx;
            yy=y*1000000;
            yy=yy>>(i-1);
            remy=yy%1000000;
            yy=yy/1000000;
            remy=remy/1000000;
            y=yy+remy;
            if (z>0)
            {
                sig=1;
            }
            else
            {
                sig=-1;
            }
            xfinal=xunchanged+(sig*y);
            yfinal=yunchanged+(sig*x);
            degree=5;
            zfinal=z-(sig*degree);
            x=xfinal;
            y=yfinal;
            z=zfinal;
        }
        xunchanged=x;
        yunchanged=y;
        xx=x*1000000;
        xx=xx>>(i-1);
        remx=xx%1000000;
        xx=xx/1000000;
        remx=remx/1000000;
        x=xx+remx;
        yy=y*1000000;
        yy=yy>>(i-1);
        remy=yy%1000000;
        yy=yy/1000000;
        remy=remy/1000000;
        y=yy+remy;
        if (z>0)
        {
            sig=1;
        }
        else
        {
            sig=-1;
        }
        xfinal=xunchanged+(sig*y);
        yfinal=yunchanged+(sig*x);
        degree=(i-1);
        zfinal=z-(sig*degree);
        x=xfinal;
        y=yfinal;
        z=zfinal;
    }
    float cosh=xfinal;
    float sinh=yfinal;
    if (signal==1)
    {
    	float tanh=sinh/cosh;
    	return tanh;
    }
    else if (signal==2)
    {
    	float e=sinh+cosh;
    	return e;
    }
}

int main(){
    float angle=0.785398;
    int signal1=1,signal2=2;
    cout<<(ca(angle,signal1))<<" "<<(ca1(angle,signal1))<<endl;
    cout<<(ca(angle,signal2))<<" "<<(ca1(angle,signal2))<<endl;

}