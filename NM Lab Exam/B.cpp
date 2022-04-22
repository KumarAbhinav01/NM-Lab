/* 
B. Write a computer oriented algorithmic flowchart and corresponding c/c++ program 
to find largest negative root of the equation x³-4x-9-0 using Newton-Rapson method 
and print the root up to 4 decimal places using at least 10 iterations (Write the 
corresponding output structure).
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define f(x)  pow(x,3) - 4*x - 9
#define g(x)  3*pow(x,2) -4

int main()
{
	 float x0, x1, f0, f1, g0, e;
	 int i = 1, N;
	 
	 printf("\nEnter initial guess:\n");
	 scanf("%f", &x0);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);
	 printf("Enter maximum iteration:\n");
	 scanf("%d", &N);
	 
	 printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	 do
	 {
		  g0 = g(x0);
		  f0 = f(x0);
		  if(g0 == 0.0)
		  {
			   printf("Mathematical Error.");
			   exit(0);
		  }
		
		  x1 = x0 - f0/g0;
		
		  printf("%d\t\t%f\t%f\t%f\t%f\n",i,x0,f0,x1,f1);
		  x0 = x1;
		  
		  i = i+1;
		
		  if(i > N)
		  {
			   printf("Not Convergent.");
			   exit(0);
		  }
		  
		  f1 = f(x1);
		  
	 }while(fabs(f1)>e);
	
	 printf("\nRoot is: %f", x1);
	return 0;
}