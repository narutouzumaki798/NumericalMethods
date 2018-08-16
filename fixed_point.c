#include<stdio.h>
#include<math.h>
#define float double

float f(float x)
{
   float y = pow(2.718,-x) - x;
   return y;
}

float g(float x)
{

 float y = pow(2.718,-x);
 return y;
}

int main()
{
int i=0;
float x0,x1,e0,e1;
FILE* fp;
fp = fopen("fixedpoint_data.txt","w");
printf("Enter x:\n");
scanf("%lf", x1);

while(1)
{

 x0 = g(x1);
 e0 = x0 - x1;
 
 if(i != 0)
 {
  printf("itr=%d x=%lf f(x)=%lf err=%lf \n", i,x0,f(x0), fabs(e0/e1) );
  fprintf(fp,"itr=%d x=%lf f(x)=%lf err=%lf \n", i,x0,f(x0), fabs(e0/e1) );
 }
  
 if(fabs(x1-x0) < 0.00001) break;
 if(i > 1000) break;
 
 x1 = x0;
 e1 = e0;
 i++;
}




return 0;
}
