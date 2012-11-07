#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10125
 *
 *language-ANSI C
 *
 */

int cmp(const void *a,const void *b)
{
      return *(int *)a<*(int *)b;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x[1010];
	int y;
	while(scanf("%d",&n) && n)
	{
	      y=1;
		for(i=0;i<n;i++) scanf("%d",&x[i]);
		qsort(x,n,sizeof(int),cmp);
		for(i=0;i<n && y;i++)
		{
			for(j=0;j<n && y;j++)
			{
			      if(j==i) continue;
				for(k=0;k<n && y;k++)
				{
				      if(k==i || k==j) continue;
					for(l=0;l<n && y;l++)
					{
						if(l==k || l==j || l==i) continue;
						y=x[j]+x[k]+x[l]==x[i]?0:1;
					}
				}
			}
		}
		if(!y) printf("%d\n",x[i-1]);
		else printf("no solution\n");
	}
	return 0;
}
