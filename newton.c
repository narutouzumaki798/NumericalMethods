#include<stdio.h>
#include<math.h>
#define float double 


//f(x)
float f(float x)
{
float y = pow(2.718,-x) - x;
return y;
}

//differentiation 0f f(x)
float df(float x)
{
float y = -pow(2.718,-x) - 1;
return y;
}


float ddf(float x)
{
float y = pow(2.718,-x);
return y;
}

int main()
{
float x;
FILE *fp;
fp = fopen("newton-raphson_data.txt","w");//opening file
printf("Enter x:");
scanf("%lf",&x); //initial value
float new_x;
float e1,e2;
float pre=0.00001; //precision
while(1)
{

//calculating new_x 
new_x = x - f(x)/df(x);// - (f(x)*f(x)*ddf(x))/(2*df(x)*df(x)*df(x));
e1 = fabs(new_x - x);

printf("x=%lf f(x)=%lf error=%lf n=%lf\n", new_x,f(x),e1,fabs(log(e1)/log(e2)));

fprintf(fp,"x=%lf f(x)=%lf error=%lf n=%lf\n", new_x,f(x),e1,fabs(log(e1)/log(e2)));

//break if f(x) is close enough to 0
if(f(new_x) <= pre && f(new_x) >= -pre) break;
x = new_x;
e2 = e1;
}

return 0;
}
