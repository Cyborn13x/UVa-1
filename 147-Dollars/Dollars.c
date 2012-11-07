#include <stdio.h>

/*problem id-147
 *
 *language-ANSI C
 *
 */

int main()
{
	register int i,j;
	int n,x;
	double dp[6000+2]={0}, a;
	const int coin[]={1,2,4,10,20,40,100,200,400,1000,2000};
	for(i=0,dp[0]=1;i<11;i++) for(j=x=coin[i];j<6002;j++) dp[j]+=dp[j-x];
	while(scanf("%lf",&a) && a)
	{
		n=(int)(a*20);
		printf("%6.2lf%17.lf\n",a,dp[n]);
	}
	return 0;
}
