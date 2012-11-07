#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-865
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
	int a[300];
	char s[500];
	char s1[500];
	char s2[500];
	scanf("%d",&t);
	getchar();
	getchar();
	x=0;
	while(t--)
	{
	      if(x) printf("\n");
	      x=1;
	      memset(a,0,sizeof(a));
	      gets(s1);
	      gets(s2);
	      l=strlen(s1);
	      for(i=0;i<l;i++) a[s1[i]]=s2[i];
	      printf("%s\n%s\n",s2,s1);
		while(gets(s)!=NULL)
		{
			if(s[0]==0) break;
			l=strlen(s);
			for(i=0;i<l;i++)
			{
				if(a[s[i]]) printf("%c",a[s[i]]);
				else printf("%c",s[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
