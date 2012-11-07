#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

#define eps 0.0004

using namespace std;

typedef struct
{
      double x1,x2,y1,y2;
}rect;

int main()
{
	int i,j,k,l,m,n,t,blank,test=0,flag,top=0;
	char c;
	double x,y;
	rect a[30];
	while(cin >> c)
	{
		if(c=='*') break;
		scanf("%lf %lf %lf %lf\n",&a[top].x1,&a[top].y1,&a[top].x2,&a[top].y2);
		top++;
	}
	while(1)
	{
	      cin >> x >> y ;
	      test++;
	      if(x==9999.9 && y==9999.9) break;
		for(i=flag=0;i<top;i++)
		{
			if(x > a[i].x1 && x < a[i].x2 && y < a[i].y1 && y > a[i].y2)
			{
			      printf("Point %d is contained in figure %d\n",test,i+1);
			      flag=1;
			}
		}
		if(!flag) printf("Point %d is not contained in any figure\n",test);
	}
	return 0;
}
