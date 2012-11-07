#include <stdio.h>

int main()
{
	register int i;
	int m;
	int n;
	register int t;
	register int x;
	register int y; t=0;
	while(scanf("%d",&n) && n)
	{
		for(i=x=y=0;i<n;i++)
		{
			scanf("%d",&m);
			m ? x++ : y++;
		}
		printf("Case %d: %d\n",++t,x-y);
	}
	return 0;
}
