#include<stdio.h>
#include<math.h>
#define float double 


//f(x)
float f(float x)
{
float y = pow(2.7182818284,-x) - x;
return y;
}

//differentiation of f(x)
float df(float x)
{
float y = -pow(2.7182818284,-x) - 1;
return y;
}

//double differentiation of f(x)
float ddf(float x)
{
float y = pow(2.7182818284,-x);
return y;
}

int main()
{
float x;
FILE *fp;
fp = fopen("chebyshev_data.txt","w");//opening file
printf("Enter x:");
scanf("%lf",&x); //initial value
float new_x;
float e1,e2;
float pre=0.00001; //precision
while(1)
{

//calculating new_x 
new_x = x - f(x)/df(x) - (f(x)*f(x)*ddf(x))/(2*df(x)*df(x)*df(x));
e1 = fabs(new_x - x);
float n = fabs(log(fabs(e1)/fabs(e2))); 

printf("x=%lf f(x)=%lf error=%lf n=%lf\n", new_x,f(x),e1,n);

fprintf(fp,"x=%lf f(x)=%lf error=%lf n=%lf\n", new_x,f(x),e1,n);

//break if f(x) is close enough to 0
if(f(new_x) <= pre && f(new_x) >= -pre) break;
x = new_x;
e2 = e1;
}

return 0;
}
