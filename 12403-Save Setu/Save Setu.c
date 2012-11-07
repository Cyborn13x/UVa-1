#include <stdio.h>

/*problem id-12403
 *
 *language-ANSI C
 *
 */

int main()
{
	int t,x=0,y,blank;
	char a[10];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		if(a[0]=='d') { scanf("%d",&y); x+=y; }
		else printf("%d\n",x);
	}
	return 0;
}
