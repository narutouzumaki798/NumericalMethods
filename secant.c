#include<stdio.h>
#include<math.h>
#define float double

float f(float x)
{
   float y = pow(2.718,-x) - x;
   return y;
}

int main()
{
int i=0;
FILE* fp;
fp = fopen("secant_data.txt","w");
float a,b,c,e1=0,e2=0;
printf("Enter a,b:\n");
scanf("%lf",&a); scanf("%lf",&b);

while(1)
{

c = (a*f(b) - b*f(a))/(f(b) - f(a));
a = b;
b = c;
e1 = b-a;
if(i != 0)
{
 printf("itr=%d a=%lf b=%lf c=%lf f(c)=%lf error=%lf \n",i,a,b,c,f(c),fabs(e1/e2) );
 fprintf(fp,"itr=%d a=%lf b=%lf c=%lf f(c)=%lf error=%lf \n",i,a,b,c,f(c),fabs(e1/e2));
}
if(fabs(b-a) <= 0.00001 ) break;
e2 = e1;
if(i > 1000) break;
i++;
}



return 0;
}
