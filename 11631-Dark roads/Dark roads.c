#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11631
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

int parent[200000];
int used[200000];
edge list[200000];

int FindParent(int n)
{
      return parent[n]==n ? n : (parent[n]=FindParent(parent[n]));
}

void MakeUnion(int A,int B)
{
      parent[FindParent(A)]=FindParent(B);
      return;
}

int IsUnion(int A,int B)
{
      return FindParent(A)==FindParent(B);
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
	int save;
	while(scanf("%d %d",&n,&m) && (n || m))
	{
	      memset(used,0,sizeof(used));
		for(i=0;i<n;i++) parent[i]=i;
		for(i=0;i<m;i++) scanf("%d %d %d",&list[i].u,&list[i].v,&list[i].w);
		qsort(list,m,sizeof(edge),&cmp);
		for(i=k=0;i<m && k<n-1;i++)
		{
			if(!IsUnion(list[i].u,list[i].v))
			{
			      MakeUnion(list[i].u,list[i].v);
			      used[i]=1;k++;
			}
		}
		for(i=save=0;i<m;i++) if(!used[i]) save+=list[i].w;
		printf("%d\n",save);
	}
	return 0;
}
