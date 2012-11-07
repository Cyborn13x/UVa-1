#include <stdio.h>

/*problem id-10489
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,b,t,x,y,blank,test=0,a[100],mod,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&b);
		for(i=ans=0;i<b;i++)
		{
			scanf("%d",&k);
			for(j=0,mod=1;j<k;j++) { scanf("%d",&x); mod=(mod*x)%n; }
			ans=(ans+mod)%n;
		}
		printf("%d\n",ans);
	}
	return 0;
}
