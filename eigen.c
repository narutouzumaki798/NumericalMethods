#include<stdio.h>
#include<math.h>

//returns maximum of 2 numbers
float max(float a,float b)
{
	if(a >= b) return a;
	return b;
}

int main()
{
FILE *fp;
fp = fopen("power_method_data.txt", "w");

int n,i,j,itr=1;
printf("Enter size of matrix:");
scanf("%d", &n);
float a[n][n];
printf("Enter Matrix:\n");
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	 	scanf("%f", &a[i][j]);

fprintf(fp,"Matrix:\n");

for(i=0;i<n;i++)
{ 	for(j=0;j<n;j++)
		 fprintf(fp,"%f ", a[i][j]);
	fprintf(fp,"\n"); 
}	 	
fprintf(fp, "\n");

float x[n],old_x[n],m,old_m;
for(i=0;i<n;i++)  x[i] = 1,old_x[i] = 1;

while(1)
{
	//Multiplying  A[][] with X[]
	for(i=0;i<n;i++)
	{
		x[i] = 0;
		for(j=0;j<n;j++)
		{
			x[i] += a[i][j]*old_x[j];
		}
	}
	
	//Calculating  max X[i]
	 m = x[0];
	for(i=0;i<n;i++) m = max(m, x[i]);
	
	//taking max(X[i]) common
	for(i=0;i<n;i++) x[i] /= m;
	
	//break if max(X[i]) converges
	if(fabs(old_m - m) <= 0.001) break;
	
	fprintf(fp, "itr=%d  eigen_value=%f   x[]=",itr,m);
	for(i=0;i<n;i++) fprintf(fp," %f " , x[i]);
	fprintf(fp, "\n");
			 	
	for(i=0;i<n;i++) old_x[i] = x[i];
	old_m = m;	
	itr++;			
}

//printing Eigen values
fprintf(fp, "\nEigen Value: %f\n", m);
fprintf(fp, "Eigen Vector: ");
fprintf(fp,"[");
for(i=0;i<n;i++) 
{
 	 fprintf(fp, "  %f", x[i]);
	if(i != n-1) fprintf(fp,",");
}
fprintf(fp,"]");
fprintf(fp, "\n\n");

printf("\nEigen Value: %f\n", m);
printf("Eigen Vector: ");
for(i=0;i<n;i++)  printf("%f ", x[i]);
printf("\n\n");

return 0;
}
