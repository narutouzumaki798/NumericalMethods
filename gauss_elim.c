#include<stdio.h>

// function to swap values in two variables
void swap(float *a,float *b)
{
   float temp = *a;
   *a = *b;
   *b = temp;
}

int main()
{
 
printf("Enter number of variables:");
int n; scanf("%d",&n);
printf("Enter co efficients: \n");
int i,j,k,l,i1,j1;
float a[n][2*n],r; float c[n];

for(i=0;i<n;i++)
 for(j=0;j<2*n;j++)
    a[i][j] = 0;

for(i=0;i<n;i++)
 for(j=0;j<n;j++)
    scanf("%f",&a[i][j]);

i = 0; j = n;

while(i <= n-1)
{
  a[i][j] = 1;
  i++; j++;
}
 

printf("Enter Constants: \n");
for(i=0;i<n;i++) scanf("%f",&a[i][n]); 

for(j=0;j<n;j++)
{
 
   
   // swap if element is 0
   if(a[j][j] == 0)
   {
      for(i=j+1;i<n;i++)
      { if(a[i][j] != 0)
        {
           for(k=0;k<=n;k++) swap(&a[i][k],&a[j][k]);
        }
      }
   }
  
     
   //r = a[j][j];
   //for(k=0;k<2*n;k++) a[j][k] /= r;
     
   
   for(l=j;l<n;l++)
   {    
        if(l == j) continue;
        r = (a[l][j]/a[j][j]);  
        for(k=0;k<=n;k++)
        a[l][k] -= r*a[j][k];
   }
   
 /* for(i1=0;i1<n;i1++)
  { 
  for(j1=0;j1<2*n;j1++)
  {
    printf("%f ", a[i1][j1]);
  }
    printf("\n");
  } 
  
  printf("----------------------------\n");  */

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

for(i=0;i<n;i++) printf("%f \n",a[i][n]);

float ans[n];

ans[n-1] = a[n-1][n]/a[n-1][n-1];

for(i=n-2;i>=0;i--)
{
   ans[i] = a[i][n];
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
