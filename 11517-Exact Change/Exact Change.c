#include <stdio.h>

#define INF 10000000

/*problem id-11517
 *
 *language-ANSI C
 *
 */

int min(int a,int b) { return a<b ? a : b; }

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
	int dp[10005];
	int coin[102];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(y=0;y<m;y++) scanf("%d",&coin[y]);
		for(i=0;i<10005;i++) dp[i]=INF;
		for(i=dp[0]=0;i<y;i++) for(j=10002,x=coin[i];j>=0;j--) if(dp[j]!=INF && j+x<10005) dp[j+x]=min(dp[j+x],dp[j]+1);
		for(i=n;i<10001;i++) if(dp[i]!=INF) { printf("%d %d\n",i,dp[i]); break; }
	}
	return 0;
}
