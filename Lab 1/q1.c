#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) x*exp(x)-2
#define e 0.001
int main()
{
    int i=0;
    float x0=0,x1=1,m,f0,f1,f2;
    //Calculation of x0 and x1.
    x0=0;
    f0=f(x0);
    calculation:
        x1=x0+1;
        f1=f(x1);
        if(f0*f1>0)
        {
            x0=x1;
            goto calculation;
        }
    
    //Implementation of Bisection Method 
    do
    {
        f0=f(x0);
        f1=f(x1);
        m=(x0+x1)/2;
        f2=f(m);
        if(f0 * f2 < 0)
            x1=m;
        else
            x0=m;
        i++;
        printf("\n%d solution is %f",i,m);
    } while (fabs(f2) > e);
    return 0;
    //getch();
}