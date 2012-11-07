#include <stdio.h>

/*problem id-674
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
	int dp[7500]={0};
	const int coin[]={1,5,10,25,50};
	dp[0]=1;
	for(i=0;i<5;i++) for(j=x=coin[i];j<7500;j++) dp[j]+=dp[j-x];
	while(scanf("%d",&n)!=EOF) printf("%d\n",dp[n]);
	return 0;
}
