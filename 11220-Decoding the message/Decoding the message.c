#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11220
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
	int f=0;
	char s[1000];
	char a[35][35];
	char *p;
	scanf("%d",&t);
	getchar();
	getchar();
	for(i=0;i<t;i++)
	{
	      if(f) putchar('\n');
	      printf("Case #%d:\n",i+1);f=1;
		while(gets(s)!=NULL && s[0])
		{
			p=strtok(s," ");j=l=0;
			memset(a,0,sizeof(a));
			while(p!=NULL) {strcpy(a[j++],p); p=strtok(NULL," ");}
			for(k=0;k<j;k++) if(a[k][l]) putchar(a[k][l++]);
			putchar('\n');
		}
	}
	return 0;
}
