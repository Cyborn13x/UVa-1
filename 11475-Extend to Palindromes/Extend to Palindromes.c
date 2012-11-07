#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-11475
 *
 *language-ANSI C
 *
 */

char a[100005];
char b[100005];

void Str_rev(char *p)
{
      int i;
      int l=strlen(p);
      char t;
      for(i=0;i<l/2;i++)
      {
      	t=p[i];
      	p[i]=p[l-i-1];
      	p[l-i-1]=t;
      }
      return;
}

int Palindrom(char *p,int l)
{
      int i;
      for(i=0;i<l/2;i++) if(p[i]!=p[l-i-1]) return 0;
      return 1;
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
	int x;
	int y;
	while(scanf("%s",a)!=EOF)
	{
		l=strlen(a);
		for(i=0;i<l;i++)
		{
			if(Palindrom(a+i,l-i)) break;
			b[i]=a[i];
		}
		b[i]=0; Str_rev(b);
		printf("%s%s\n",a,b);
	}
	return 0;
}
