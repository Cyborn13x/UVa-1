#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10842
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

int parent[102];
edge list[10005];

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
      return (((edge *)b)->w >= ((edge *)a)->w) ? 1 : -1;
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
	int MinMax;
      scanf("%d",&t);x=1;
      while(t--)
      {
      	scanf("%d %d",&n,&m);MinMax=20000000;
      	for(i=0;i<n;i++) parent[i]=i;
      	for(i=0;i<m;i++) scanf("%d %d %d",&list[i].u,&list[i].v,&list[i].w);
      	qsort(list,m,sizeof(edge),&cmp);
      	for(i=k=0;i<m && k<n-1;i++)
      	{
      		if(!IsUnion(list[i].u,list[i].v))
      		{
      		      MakeUnion(list[i].u,list[i].v);
      		      k++;
      		      if(list[i].w<MinMax) MinMax=list[i].w;
      		}
      	}
      	printf("Case #%d: %d\n",x++,MinMax);
      }
	return 0;
}
