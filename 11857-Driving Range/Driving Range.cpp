#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11857
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

int cmp(const void *a,const void *b)
{
      return ((edge*)a)->w-((edge*)b)->w;
}

int parent[1000000];
edge list[1000000];

int FindParent(int n) { return parent[n]==n ? n : (parent[n]=FindParent(parent[n])); }

void MakeUnion(int A,int B) { A<B ? (parent[B]=A) : (parent[A]=B); return; }

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
	int A;
	int B;
	int range;
	edge tmp;
	while(scanf("%d %d",&n,&m) && (n || m))
	{
		for(i=0;i<n;i++) parent[i]=i;
		for(i=0;i<m;i++) scanf("%d %d %d",&list[i].u,&list[i].v,&list[i].w);
		qsort(list,m,sizeof(edge),&cmp);
		for(i=0,k=0;i<m && k<n-1;i++)
		{
		      tmp=list[i];
			A=FindParent(tmp.u);
			B=FindParent(tmp.v);
			if(A!=B) {k++;MakeUnion(A,B);}
			if(k==n-1) {range=tmp.w;break;}
		}
		if(k!=n-1) printf("IMPOSSIBLE\n");
		else printf("%d\n",range);
	}
	return 0;
}
