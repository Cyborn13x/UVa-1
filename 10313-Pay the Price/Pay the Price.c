#include <stdio.h>

/*problem id-10313
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,N,L1,L2;
	unsigned long long dp[302][302]={0},data[302][302]={0};
	char a[30];
	for(i=dp[0][0]=1;i<301;i++) for(j=i;j<301;j++) for(k=1;k<301;k++) dp[j][k]+=dp[j-i][k-1];
	for(i=0;i<301;i++) data[0][i]=dp[0][i];
	for(i=0;i<301;i++) for(j=1;j<301;j++) data[i][j]=data[i][j-1]+dp[i][j];
	while(gets(a))
	{
		l=sscanf(a,"%d %d %d",&N,&L1,&L2);
		if(l==1) printf("%llu\n",data[N][N]);
		else if(l==2) printf("%llu\n",data[N][N<L1?N:L1]);
		else if(L1<=N) printf("%llu\n",data[N][N<L2?N:L2]-data[N][L1]+dp[N][L1]);
		else printf("0\n");
	}
	return 0;
}
