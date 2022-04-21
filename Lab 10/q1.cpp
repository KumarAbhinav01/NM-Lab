#include<iostream>
#include<math.h>
using namespace std;
int main()
{
 int n;             
 cout<<"Enter Number of Elements : ";
 cin>>n;
 cout<<"Enter values of x:-\n";
 float x[n],h;
 cin>>x[0]>>h;
 for(int i=1;i<n;i++){
    x[i]=x[i-1]+h;
}
 float y[n][n];
 cout<<"Enter Y Values :-\n";
 for(int i=0;i<n;i++){
     cin>>y[i][0];
 } 
 for (int i = 1; i < n; i++) {
  for (int j = 0; j+i<n; j++){
   y[j][i] = (y[j+1][i - 1] - y[j][i - 1]);
  }
 }
 cout<<"\nX\tY\tdy\td2y\td3y\td4y\td5y\n\n";
  for (int i = 0; i < n; i++){
  cout <<x[i]<< "\t";
  for (int j = 0; j+i<n; j++)
   cout<<y[i][j]<<"\t";
  cout << endl;
  }
 float sum = 0;
 for(int k=1;k<n;k++){
     sum += (pow(-1,k-1)*y[0][k])/k;
 }
 cout<<"\nValue is "<<sum/h<<endl;
return 0;
}