#include <stdio.h>
#include <string.h>

/*problem id-621
 *
 *language-ANSI C
 *
 */

int main()
{
	int l,t;
	char a[10000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		l=strlen(a);
		if(!strcmp(a,"1")||!strcmp(a,"4")||!strcmp(a,"78")) printf("+");
		else if(a[l-1]=='5' && a[l-2]=='3') printf("-");
		else if(a[0]=='9' && a[l-1]=='4') printf("*");
		else if(a[0]=='1' && a[1]=='9' && a[2]=='0') printf("?");
		putchar('\n');
	}
	return 0;
}
