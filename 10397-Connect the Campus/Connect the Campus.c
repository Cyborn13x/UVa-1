#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10397
 *
 *language-ANSI C
 *
 */

typedef struct
{
      int u;
      int v;
      double w;
}edge;

int point[1000][2];
int parent[1000];
edge list[300000];

int FindParent(int n)
{
      return (parent[n]==n) ? (n) : (parent[n]=FindParent(parent[n]));
}

int IsUnion(int A,int B)
{
      return FindParent(A)==FindParent(B);
}

void MakeUnion(int A,int B)
{
      parent[FindParent(A)]=FindParent(B);
      return;
}
double Distance(int x1,int y1,int x2,int y2)
{
      return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int cmp(const void* a,const void* b)
{
      return (((edge *)a)->w >= ((edge *)b)->w) ? 1 : -1;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int a;
	int b;
	double cost;
	while(scanf("%d",&n)==1)
	{
	      m=0;

		for(i=1;i<=n;i++)
		{
		      scanf("%d %d",point[i],point[i]+1);
		}
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
			      list[m].u=i;
				list[m].v=j;
				list[m].w=Distance(point[i][0],point[i][1],point[j][0],point[j][1]);
				m++;
			}
		}
		for(i=1;i<=n;i++) parent[i]=i;
		k=0;cost=0;
		scanf("%d",&l);
		while(l--)
		{
			scanf("%d %d",&a,&b);
			if(!IsUnion(a,b))
			{
			      MakeUnion(a,b);
			      k++;
                  }
		}
		qsort(list,m,sizeof(edge),&cmp);
		for(i=0;i<m && k<n-1;i++)
		{
			if(!IsUnion(list[i].u,list[i].v))
			{
			      MakeUnion(list[i].u,list[i].v);
			      cost+=list[i].w;
			      k++;
			}
		}
		printf("%.2lf\n",cost);
	}
	return 0;
}
