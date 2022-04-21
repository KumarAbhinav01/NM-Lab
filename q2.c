#include<stdio.h>
#include<math.h>
float dydx(float x, float y)
{
	return ((x*x)+y);
}

float rungeKutta1st(float x0, float y0,float x, float h)
{
    int i;
    double y;
    while(x0<x){
        y=y0+h*dydx(x0,y0);
        y0=y;
        x0=x0+h;
    }
   return y;
}

float rungeKutta2nd(float x0, float y0,float x, float h)
{
	int n = (int)((x - x0) / h);
	float k1, k2;
	float y = y0;
	for (int i = 1; i <= n; i++) {
		k1 = h * dydx(x0, y);
		k2 = h * dydx(x0 + 0.5 * h, y + 0.5 * k1);
		y = y + (1.0 / 6.0) * (k1 + 2 * k2);
		x0 = x0 + h;
	}
	return y;
}
float rungeKutta4th(float x0, float y0, float x, float h)
{
	int n = (int)((x - x0) / h);
	float k1, k2, k3, k4, k5;
	float y = y0;
	for (int i=1; i<=n; i++)
	{
		k1 = h*dydx(x0, y);
		k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1);
		k3 = h*dydx(x0 + 0.5*h, y + 0.5*k2);
		k4 = h*dydx(x0 + h, y + k3);
		y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);
		x0 = x0 + h;
	}
	return y;
}
int main()
{
	float x0 = 0, y = 1, x = 0.2 , h = 0.1;
    printf("\nUsing First Order -> y(x) = %f", rungeKutta1st(x0, y, x, h));
    printf("\nUsing Second Order -> y(x) = %f", rungeKutta2nd(x0, y, x, h));
	printf("\nUsing Fourth Order -> y(x) =  %f\n\n",rungeKutta4th(x0, y, x, h));
    
	return 0;
}