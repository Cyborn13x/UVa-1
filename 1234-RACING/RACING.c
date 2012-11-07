#include <stdio.h>
#include <stdlib.h>

/*problem id-1234
 *
 *language-ANSI C
 *
 */

typedef struct
{
      int u,v,w;
}edge;

int parent[10002];
edge list[100002];

int FindParent(int n) { return parent[n]==n ? n : (parent[n]=FindParent(parent[n])); }

int IsUnion(int a,int b) { return FindParent(a)==FindParent(b); }

void MakeUnion(int a,int b) { parent[FindParent(a)]=FindParent(b); }

int cmp(const void *a,const void *b) { return (*(edge*)b).w-(*(edge*)a).w; }

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++) parent[i]=i;
		for(i=0;i<m;i++) scanf("%d %d %d",&list[i].u,&list[i].v,&list[i].w);
		qsort(list,m,sizeof(edge),&cmp);
		for(i=ans=0;i<m;i++)
		{
			if(!IsUnion(list[i].u,list[i].v)) MakeUnion(list[i].u,list[i].v);
			else ans+=list[i].w;
		}
		printf("%d\n",ans);
	}
	scanf("%d",&x);
	return 0;
}
