#include <stdio.h>

/*problem id-1230
 *
 *language-ANSI C
 *
 */

int BigMod(int x,int y,int n)
{
      int res;
      if(!y) return 1;
      if(y&1) return (x*BigMod(x,y-1,n))%n;
      res=BigMod(x,y/2,n);
      return (res*res)%n;
}

int main()
{
	int n,t,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&x,&y,&n);
		printf("%d\n",BigMod(x,y,n));
	}
	scanf("%d",&x);
	return 0;
}
