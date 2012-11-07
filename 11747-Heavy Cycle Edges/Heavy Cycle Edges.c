#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11747
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

int parent[1002];
int used[25000];
edge list[25000];

int FindParent(int n)
{
      return parent[n]==n ? n : (parent[n]=FindParent(parent[n]));
}

void MakeUnion(int A,int B)
{
      parent[FindParent(B)]=FindParent(A);
      return;
}

int cmp(const void *a,const void *b)
{
      return ((edge*)a)->w-((edge*)b)->w;
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
	int A;
	int B;
	while(scanf("%d %d",&n,&m) && (n || m))
	{
	      memset(used,0,sizeof(used));
		for(i=0;i<n;i++) parent[i]=i;
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&list[i].u,&list[i].v,&list[i].w);
		}
		qsort(list,m,sizeof(edge),&cmp);
		for(i=0,t=0;i<m && t<n-1;i++)
		{
			A=FindParent(list[i].u);
			B=FindParent(list[i].v);
			if(A!=B)
			{
			      used[i]=1;
			      MakeUnion(A,B);
			}
		}
		for(i=0;i<m;i++) if(!used[i]) {t=1;break;}
		if(!t) printf("forest");
		else
		{
		      printf("%d",list[i].w);
		      for(i=i+1;i<m;i++) if(!used[i]) printf(" %d",list[i].w);
		}
		printf("\n");
	}
	return 0;
}
