#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

double x[4];
double y[4];

double X1;
double X2;
double X3;
double Y1;
double Y2;
double Y3;

int fn()
{
      int f=0;
      int i;
      int j;
      int xi;
      int yi;
      for(i=0;i<4;i++)
      {
      	for(j=i+1;j<4;j++)
      	{
      		if(x[i]==x[j] && y[i]==y[j])
      		{
      		      f=1;
      		      xi=i;
      		      yi=j;
      		      X2=x[i];
      		      Y2=y[i];
      		}
      		if(f)
      		{
      		      break;
      		}
      	}
      	if(f)
      	{
      	      break;
      	}
      }
      for(i=0;i<4;i++)
      {
      	if(i!=xi && i!=yi)
      	{
      	      X1=x[i];
      	      Y1=y[i];
      	      break;
      	}
      }
      for(i=3;i>=0;i--)
      {
      	if(i!=xi && i!=yi)
      	{
      	      X3=x[i];
      	      Y3=y[i];
      	      break;
      	}
      }
      return;
}

int main()
{
      int i;
      int j;
      int n;
      while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3])==8)
      {
            fn();
            printf("%.3lf %.3lf\n",X1+X3-X2,Y1+Y3-Y2);
      }
      return 0;
}
