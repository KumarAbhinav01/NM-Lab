// Newton's Forward Interpolation

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

float u_cal(float, int);
int fact(int);

int main()
{
    int n = 4;
    cout<<"\nEnter no. of elements: ";
    cin>>n;
	float x[n];     
	
    for(int i=0; i<n; i++)
    {
        cout<<"x["<<i<<"]: ";
        cin>>x[i];
    }

    float y[n][n];
    y[0][0] = 1;
	y[1][0] = 2;
	y[2][0] = 4;
	y[3][0] = 7;
	y[4][0] = 11;
	y[5][0] = 16;
	y[6][0] = 22;
	y[7][0] = 29;

    cout<<endl<<endl;

    for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++)
			y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
	}

    for (int i = 0; i < n; i++) {
		cout << setw(4) << x[i]<< "\t";
		for (int j = 0; j < n - i; j++)
			cout << setw(4) << y[i][j]<< "\t";
		cout << endl;
	}

    float value = 12;
    cout<<"\t\nEnter the No. to find value: ";
    cin>>value;

    float sum = y[0][0];
	float u = (value - x[0]) / (x[1] - x[0]);
	for (int i = 1; i < n; i++) {
		sum = sum + (u_cal(u, i) * y[0][i]) / fact(i);
	}

    cout << "\nValue at " << value << " is "
		<< sum << endl<< endl;
	
    return 0;
}

float u_cal(float u, int n)
{
	float temp = u;
	for (int i = 1; i < n; i++)
		temp = temp * (u - i);
	return temp;
}

int fact(int n)
{
	int f = 1;
	for (int i = 2; i <= n; i++)
		f *= i;
	return f;
}
