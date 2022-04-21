#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main()
{
    int n,i,j;
    float x0,a[50][50],h,x,p=1,sum;

    cout<<"Enter number of Input: ";
    cin>>n;

    cout<<"\nEnter initial Value of x: ";
    cin>>x0;

    cout<<"\nEnter Value of h: ";
    cin>>h;

    cout<<"\nEnter Value of 'x' at which you want to find answer : ";
    cin>>x;

    cout<<"\nEnter Value of Y:\n";
    for(i=0;i<n;i++)
      cin>>a[0][i]; 

    for(i=1;i<n;i++)
        for(j=0;j<n-i+1;j++)
            a[i][j]=a[i-1][j+1]-a[i-1][j];

    sum=0;

    for(int i=1;i<n-1;i++)
    {
        sum=sum+(pow(-1, i-1)*a[i][0])/i;
    }
    sum = sum/h;

    cout<<"Value at "<<x<<" is "<<sum<<endl;

    return 0;
}