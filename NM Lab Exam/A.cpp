/*
A. Write a computer oriented algorithmic flowchart and corresponding 
c/c++ program to find largest negative root of the equation x³-4x-9-0 
using bisection method and print the root up to 5 decimal places using 
at least 10 iterations (write the corresponding output structure).
*/

#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.00001

double func(double x)
{
	return x*x*x - 4*x - 9;
}

void bisection(double a, double b)
{
    
    //checking for condition that satisfy for having root between a and b
	if (func(a) * func(b) >= 0)
	{
		cout << "It is not possible to have root between a and b therefore choose other value of a and b\n";
		return;
	}

	double c = a;
	while ((b-a) >= EPSILON )//taking care of decimal places
	{
		
		c = (a+b)/2;  // Find middle point

		if (func(c) == 0.0){   // Check if middle point is root
			 cout<<"\nRoot = "<<c;
            break;
            }
		
		else if (func(c)*func(a) < 0){  // Decide the side to repeat the steps
			cout<<"\nRoot = "<<c;
            b = c;
            }
		else{
        cout<<"\nRoot = "<<c;
			a = c;
        }
        
	}
	cout << "\nThe value of root is : " << c;
}
int main(){
    double a =-100, b = 100;
	bisection(a, b);
	return 0;
}