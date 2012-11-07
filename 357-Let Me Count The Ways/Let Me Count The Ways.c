#include <stdio.h>

/*problem id-357
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
	const int coin[]={1,5,10,25,50};
	long long int dp[30002]={0};
	dp[0]=1LL;
	for(i=0;i<5;i++) for(j=x=coin[i];j<30002;j++) dp[j]+=dp[j-x];
	while(scanf("%d",&n)!=EOF)
	{
		if(dp[n]==1) printf("There is only 1 way to produce %d cents change.\n",n);
		else printf("There are %lld ways to produce %d cents change.\n",dp[n],n);
	}
	return 0;
}
