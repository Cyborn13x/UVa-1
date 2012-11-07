#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10019
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
	int b1;
	int b2;
	int tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		b1=b2=x=0;y=1;
		tmp=n;
		while(tmp)
		{
			b1+=tmp%2;
			tmp/=2;
		}
		tmp=n;
		while(tmp)
		{
			x+=(y*(tmp%10));
			tmp/=10;
			y*=16;
		}
		while(x)
		{
			b2+=x%2;
			x/=2;
		}
		printf("%d %d\n",b1,b2);
	}
	return 0;
}
