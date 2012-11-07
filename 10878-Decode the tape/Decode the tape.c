#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10878
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
	char c;
	char s[20];
	while(gets(s)!=NULL)
	{
	      if(s[0]!='|') continue;
	      k=0;
		for(i=strlen(s)-2,j=0;i>0;i--)
		{
			if(s[i]==' ' || s[i]=='o')
			{
			      if(s[i]=='o')k+=pow(2,j);
			      j++;
			}
		}
		printf("%c",k);
	}
	return 0;
}
