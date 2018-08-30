#include<stdio.h>
#include<math.h>

int main()
{
int n,i,itr=0; float r,s,dr,ds;
printf("Enter Degree:");
scanf("%d",&n);

FILE* fp;

float a[n+1],b[n+1],c[n+1];

for(i=n;i>=0;i--)
{
   printf("x^%d : ",i);
   scanf("%f", &a[i]);
}

printf("Intitial r,s:\n"); scanf("%f",&r); scanf("%f",&s);

while(1)
{

b[n] = a[n]; b[n-1] = a[n-1] + r*b[n];
for(i=n-2;i>=0;i--)
b[i] = a[i] + r*b[i+1] + s*b[i+2];

c[n] = b[n]; c[n-1] = b[n-1] + r*c[n];
for(i=n-2;i>=0;i--) 
c[i] = b[i] + r*c[i+1] + s*c[i+2];

dr = (b[0]*c[3] - b[1]*c[2])/(c[2]*c[2] - c[1]*c[3]);
ds = (-b[1] - c[2]*dr)/c[3];

r = r + dr; s = s + ds;

printf("itr=%d r=%f s=%f dr=%f ds=%f \n",itr,r,s,dr,ds);
if(fabs(dr) <= 0.001 && fabs(ds) <= 0.001) break;
itr++;

}

printf("\nPolynomial = \n"); 
printf("(x^2 + %fx + %f )",r,s );
printf("(");
for(i=n;i>=2;i--)
{
  printf("%f*x^%d", b[i],i-2);
  if(i != 0) printf(" + ");
}
printf(")");
printf("\n \n");


return 0;
}
