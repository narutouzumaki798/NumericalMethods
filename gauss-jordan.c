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
 

/*printf("Enter Constants: \n");
for(i=0;i<n;i++) scanf("%f",&a[i][n]); */


for(j=0;j<n;j++)
{
 
   
   // swap row if diagonal element is 0
   if(a[j][j] == 0)
   {
      //with row that has non-zero element in current column
      for(i=j+1;i<n;i++) 
      { if(a[i][j] != 0)
        {
           for(k=0;k<2*n;k++) swap(&a[i][k],&a[j][k]);
        }
      }
   }
   printf("\n"); 
     
   //divide all elements of jth row by a[j][j] to make a[j][j] 1  
   r = a[j][j];
   for(k=0;k<2*n;k++) a[j][k] /= r;
     
   //make all elements of current column except diagonal
   //element 0  
   for(l=0;l<n;l++)
   {    
        if(l == j) continue;
        r = (a[l][j]/a[j][j]);  
        for(k=0;k<2*n;k++)
        a[l][k] -= r*a[j][k];
   }
   
  //printing the matrix   
  for(i1=0;i1<n;i1++)
  { 
   for(j1=0;j1<2*n;j1++)
   {
    printf("%10f ", a[i1][j1]);
    if(j1 == n-1) printf(" | ");
   }
    printf("\n");
  } 
  
  printf("--------------------------------------------------\n");  

} 

//printing the inverse
printf("\nInverse = \n");
for(i=0;i<n;i++)
{ 
  for(j=n;j<2*n;j++)
  {
    printf("%f ", a[i][j]);
  }
    printf("\n");
}   

return 0;
}
