#include <stdio.h>

/*problem id-12372
 *
 *language-ANSI C
 *
 */

int main()
{
	int t,x,y,z,test=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&x,&y,&z);
		printf("Case %d: %s\n",++test,(x>20 || y>20 || z>20) ? "bad" : "good");
	}
	return 0;
}
