#include <stdio.h>

/*problem id-12149
 *
 *language-ANSI C
 *
 */

int main()
{
      int i;
	int n;
	long long int ans;
	while(scanf("%d",&n) && n)
	{
		for(i=1,ans=0;i<=n;i++) ans+=i*i;
		printf("%lld\n",ans);
	}

	return 0;
}
