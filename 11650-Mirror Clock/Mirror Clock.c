#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11650
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
	int hh;
	int mm;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d:%d",&x,&y);
		t=x*60+y;
		if(t>720) t-=720;
		t=720-t;
		hh=t/60;
		mm=t%60;
		if(!hh) hh=12;
		if(hh<10) printf("0%d",hh);
		else printf("%d",hh);
		printf(":");
		if(mm<10) printf("0%d",mm);
		else printf("%d",mm);
		printf("\n");
	}
	return 0;
}
