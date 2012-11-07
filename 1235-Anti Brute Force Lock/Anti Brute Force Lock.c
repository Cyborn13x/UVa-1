#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define CLEAR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define FORI(x,y,n) for(x=(y);x<=(n);x++)
#define FOR(x,n) for(x=0;x<(n);x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define llu unsigned long long int
#define ll long long int
#define INF (1<<28)
#define SZ 502

/*problem id-1235
 *
 *language-ANSI C
 *
 */

typedef struct
{
      int u,v,w;
}edge;

edge list[SZ*SZ/2];
int parent[SZ];
char lock[SZ][5],zero[]="0000";

int FindParent(int n) { return parent[n]==n ? n : (parent[n]=FindParent(parent[n])); }

int IsUnion(int a,int b) { return FindParent(a)==FindParent(b); }

void MakeUnion(int a,int b) { parent[FindParent(a)]=FindParent(b); }

int Distance(char *a,char *b)
{
      int i,ret=0;
      FOR(i,4) ret+=min((a[i]-b[i]+10)%10,(b[i]-a[i]+10)%10);
      return ret;
}

int cmp(const void *a,const void *b)
{
      return ((edge *)a)->w-((edge *)b)->w;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,cnt,mst;
	edge tmp;
	scanf("%d",&t);
	while(t--)
	{
	      mst=INF, cnt=0, k=0;
		scanf("%d",&n);
		FOR(i,n) parent[i]=i;
		FOR(i,n) scanf("%s",lock[i]);
		FOR(i,n) mst=min(mst,Distance(zero,lock[i]));
		FOR(i,n)
		{
			for(j=i+1;j<n;j++)
			{
				tmp.u=i, tmp.v=j, tmp.w=Distance(lock[i],lock[j]);
				list[cnt++]=tmp;
			}
		}
		qsort(list,cnt,sizeof(edge),&cmp);
		for(i=0;i<cnt && k<n-1;i++)
		{
		      x=list[i].u, y=list[i].v;
			if(!IsUnion(x,y))
			{
			      k++, mst+=list[i].w;
			      MakeUnion(x,y);
			}
		}
		printf("%d\n",mst);
	}
	return 0;
}
