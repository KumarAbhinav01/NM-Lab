/*
C. Write a generalized computer oriented algorithmic flowchart and 
corresponding c/c++ program to solve the system of linear equations 
(atleast 10 equations) using Gauss Elemination method. Hence evaluate

10x₁ - x₂ = 100
-x₁ +15x₂ - x3 = 130
-x₂ + 20x3 - x4 = 162
-x3 + 25x4 - x5 = 184
-x4 + 30x5 = 202

print the solution up to 5 decimal places (write the corresponding output structure).
*/

#include <stdio.h>

int main()
{
    float ratio;
    int n=0;
    printf("Enter number of Unknown: ");
    scanf("%d",&n);
    float mat[n][n+1],value[n];
    printf("Enter Value of Augmented Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            scanf("%f",&mat[i][j]);
        }
    }

    // Convert To Upper Triangular Matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j>i)
            {
                ratio=mat[j][i]/mat[i][i];
                for(int k=0;k<n+1;k++)
                {
                    mat[j][k]=mat[j][k]-(ratio*mat[i][k]);
                }
            }
        }
    }


    //Apply BackSubstitution
    
    value[n-1]=mat[n-1][n]/mat[n-1][n-1];

    for(int i=n-2;i>=0;i--)
    {
        float sum = 0;
        for(int j=i+1;j<n;j++)
        {
            sum=sum+mat[i][j]*value[j];
        }
        value[i]=(mat[i][n]-sum)/mat[i][i];
    }
    
    //Printing values
    for(int i=0;i<n;i++)
    {
        printf("Value of x%d = %0.5f\n",i+1,value[i]); 
    }
    return 0;
}