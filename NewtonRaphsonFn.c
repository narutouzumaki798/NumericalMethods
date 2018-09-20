#include<stdio.h>
#include<math.h>
float f1(float x1, float x2)
{
	float ans=0;
	ans=x1*x1+x2*x2-25;
	return ans;
}
float f2(float x1, float x2)
{
	float ans=0;
	ans=x1-x2-1;
	return ans;
}
float f1d1(float x1, float x2)
{
	float ans=0;
	ans=2*x1;
	return ans;
}
float f1d2(float x1, float x2)
{
	float ans=0;
	ans=2*x2;
	return ans;
}
float f2d1(float x1, float x2)
{
	float ans=0;
	ans=1;
	return ans;
}
float f2d2(float x1, float x2)
{
	float ans=0;
	ans=-1;
	return ans;
}
void inverse(float l[10][10], int n)
{
	int i=0, j=0, r=0, c=0, k=0;
	float mt=0;
	float m[10][10];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			m[i][j]=l[i][j];
		}
		for(j=n;j<2*n;j++)// to store an identity matrix along with the given matrix
		{
			if(j==i+n)
			{
				m[i][j]=1;
			}
			else
			{
				m[i][j]=0;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				mt=m[j][i]/m[i][i];//calculation of coefficient for row operation
				for(k=0;k<2*n;k++)
				{
					m[j][k]-=mt*m[i][k];
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=n;j<2*n;j++)
		{
			m[i][j]/=m[i][i];//calculate the inverse by dividing the answer with the diagonal element
		}
	}
	for(r=0;r<n;r++)
	{
		for(c=n;c<2*n;c++)
		{
			l[r][c-n]=m[r][c];
		}
	}
}
int main()
{
	int i=0, j=0, k=0, n=2;
	float ji[10][10];
	float x[10], xt[10], fx[10];
	FILE *fp=fopen("NewtonRaphsonEqn.tsv","w");
	float err=10;
	x[0]=xt[0]=1;
	x[1]=xt[1]=1;
	k=0;
	while(++k)
	{		
		printf("\n Itr#%d \n", k);
		fx[0]=f1(x[0], x[1]);
		fx[1]=f2(x[0], x[1]);
		ji[0][0]=f1d1(x[0], x[1]);
		ji[0][1]=f1d2(x[0], x[1]);
		ji[1][0]=f2d1(x[0], x[1]);
		ji[1][1]=f2d2(x[0], x[1]);
		inverse(ji,2);
		xt[0]=x[0]-ji[0][0]*fx[0]-ji[0][1]*fx[1];
		xt[1]=x[1]-ji[1][0]*fx[0]-ji[1][1]*fx[1];
		err=0;
		fprintf(fp,"%d,",k);
		for(i=0;i<n;i++)
		{
			printf("x%d = %f ",i+1 ,x[i]);
			fprintf(fp,"%f ,",x[i]);
			err+=fabs(x[i]-xt[i]);//the total error is calculated as sum of difference of all values from their values in previous iteration
		}
		fprintf(fp,"%f",err);
		fprintf(fp,"\n");
		printf("\nError %f", err);
		for(i=0;i<n;i++)
		{
			x[i]=xt[i];//copying the values of new iteration into original matrix for answers
		}
		if(fabs(err)<=0.001)
		{
			break;//stop iteration after error is less than desired
		}
	}
	printf("\n");
}
