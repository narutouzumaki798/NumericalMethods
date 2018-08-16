#include<stdio.h>
#include<math.h>
#define float double

float f(float x)
{
   float y = pow(2.7182818284,-x) - x;
   return y;
}

int main()
{
int i=0;
FILE* fp;
fp = fopen("secant_data.txt","w");
float a,n,b,c,e1=0,e2=0;
printf("Enter a,b:\n");
scanf("%lf",&a); scanf("%lf",&b); //initial range

while(1)
{

c = (a*f(b) - b*f(a))/(f(b) - f(a)); //calculating value of c
a = b;
b = c;
e1 = b-a;
n = fabs(log(fabs(e1))/log(fabs(e2)));
if(i != 0)
{
 printf("itr=%d a=%lf b=%lf c=%lf f(c)=%lf error=%lf order of convergence=%lf \n",i,a,b,c,f(c),fabs(e1/e2),n );
 fprintf(fp,"itr=%d a=%lf b=%lf c=%lf f(c)=%lf error=%lf order of convergence=%lf \n",i,a,b,c,f(c),fabs(e1/e2),n );
}
if(fabs(b-a) <= 0.00001 ) break;
e2 = e1;
if(i > 1000) break; //break after large number of iterations
i++;
}



return 0;
}
