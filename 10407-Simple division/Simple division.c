#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10407
 *
 *language-ANSI C
 *
 */

int abs(int a)
{
      return a<0 ? -a : a;
}

int gcd(int a,int b)
{
      return b==0 ? a : gcd(b,a%b);
}

int main()
{
	register int i;
	register int j;
	int k;
	int ans;
	int a[1002];
	while(1)
	{
		k=0;
		scanf("%d",&a[k]);
		if(!a[k]) break;
		k++;while(scanf("%d",&a[k]) && a[k]) k++;
		for(i=0,ans=0;i<k;i++) for(j=i+1;j<k;j++) ans=gcd(abs(a[i]-a[j]),ans);
		printf("%d\n",ans);
	}
	return 0;
}
