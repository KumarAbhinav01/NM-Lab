/*
E. Write a computer oriented algorithmic flowchart and corresponding 
c/c++ program to find value of the dx root f Simpson's 1/3rd and Simpsons 
3/8h rule respectively and print corresponding output structure.
*/

#include<bits/stdc++.h>
#include<math.h>

using namespace std;

float func( float x)
{
    return pow(2.718,-1*x*x);
}

void calc(float &S13sum,float&S38sum,float y[],float x[],float h,int n)
{

    for(int i=0;i<n-1;i+=2)
        S13sum=S13sum+(h/3)*(y[i]+4*y[i+1]+y[i+2]);

    for(int i=0;i<n-2;i+=3)
        S38sum=S38sum+(3*h/8)*(y[i]+3*y[i+1]+3*y[i+2]+y[i+3]);
}

int main()
{
    float x[100],y[100];
    int i;
    float a=0,b=1;
    int n=18;
    float S13sum=0.0,S38sum=0.0;
    x[0]=a;
    x[n]=b;

    float h=(b-a)/n;

    for(i=0;i<n+1;i++)
    {
        y[i]=func(x[i]);

        if(i==n)
        calc(S13sum,S38sum,y,x,h,n);

        x[i+1]=x[i]+h;
    }

    cout<<"Simpson's 1/3  : "<<sqrt(S13sum)<<endl;
    cout<<"Simpson's 3/8  : "<<sqrt(S38sum)<<endl;
    
    return 1;

}