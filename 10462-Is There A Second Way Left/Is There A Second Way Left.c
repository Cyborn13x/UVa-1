#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define INFINITY 20000000

/*problem id-10462
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

int parent[101];
int used[202];
edge list[202];

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
	int x;
	int y;
	int cost;
	int FirstMST;
	int SecondMST;x=1;
      scanf("%d",&t);
      while(t--)
      {
            memset(used,0,sizeof(used));
      	scanf("%d %d",&n,&m);
      	for(i=1;i<=n;i++) parent[i]=i;
      	for(i=0;i<m;i++) scanf("%d %d %d",&list[i].u,&list[i].v,&list[i].w);
      	qsort(list,m,sizeof(edge),&cmp);
      	for(i=k=0;i<m && k<n-1;i++)
      	{
      		if(!IsUnion(list[i].u,list[i].v))
      		{
      		      MakeUnion(list[i].u,list[i].v);
      		      k++;used[i]=1;
      		}
      	}
      	printf("Case #%d : ",x++);
      	if(k<n-1) printf("No way\n");
      	else
      	{
      	      for(i=0,SecondMST=INFINITY;i<m;i++)
      	      {
      	      	if(used[i])
      	      	{
      	      	      for(j=1;j<=n;j++) parent[j]=j;
      	      	      for(j=cost=0;j<m;j++)
      	      	      {
      	      	      	if(used[j] && i!=j)
      	      	      	{
      	      	      	      MakeUnion(list[j].u,list[j].v);
      	      	      	      cost+=list[j].w;
      	      	      	}
      	      	      }
      	      	      for(j=y=0;j<m && !y;j++)
      	      	      {
      	      	      	if(!used[j] && !IsUnion(list[j].u,list[j].v))
      	      	      	{
      	      	      	      y=1;MakeUnion(list[j].u,list[j].v);
      	      	      	      cost+=list[j].w;
      	      	      	}
      	      	      }
      	      	      if(cost<SecondMST && y) SecondMST=cost;
      	      	}
      	      }
      	      if(SecondMST!=INFINITY) printf("%d\n",SecondMST);
      	      else printf("No second way\n");
      	}
      }
	return 0;
}
