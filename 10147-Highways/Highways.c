#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10147
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

int x[1000];
int y[1000];
int parent[1000];
edge list[300000];

int FindParent(int n)
{
      return (parent[n]==n) ? n : (parent[n]=FindParent(parent[n]));
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

int cmp(const void *a,const void *b)
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
	int A;
	int B;
	double cost;
	scanf("%d",&t);
	while(t--)
	{
	      scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
		for(i=1,m=0;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
			      list[m].u=i;
				list[m].v=j;
				list[m].w=Distance(x[i],y[i],x[j],y[j]);
				m++;
			}
		}
		k=0;cost=0;
		for(i=1;i<=n;i++) parent[i]=i;
		scanf("%d",&l);
		while(l--)
		{
			scanf("%d %d",&A,&B);
			if(!IsUnion(A,B))
			{
			      MakeUnion(A,B);
			      k++;
                  }
		}
		if(k==n-1) printf("No new highways need\n");
		qsort(list,m,sizeof(edge),&cmp);
		for(i=0;i<m && k<n-1;i++)
		{
			if(!IsUnion(list[i].u,list[i].v))
			{
			      printf("%d %d\n",list[i].u,list[i].v);
			      MakeUnion(list[i].u,list[i].v);
			      k++;
			}
		}
		if(t) printf("\n");
	}
	return 0;
}
