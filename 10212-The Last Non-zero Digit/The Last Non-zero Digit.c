#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10212
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,N,M,ans;
	while(scanf("%d %d",&N,&M)!=EOF)
	{
		ans=1;x=y=0;
		for(i=N;i>N-M;i--)
		{
			n=i;
			while(!(n&1)) {x++;n>>=1;}
			while(!(n%5)) {y++;n/=5;}
			ans=(ans*n)%10;
		}
		for(i=x;i<y;i++) ans=(ans*5)%10;
		for(i=y;i<x;i++) ans=(ans*2)%10;
		printf("%d\n",ans%10);
	}
	return 0;
}
