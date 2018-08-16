#include<stdio.h>
#include<math.h>

double fun(double x)
{
    double ans = pow(2.718,-x) - x;
    return ans;
}

int main()
{
double a,b;

while(1)
{
printf("Enter a:");
scanf("%lf",&a);
printf("Enter b:");
scanf("%lf",&b);
if(a<b && fun(a)*fun(b)<0) break;
else printf("Invalid a,b\n\n");

}

FILE *fp1;
fp1 = fopen("bisection_data.txt","w");
double l=a,r=b,m;


double pre=0,curr=0;
int itr = 1;

//infinte bisection loop
while(1)
{
   m = (l+r)/2.0;
   if(fun(m)*fun(a)<0)
   r = m; // if f(m) and f(a) on opposite sides of x axis then root is on left side
   else l = m;
   if( r - l <= 0.000001 ) break; // break if range is small 
   curr = m; 
   
   double err = fabs(curr-pre)/fabs(curr)*100.0; //error calculation
   
   printf("iteration=%d ",itr); 
   printf("a=%lf b=%lf ",l,r);
   printf("x=%lf fun(x)=%lf ", m,fun(m));
   printf("f(x)*f(a)=%lf ", fun(m)*fun(a));
   printf("error=%lf\n",err);
   
   fprintf(fp1,"iteration=%d ",itr); 
   fprintf(fp1,"a=%lf b=%lf ",l,r);
   fprintf(fp1,"x=%lf fun(x)=%lf ", m,fun(m));
   fprintf(fp1,"f(x)*f(a)=%lf ", fun(m)*fun(a));
   fprintf(fp1,"error=%lf\n",err);
   
   pre = m;   
   itr++; //iteration number
}



return 0;
}
