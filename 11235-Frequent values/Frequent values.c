#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define N 100002
#define N1 2*N
#define SZ 4*N

/*problem id-11235
 *
 *language-ANSI C
 *
 */

int Tree[SZ], num[N], cnt[N1], start[N1], xx[SZ], yy[SZ];

int max(int a,int b) { return a>b ? a : b; }

void BuildSegmentTree(int node,int str,int end)
{
      int left=node<<1, right=left+1, mid=(str+end)>>1;
      xx[node]=str, yy[node]=end;
      if(str==end) { Tree[node]=cnt[num[str]]; return; }
      BuildSegmentTree(left,str,mid);
      BuildSegmentTree(right,mid+1,end);
      Tree[node]=max(Tree[left],Tree[right]);
      return;
}

int QueryTree(int node,int str,int end)
{
      int left=node<<1, right=left+1;
      if(xx[node]>end || yy[node]<str) return -1;
      if(xx[node]>=str && yy[node]<=end) return Tree[node];
      return max(QueryTree(left,str,end),QueryTree(right,str,end));
}

int main()
{
	int i,j,k,l,m,n,q,t,x,y,a,b,blank=0,test=0;
	while(scanf("%d %d",&n,&q) && n)
	{
	      memset(cnt,0,N1*sizeof(int));
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			num[i]+=N, cnt[num[i]]++;
			if(cnt[num[i]]==1) start[num[i]]=i;
		}
		BuildSegmentTree(1,0,n-1);
		for(i=0;i<q;i++)
		{
			scanf("%d %d",&a,&b);
			a--, b--;
			if(num[a]==num[b]) { printf("%d\n",b-a+1); continue; }
			x=(k=start[num[a]]+cnt[num[a]])-a;
			y=b-(l=start[num[b]]-1);
			printf("%d\n",k<=l ? max(max(x,y),QueryTree(1,k,l)) : max(x,y));
		}
	}
	return 0;
}
