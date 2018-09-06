#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
float **a,*x,*old_x,error; int cnt=0,n,i,j,k;
FILE *fp;
fp = fopen("seidel_data.txt","w");

printf("Enter number of variables:");
 
scanf("%d",&n);
printf("Enter co efficients: \n");
a = (float**)malloc((n+1)*(sizeof(float)));
for(i=0;i<=n;i++) a[i] = (float*)malloc((n+1)*sizeof(float)); 

//inputing the matrix
for(i=0;i<n;i++)
 for(j=0;j<n;j++)
    scanf("%f", &a[i][j]);
    
printf("Enter Constants:\n");
for(i=0;i<n;i++) scanf("%f", &a[i][n]);

x = (float*)malloc((n+1)*sizeof(float));
old_x = (float*)malloc((n+1)*sizeof(float));   

fprintf(fp,"Coeficient Matrix:\n");
for(i=0;i<n;i++)
{ for(j=0;j<n;j++)
    fprintf(fp,"%f ", a[i][j]);
  fprintf(fp,"\n");  
}
fprintf(fp,"\n");   

fprintf(fp,"Constants:\n");
for(i=0;i<n;i++) fprintf(fp,"%f\n",a[i][n]);
fprintf(fp,"\n");


//initializing x[] with 0
for(i=0;i<n;i++) x[i] = 0,old_x[i] = 0;

//printf("tttttt\n");

while(1)
{
 //new x[i] = constant[i] - a[i][0]*old_x[0] - a[i][1]*old_x[1] ... 
 //(except a[i][i]*old_x[i])
 for(i=0;i<n;i++)
 {
   x[i] = a[i][n];
   for(j=0;j<n;j++)
   {
      if(j != i) x[i] -= a[i][j]*old_x[j];
   }  
   x[i] = x[i]/a[i][i];
 }
 
 //printing current x[]
 printf("itr=%d\n", cnt+1);
 for(k=0;k<n;k++) printf("%f ",x[k]);
 printf("\n--------------\n");
 
 //error = sum(|x[i] - old_x[i]|)
 error = 0;
 for(j=0;j<n;j++) error += fabs(x[j] - old_x[j]); 
 
 //printing to file
 fprintf(fp,"itr=%d\n", cnt+1);
 for(i=0;i<n;i++) fprintf(fp,"x[%d]=%f ",i+1,x[i]); 
 fprintf(fp,"error=%f\n\n", error);
 
 //break if variation in values is less or number of iterations exceeds 1000
 if(error <= 0.001 || cnt > 1000) break;
 
 for(j=0;j<n;j++) old_x[j] = x[j];
 cnt++;

}

printf("Answer:\n");
for(i=0;i<n;i++) printf("x[%d]=%f\n", i+1, x[i] );


return 0;
}
