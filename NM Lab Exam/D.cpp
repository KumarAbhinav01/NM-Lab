/*
D. Write a generalized computer oriented algorithmic flowchart and 
corresponding c/c++ program to solve the system of linear equations 
(atleast 10 equations) using Gauss- Seidal method. Hence evaluate

10x₁ - x₂ = 100
-x₁ +15x₂-x₂ = 130
-x₂ +20x₁ - x₂ = 162
- x₂ + 25x₁ - x₁ = 184
-x₂ +30x, = 202

print the solution up to 5 decimal places using atleast 10 iterations 
(write the corresponding output structure).
*/

#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
#define f1(x,y,z,p,q) (100+y)/10
#define f2(x,y,z,p,q) (130 +x +z)/15
#define f3(x,y,z,p,q) (162+y+p)/20
#define f4(x,y,z,p,q) (184+z+q)/25
#define f5(x,y,z,p,q) (202+p)/30
int main()
{
    float x0=0,y0=0,z0=0,p0=0,q0=0,x1,y1,z1,p1,q1,e1,e2,e3,e4,e5,e;
    int count=1;
    printf("Enter error:");
    scanf("%f",&e);
    printf("\nx1\t\tx2\t\tx3\t\tx4\t\tx5\n");
    do{
       x1 =f1(x0,y0,z0,p0,q0);
        y1 =f2(x1,y0,z0,p0,q0);
        z1 =f3(x0,y1,z0,p0,q0);
        p1=f4(x0,y0,z1,p0,q0);
        q1=f5(x0,y0,z0,p1,q0);
         e1=fabs(x0-x1);
         e2=fabs(y0-y1);
         e3=fabs(z0-z1);
         e4=fabs(p0-p1);
         e5=fabs(q0-q1);
         count++;
         cout<<x1<<"\t\t"<<y1<<"\t\t"<<z1<<"\t\t"<<p1<<"\t\t"<<q1<<endl;
         x0=x1;y0=y1;z0=z1;p0=p1;q0=q1;
    }while(count<11||(e1>e&&e2>e&&e3>e&&e4>e&&e5>e));
    
    return 0;

}