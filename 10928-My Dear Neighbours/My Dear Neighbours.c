#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10928
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
	int ans[1005];
	int otdeg[1005];
	char a[5000];
	char *p;
	scanf("%d",&t);
	while(t--)
	{
	      memset(otdeg,0,sizeof(otdeg));
		scanf("%d\n",&n);
		for(i=1,x=10000;i<=n;i++)
		{
			scanf("%[^\n]%*c",a);
			p=strtok(a," ");
			while(p!=NULL)
			{
				otdeg[i]++;
				p=strtok(NULL," ");
			}
			if(otdeg[i]<x) x=otdeg[i];
		}
		for(i=1,y=0;i<=n;i++) if(otdeg[i]==x) ans[y++]=i;
		printf("%d",ans[0]);
		for(i=1;i<y;i++) printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
