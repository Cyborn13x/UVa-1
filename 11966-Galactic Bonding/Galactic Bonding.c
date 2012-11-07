#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-11966
 *
 *language-ANSI C
 *
 */

typedef struct
{
      double x;
      double y;
}point;

int N;
int parent[1002];

int FindParent(int n)
{
      return parent[n]==n ? n : (parent[n]=FindParent(parent[n]));
}

void MakeUnion(int A,int B)
{
      parent[FindParent(A)]=FindParent(B);
      return;
}

double Distance(point a,point b)
{
      return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main()
{
	register int i;
	register int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
	int test=0;
	double d;
	double dist;
	point a[1002];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %lf",&N,&dist);
		dist*=dist;
		for(i=0;i<N;i++)
		{
			scanf("%lf %lf",&a[i].x,&a[i].y);
			for(j=0,parent[i]=i;j<i;j++) if(Distance(a[i],a[j])<=dist) MakeUnion(i,j);
		}
		for(i=n=0;i<N;i++) n += parent[i]==i;
		printf("Case %d: %d\n",++test,n);

	}
	return 0;
}
