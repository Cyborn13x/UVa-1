#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-190
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	int j;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
      double x1;
	double x2;
	double x3;
	double y1;
	double y2;
	double y3;
	double D;
	double g;
	double f;
	double c;
	double r;
	double h;
	double k;
	double pi=3.141592653589793;
	while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
	{
		D=x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1;
		g=(x1*x1+y1*y1)*(y2-y3)-y1*(x2*x2+y2*y2-x3*x3-y3*y3)+y3*(x2*x2+y2*y2)-y2*(x3*x3+y3*y3);
		g*=-1;
		g/=2*D;
		f=(x1*x1+y1*y1)*(x2-x3)-x1*(x2*x2+y2*y2-x3*x3-y3*y3)+x3*(x2*x2+y2*y2)-x2*(x3*x3+y3*y3);
		f/=2*D;
		c=(x1*x1+y1*y1)*(x2*y3-y2*x3)-x1*(y3*(x2*x2+y2*y2)-y2*(x3*x3+y3*y3))+y1*(x3*(x2*x2+y2*y2)-x2*(x3*x3+y3*y3));
		c*=-1;
		c/=D;
		r=sqrt(g*g+f*f-c);
		h=g;
		k=f;
		printf("(x ");
		if(h<0) h*=-1,printf("-");
		else printf("+");
		printf(" %.3lf)^2 + (y ",h);
		if(k<0) k*=-1,printf("-");
		else printf("+");
		printf(" %.3lf)^2 = %.3lf^2\n",k,r);
		printf("x^2 + y^2 ");
		if(g<0) g*=-1,printf("-");
		else printf("+");
		printf(" %.3lfx ",2*g);
		if(f<0) f*=-1,printf("-");
		else printf("+");
		printf(" %.3lfy ",2*f);
		if(c<0) c*=-1,printf("-");
		else printf("+");
		printf(" %.3lf = 0\n\n",c);
	}
	return 0;
}
