#include <stdio.h>
#include <math.h>
#define float double
float fun(float x)
{
float y = pow(2.718,-x)-x;
return y;
}



int main()
{
float a,b;
FILE* fp;
//opening file
fp = fopen("false_position_data.txt", "w");
printf("Enter a,b:\n");
scanf("%lf",&a);
scanf("%lf",&b);
int itr = 0; //iteration number
float c,old_c = 1000,ya,yb;
float pre = 0.00001; // precision 
while(1)
{
ya = fun(a);
yb = fun(b);
c = b + ((a-b)*yb)/(yb - ya); //calclating new value of c

if(fun(c)*fun(a) < 0)
b = c;
else a = c;

//error calculation
float err = fabs(((c-old_c)*100)/c);



if(itr == 0)
fprintf(fp,"itr=%d a=%lf b=%lf c=%lf fun(c)=%lf err=0\n",itr,a,b,c,fun(c));
else
fprintf(fp,"itr=%d a=%lf b=%lf c=%lf fun(c)=%lf err=%lf\n",itr,a,b,c,fun(c),err);

if(itr == 0)
printf("itr=%d a=%lf b=%lf c=%lf fun(c)=%lf err=0\n",itr,a,b,c,fun(c));
else
printf("itr=%d a=%lf b=%lf c=%lf fun(c)=%lf err=%lf\n",itr,a,b,c,fun(c),err);

//break if fun(c) is close enough to 0
if(fun(c) <= pre && fun(c) >= -pre) break;
itr++;
old_c = c;
}



return 0;
}
