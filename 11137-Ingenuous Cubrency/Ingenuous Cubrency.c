#include <stdio.h>

/*problem id-11137
 *
 *language-ANSI C
 *
 */

int main()
{
	register int i;
	register int j;
	int n;
	int x;
	int y;
	int coin[25];
	double dp[10005]={0};
	for(y=1;y<22;y++) coin[y-1]=y*y*y;
	for(i=0,y--,dp[0]=1;i<y;i++) for(j=x=coin[i];j<10002;j++) dp[j]+=dp[j-x];
	while(scanf("%d",&n)!=EOF) printf("%.lf\n",dp[n]);
	return 0;
}
