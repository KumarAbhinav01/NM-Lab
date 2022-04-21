// Newton divided interpolation

#include <bits/stdc++.h>
#include<math.h>

using namespace std;

float fdt[10][11],y=0,x,p=1,u;
int i,j,k,fac=1;

void input(void);  
void diff_table(void);    
float x_cal(float,int);   
int fact(int);              
float calculate(float);    

int main()
{
    input();
    char choice = y;
    cout<<"\nEnter the value of x for which y is to be computed : ";
    cin>>x;
    diff_table();
    y=calculate(x);
    cout<<"\n\nFOR x = "<<x<<", y = "<<y<<endl;
    
    /* cout<<"Do you want to continue? (y/n): ";
    cin>>choice;
    while (choice == 'y')
    {
        cout<<"\nEnter the value of x for which y is to be computed : ";
        cin>>x;
        diff_table();
        y=calculate(x);
        cout<<"\n\nFOR x = "<<x<<", y = "<<y<<endl;
        cout<<"Do you want to continue? (y/n): ";
        cin>>choice; 
    } */
    
    return 0;
}

void input()
{
    cout<<"Enter the total number of set of points : ";
    cin>>k;

    for(i=1;i<=k;i++)
    {
        cout<<"\nX"<<i<<" = ";
        cin>>fdt[i][0];

        cout<<"Y"<<i<<" = ";
        cin>>fdt[i][1];
    }
    return;
}

void diff_table()
{
    for(j=1;j<k;j++)
    {
        for(i=1;i<=k-j;i++)

        {
           if(j==1)
              fdt[i][j+1]=(fdt[i+1][j]-fdt[i][j])/(fdt[i+1][0]-fdt[i][0]);
           else
                fdt[i][j+1]=(fdt[i+1][j]-fdt[i][j])/(fdt[i+j][0]-fdt[i][0]);
        }
    }

    cout<<"\nDIVIDED DIFFERENCE TABLE \n\n";

    cout<<"x\ty\n\n";

    for(i=1;i<=k;i++)
    {
        cout<<fdt[i][0]<<"\t";
        for(j=1;j<=k-i+1;j++)
        {
            cout<<fdt[i][j]<<"\t";
        }
        cout<<"\n";
    }

}

int c;
float calculate(float x)
{
    for(i=1;i<=k;i++)
    {
        if(x<fdt[i+1][1])
        {
            break;
        }
    }

    for(j=1;j<=(k-i+1);j++)
    {
        c=i;
        y+=fdt[i][j]*x_cal(x,j-1);
    }
    return y;
}

float x_cal(float l,int m)
{
    p=1;
    if(m>0)
    {
        while(m>0)
        {
            p*= (l-fdt[c][0]);
            m-= 1;
            c++;
        }
    }
    return p;
}
