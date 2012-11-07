#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

#define eps 0.000000001

using namespace std;

int p,q,r,s,t,u;

double f(double x)
{
      return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double fd(double x)
{
      return -p*exp(-x)+q*cos(x)-r*sin(x)+s/(cos(x)*cos(x))+2*t*x;
}

double NewtonsIteration()
{
      double x,x1,a=f(0),b=f(1);
      if((a>0 && b>0) || (a<0 && b<0)) return -1;
      else if(a==0) return 0.0000;
      if(b==0) return 1.0000;
      x=.5;
      for(;;)
      {
            x1=x-f(x)/fd(x);
            if(fabs(x1-x)<eps) return x;
            x=x1;
      }
}

int main()
{
      double x;
	while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)==6)
	{
	      x=NewtonsIteration();
            if(x<0 || x>1) printf("No solution\n");
            else printf("%.4lf\n",NewtonsIteration());
	}
	return 0;
}
