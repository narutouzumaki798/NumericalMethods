#include<stdio.h>
#include<math.h>
#define float double

float f(float x)
{
   float y = pow(2.7182818284,-x) - x;
   return y;
}

float df(float x)
{

 float y = -pow(2.7182818284,-x) - 1;
 return y;
}

int main()
{
int i=0;
float x0,x01,x1,e0,e1;
FILE* fp;
fp = fopen("multipoint_data.txt","w");
printf("Enter x:\n");
scanf("%lf", x1);

while(1)
{

 x01 = x1 - f(x1)/(2*df(x1));
 x0 = x1 - f(x1)/df(x01);
 
 e0 = x0 - x1;
 float n = fabs(log(fabs(e0))/log(fabs(e1)));
 
 if(i != 0)
 {
  printf("itr=%d x=%lf f(x)=%lf err=%lf n=%lf\n", i,x0,f(x0), fabs(e0/e1),n );
  fprintf(fp,"itr=%d x=%lf f(x)=%lf err=%lf n=%lf\n", i,x0,f(x0), fabs(e0/e1),n );
 }
  
 if(fabs(x1-x0) < 0.00001) break;
 if(i > 1000) break;
 
 x1 = x0;
 e1 = e0;
 i++;
}




return 0;
}
