#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11733
 *
 *language-ANSI C
 *
 */

typedef struct
{
      int u;
      int v;
      int w;
}edge;

int parent[10002];
edge list[100000];

int FindParent(int n)
{
      return parent[n]==n ? n : (parent[n]=FindParent(parent[n]));
}

void MakeUnion(int A,int B)
{
      parent[FindParent(A)]=FindParent(B);
      return;
}

int cmp(const void *a,const void *b)
{
      return ((edge *)a)->w-((edge *)b)->w;
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
	int x;
	int y;
	int N;
	int M;
	int A;
	int PA;
	int PB;
	int c;
	long long int RoadCost;
	scanf("%d",&t);k=1;
	while(t--)
	{
		scanf("%d %d %d",&N,&M,&A);
		for(i=1;i<=N;i++) parent[i]=i;
		for(i=0;i<M;i++) scanf("%d %d %d",&list[i].u,&list[i].v,&list[i].w);
		qsort(list,M,sizeof(edge),&cmp);
		for(i=l=RoadCost=0;i<M && l<N-1 && list[i].w<A;i++)
		{
			PA=FindParent(list[i].u);
			PB=FindParent(list[i].v);
			if(PA!=PB)
			{
			      l++;RoadCost+=list[i].w;
			      MakeUnion(PA,PB);
			}
		}
		for(i=1,l=0;i<=N;i++)
		{
			RoadCost+=(A*(parent[i]==i));
			l+=(parent[i]==i);
		}
		printf("Case #%d: %lld %d\n",k++,RoadCost,l);
	}
	return 0;
}
