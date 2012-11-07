#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10679
 *
 *language-ANSI C
 *
 */

void str_rev(char *a)
{
      int l=strlen(a);
      int j=l/2;
      int i;
      char tmp;
      for(i=0;i<j;i++)
      {
      	tmp=a[l-i-1];
      	a[l-i-1]=a[i];
      	a[i]=tmp;
      }
      return;
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
	char a[1000010];
	char b[10010];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		str_rev(a);
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",b);
			str_rev(b);
			if(strstr(a,b)!=NULL) printf("y\n");
			else printf("n\n");
		}
	}
	return 0;
}
