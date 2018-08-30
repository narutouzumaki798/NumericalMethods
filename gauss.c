#include<stdio.h>
#include<math.h>

float det(float a[][100],int n)
{

 int i,j; float ans = 0;
 for(i=0;i<n;i++)
 {
    ans += a[0][i]*det(&a[1][i)
 }

}

int main()
{


printf("Enter number of variables:");
int n; scanf("%d",&n);
printf("Enter co efficients: \n");
int i,j,r;
float a[n+1][n+1]; float c[n+1];

for(i=0;i<n;i++)
 for(j=0;j<n;j++)
    scanf("%f",&a[i][j]);

printf("Enter Constants: \n");
for(i=0;i<n;i++) scanf("%f",&c[i]);


   //float x = det(a,n);
 

for (j=0;j<n;j++)
{
    for (i=n-1;i>j;i--)
	{
	  c[i]=c[i]-((a[i][j]/a[i-1][j])*c[i-1]);
	  
	  if(a[i-1][j] != 0 )
	  {
	   for (r=n-1;r>=0;r--)
       {
        a[i][r]=a[i][r]-((a[i][j]/a[i-1][j])*a[i-1][r]);            
       }
      }
  }
}       

printf("\nMatrix:\n");
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
    printf("%f ",a[i][j]);
    printf("\n");
}

printf("\n");
printf("Constants:\n");

for(i=0;i<n;i++) printf("%f \n",c[i]);

float ans[n];

ans[n-1] = c[n-1]/a[n-1][n-1];

for(i=n-2;i>=0;i--)
{
   ans[i] = c[i];
   for(j=n-1;j>i;j--)
   { 
       ans[i] -= a[i][j]*ans[j]; 
   }
   ans[i] = ans[i]/a[i][i];
}

printf("\nAnswer:\n");

for(i=0;i<n;i++) printf("%f ",ans[i]); printf("\n");

return 0;
}
