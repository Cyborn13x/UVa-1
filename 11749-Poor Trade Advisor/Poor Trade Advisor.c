#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>

/*problem id-11749
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

int parent[502];
int rank[502];
edge list[1000002];

int FindParent(int n)
{
      return parent[n]==n ? n : (parent[n]=FindParent(parent[n]));
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

int cmp(const void *a,const void *b)
{
      return ((edge *)b)->w>((edge *)a)->w ? 1 : -1;
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
	int PPA;
	int maxans;
	int maxppa;
	edge tmp;
	while(scanf("%d %d",&n,&m) && (n || m))
	{
	      for(i=1;i<=n;i++) parent[i]=i;
	      memset(rank,0,sizeof(rank));
	      maxppa=maxans=LONG_MIN;
		for(i=0;i<m;i++) scanf("%d %d %d",&list[i].u,&list[i].v,&list[i].w);
		qsort(list,m,sizeof(edge),&cmp);
		for(i=0,maxppa=list[0].w;i<m && list[i].w==maxppa;i++) if(!IsUnion(list[i].u,list[i].v)) MakeUnion(list[i].u,list[i].v);
		for(i=1;i<=n;i++) rank[FindParent(i)]++;
		for(i=1;i<=n;i++) maxans = rank[i]>maxans ? rank[i] : maxans;
		printf("%d\n",maxans);
	}
	return 0;
}
