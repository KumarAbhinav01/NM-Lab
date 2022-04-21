#include<iostream>
#include<cmath>
using namespace std;

#define f(x) pow(x,3)-pow(x,2)+100
#define g(x) 3*pow(x,2)-2*x 
float x0=0,x1,f1;
float xy[500];
float f0=f(x0);
void calculate(){
    x1=x0-1;
    f1=f(x1);
    if(f0*f1>0){
        x0=x1;
        f0=f1;
         calculate();
    }
    xy[0]=x0;
}

int main(){
    int i=0;
    calculate();      
    for( i=0;i<500;i++){
        float a=f(xy[i]);
        float b=g(xy[i]);
        xy[i+1]=xy[i]-a/b;
        if(abs(xy[i+1]-xy[i])<pow(10,-5)){
            break;
        }
    }
    cout<<"The Solution ="<<xy[i+1]<<endl;
    return 0;
}