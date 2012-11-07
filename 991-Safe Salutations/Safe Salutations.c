#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-991
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
	int y=0;
	int a[11];a[1]=1;
	for(i=2;i<=10;i++) a[i]=a[i-1]*(4*i-2)/(i+1);
	while(scanf("%d",&n)!=EOF)
	{
		if(y) printf("\n");
		y=1; printf("%d\n",a[n]);
	}
	return 0;
}
