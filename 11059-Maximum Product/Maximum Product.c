#include <stdio.h>

/*problem id-11059
 *
 *language-ANSI C
 *
 */

int main()
{
	register int i;
	register int j;
	register int k;
	register long long int m;
	register long long int t;
	int n;
	long long int a[20]; k=1;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		for(i=m=0;i<n;i++)
		{
			t=a[i];
			m = t>m ? t : m;
			for(j=i+1;j<n;j++)
			{
				t*=a[j];
				m = t>m ? t : m;
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n",k++,m);
	}
	return 0;
}
