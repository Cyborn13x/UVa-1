#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-913
 *
 *language-ANSI C
 *
 */

int main()
{
      int i;
	int n;
	long long ans;
	long long res;
	while(scanf("%d",&n)!=EOF)
	{
	      n/=2;
	      ans=1;
	      res=6;
		for(i=0;i<n;i++)
            {
			ans+=res;
			res+=4;
		}
		printf("%lld\n",ans+ans-2+ans-4);
	}
	return 0;
}
