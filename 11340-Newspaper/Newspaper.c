#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11340
 *
 *language-ANSI C
 *
 */

int main()
{
	int m;
	int t;
	int n;
	int a[500];
	char c;
	scanf("%d\n",&t);
	while(t-- && scanf("%d\n",&m)==1)
	{
		memset(a,0,sizeof(a));
		while(m-- && scanf("%c %d\n",&c,&n)==2) a[c+150]=n;
		scanf("%d\n",&m);
		while(m--) while((c=getchar())!='\n') a[480]+=a[c+150];
		printf("%d.%02d$\n",a[480]/100,a[480]%100);
	}
	return 0;
}
