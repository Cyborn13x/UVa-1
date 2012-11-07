#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-11608
 *
 *language-ANSI C
 *
 *
 */

int main()
{
	int i;
	int j=0;
	int n;
	int fn;
	int p[13];
	int r[12];
	while(scanf("%d",&p[0])==1 && p[0]>=0)
	{
		for(i=1;i<13;i++)
		{
                  scanf("%d",&p[i]);
		}
		for(i=0;i<12;i++)
		{
			scanf("%d",&r[i]);
		}
		printf("Case %d:\n",++j);
		for(i=0;i<12;i++)
		{
		      fn=p[i];
			if(fn>=r[i])
			{
			      printf("No problem! :D\n");
			      fn-=r[i];
			}
			else printf("No problem. :(\n");
			p[i+1]+=fn;
		}
	}
	return 0;
}
