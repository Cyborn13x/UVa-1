#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-1208
 *
 *language-ANSI C
 *
 */

typedef struct
{
      int u,v,w;
}edge;

int parent[30];
edge list[350];

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

int cmp(const void *p1,const void *p2)
{
      edge *a=(edge *)p1,*b=(edge *)p2;
      if(a->w!=b->w) return a->w-b->w;
      if(a->u!=b->u) return a->u-b->u;
      return a->v-b->v;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	scanf("%d",&t);
	while(t--)
	{
	      scanf("%d",&n);
	      for(i=m=0;i<n;i++) parent[i]=i;
		for(i=0;i<n;i++)
		{
		      for(j=0;j<n;j++)
		      {
		      	scanf("%d%*c",&x);
		      	if(x && j>i)
				{
				      list[m].u=i;
				      list[m].v=j;
				      list[m++].w=x;
				}
		      }
		}
		qsort(list,m,sizeof(edge),&cmp);
		printf("Case %d:\n",++test);
		for(i=k=0;i<m && k<n-1;i++)
		{
			if(!IsUnion(list[i].u,list[i].v))
			{
			      k++;
			      printf("%c-%c %d\n",list[i].u+'A',list[i].v+'A',list[i].w);
			      MakeUnion(list[i].u,list[i].v);
			}
		}
	}
	return 0;
}
