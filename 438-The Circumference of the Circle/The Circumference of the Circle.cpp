#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

/*problem id-438
 *
 *language-C++
 *
 */

using namespace std;

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
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
	double s;
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
		s=2*pi*r;
		printf("%.2lf\n",s);
	}
	return 0;
}
