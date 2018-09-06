#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
float **a,**d,**r,*b,*temp,*rx,*x,*old_x,error; int cnt=0,n,i,j,k;
FILE *fp;
fp = fopen("jacobi_data.txt","w");

printf("Enter number of variables:");
 
scanf("%d",&n);

a = (float**)malloc((n)*(sizeof(float)));
d = (float**)malloc((n)*(sizeof(float)));
r = (float**)malloc((n)*(sizeof(float)));


temp = (float*)malloc((n)*sizeof(float));
rx = (float*)malloc((n)*sizeof(float));
b = (float*)malloc((n)*sizeof(float));
x = (float*)malloc((n)*sizeof(float));
old_x = (float*)malloc((n)*sizeof(float));

for(i=0;i<n;i++) 
{ 
 a[i] = (float*)malloc((n)*sizeof(float)); 
 d[i] = (float*)malloc((n)*sizeof(float));
 r[i] = (float*)malloc((n)*sizeof(float));  
}


//inputing matrix
printf("Enter co efficients: \n");
for(i=0;i<n;i++)
 for(j=0;j<n;j++)
    scanf("%f", &a[i][j]);
    
printf("Enter Constants:\n");
for(i=0;i<n;i++) scanf("%f", &b[i]);

fprintf(fp,"Coeficient Matrix:\n");
for(i=0;i<n;i++)
{ for(j=0;j<n;j++)
    fprintf(fp,"%f ", a[i][j]);
  fprintf(fp,"\n");  
}
fprintf(fp,"\n");   

fprintf(fp,"Constants:\n");
for(i=0;i<n;i++) fprintf(fp,"%f\n",b[i]);
fprintf(fp,"\n");

//making D[][] and R[][]
for(i=0;i<n;i++)
 for(j=0;j<n;j++)
   d[i][j] = 0,r[i][j] = a[i][j];
      
i=0;
while(i <= n-1)
{
d[i][i] = a[i][i];
r[i][i] = 0; 
i++; 
}     

for(i=0;i<n;i++) x[i] = 0,old_x[i] = 0;

while(1)
{

//calculating R*old_X  
for(i=0;i<n;i++)
{  
   rx[i] = 0;
   for(j=0;j<n;j++)
    rx[i] += r[i][j]*old_x[j];
}

//(B - R*old_X)
for(i=0;i<n;i++) 
{
 temp[i] = b[i] - rx[i]; 
}

//X = D^-1(B - R*old_x)
for(i=0;i<n;i++)
{
  x[i] = temp[i]/d[i][i];
  
}

//calculating divergence from last x[]
//error = sum(|x[i] - old_x[i]|)
error = 0;
for(j=0;j<n;j++) error += fabs(x[j] - old_x[j]); 

//printing current x[]
printf("itr=%d\n", cnt+1);
for(i=0;i<n;i++) printf("%f ",x[i]); printf("error=%f", error);
printf("\n--------------\n");

//printing to file
fprintf(fp,"itr=%d\n", cnt+1);
for(i=0;i<n;i++) fprintf(fp,"x[%d]=%f ",i+1,x[i]); 
fprintf(fp,"error=%f\n\n", error);

 
//break if variation in values is very less or number of iterations exceeds 1000
if( (error <= 0.001 && cnt !=0) || cnt>1000) break;

for(i=0;i<n;i++) old_x[i] = x[i];

cnt++;

}

printf("Answer:\n");
for(i=0;i<n;i++) printf("x[%d]=%f\n", i+1, x[i] );

return 0;
}
