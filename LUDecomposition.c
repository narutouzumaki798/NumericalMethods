#include<stdio.h>
int main()
{
    int i=0, j=0, n=0, k=0, x=0, y=0;
    float m[10][10], l[10][10], u[10][10];
    float sum=0;
    printf("Enter size of matrix (<=9) ");
    scanf("%d", &n);
    printf("Enter the matrix \n");
    for(x=1;x<=n;x++)
    {
    	for(y=1;y<=n;y++)
    	{
    		printf("m[%d][%d] ", x, y);
    		scanf("%f", &m[x][y]);
    	}
    }
    for(x=1;x<=n;x++)
	{
		for(y=1;y<=n;y++)
		{
			l[x][y]=0;
			u[x][y]=0;	
		}
	}
    for(x=1;x<=n;x++)
    {
    	l[x][x]=1;
    }
    for(j=1;j<=n;j++)
    {
    	for(i=1;i<=j;i++)
    	{
    		sum=m[i][j];
    		for(k=1;k<=i-1;k++)
    		{
    			sum-=l[i][k]*u[k][j];
    		}
    		if(i==1)
    		{
    			u[i][j]=m[i][j];
    		}
    		else
    		{
    			u[i][j]=sum;
    		}
    	}
    	for(i=j+1;i<=n;i++)
    	{
    		sum=m[i][j];
    		for(k=1;k<=j-1;k++)
    		{
    			sum-=l[i][k]*u[k][j];
    		}
    		sum=sum/u[j][j];
    		if(i==1)
    		{
    			l[i][j]=m[i][j]/u[j][j];
    		}
    		else
    		{
    			l[i][j]=sum;
    		}
    	}
    }
    printf("\n");
	printf("M=\n");
	for(x=1;x<=n;x++)
	{
		for(y=1;y<=n;y++)
		{
			printf("%f ",m[x][y]); 
		}
		printf("\n");
	}
	printf("\n");
	printf("L=\n");
	for(x=1;x<=n;x++)
	{
		for(y=1;y<=n;y++)
		{
			printf("%f ",l[x][y]); 
		}
		printf("\n");
	}
	printf("\n");
	printf("U=\n");
	for(x=1;x<=n;x++)
	{
		for(y=1;y<=n;y++)
		{
			printf("%f ",u[x][y]); 
		}
		printf("\n");
	}
	printf("\n");
}
