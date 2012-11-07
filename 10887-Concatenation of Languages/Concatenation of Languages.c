#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problemid-10887
 *
 *language-ANSI C
 *
 */

char a[1506][20],data[1520*1520][50],b[20];

int cmp(const void *a,const void *b)
{
      return strcmp((char *)a,(char *)b);
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		gets(b);
		for(i=0;i<m;i++) gets(a[i]);
		for(i=x=0;i<n;i++)
		{
			gets(b);
			for(j=0;j<m;j++)
			{
				strcpy(data[x],a[j]);
				strcat(data[x++],b);
			}
		}printf("Case %d: ",++test);
		if(!m || !n)
		{
		      printf("0\n");
		      continue;
		}
		qsort(data,x,sizeof(data[0]),&cmp);
		for(i=1,y=1;i<x;i++) if(strcmp(data[i-1],data[i])) y++;
		printf("%d\n",y);
	}
	return 0;
}
